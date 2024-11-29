#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEHIDDevice.h>

#define KNOB_A_IO_NUM 6
#define KNOB_B_IO_NUM 7
#define BUTTON_IO_NUM 10

BLECharacteristic *inputCharacteristic;

uint8_t volumeUpReport[] = { 0x01 };    // Volume Up (bit 0 set)
uint8_t volumeDownReport[] = { 0x02 };  // Volume Down (bit 1 set)
uint8_t stopReport[] = { 0x04 };        // Stop (bit 2 set)
uint8_t keyReleaseReport[] = { 0x00 };  // No keys pressed

void button(void *pvParameters);
void knob(void);

class MyCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) {
    Serial.println("connected");
    BLEDescriptor *desc = inputCharacteristic->getDescriptorByUUID(BLEUUID((uint16_t)0x2902));
    uint8_t val[] = { 0x01, 0x00 };
    desc->setValue(val, 2);
  }

  void onDisconnect(BLEServer *pServer) {
    Serial.println("disconnected");
  }
};


void setup() {

  BLEDevice::init("ESP32-HID-Button");
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyCallbacks());

  BLEHIDDevice *hid = new BLEHIDDevice(pServer);
  inputCharacteristic = hid->inputReport(1);  // Use report ID 1

  uint8_t REPORT_MAP[] = {
      USAGE_PAGE(1), 0x0C,  // Usage Page (Consumer Devices)
      USAGE(1), 0x01,       // Usage (Consumer Control)
      COLLECTION(1), 0x01,  // Collection (Application)
        REPORT_ID(1), 0x01,   // Report ID (1)

        USAGE(1), 0xE9,    // Usage Minimum (Volume Up)
        USAGE(1), 0xEA,    // Usage Maximum (Volume Down)
        USAGE(1), 0xCD,    // Usage (Pause)
        LOGICAL_MINIMUM(1), 0x00,  // Logical Minimum (0)
        LOGICAL_MAXIMUM(1), 0x01,  // Logical Maximum (1)
        REPORT_SIZE(1), 0x01,      // Report Size (1)
        REPORT_COUNT(1), 0x03,     // Report Count (2 - Volume Up and Volume Down)
        0x81, 0x02,            // Input (Data, Variable, Absolute)

        REPORT_COUNT(1), 0x05,  // Report Count (5 - Padding)
        0x81, 0x03,         // Input (Constant, Variable, Absolute)
      END_COLLECTION(0)
  };

  hid->pnp(0x02, 0x0810, 0xe501, 0x0106);
  hid->hidInfo(0x00, 0x01);
  hid->reportMap(REPORT_MAP, sizeof(REPORT_MAP));

  hid->startServices();

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();

  pAdvertising->addServiceUUID(hid->hidService()->getUUID());
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  pAdvertising->start();

  BLESecurity *pSecurity = new BLESecurity();
  pSecurity->setAuthenticationMode(ESP_LE_AUTH_BOND);

  Serial.begin(9600);
  pinMode(BUTTON_IO_NUM, INPUT);

  pinMode(KNOB_A_IO_NUM, INPUT_PULLUP);
  pinMode(KNOB_B_IO_NUM, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(KNOB_A_IO_NUM), knob, CHANGE);

  Serial.println("BLE HID Button Ready!");

  xTaskCreate(
    button,    // Function that should be called
    "button",  // Name of the task (for debugging)
    4096,      // Stack size (bytes)
    NULL,      // Parameter to pass
    1,         // Task priority
    NULL       // Task handle
  );
}

void loop() {
  delay(1000);
}

void button(void *pvParameters) {
  bool buttonState = 0;
  bool lastButtonState = 0;
  bool wasStopped = false;           // Flag to track if the button was previously pressed
  unsigned long time_stamp = 0;      // the last time the output pin was toggled
  unsigned long debounceDelay = 10;  // the debounce time; increase if the output flickers
  int press = 0;
  while (1) {
    int reading = digitalRead(BUTTON_IO_NUM);

    if (reading != lastButtonState) {
      time_stamp = millis();
    }

    if ((millis() - time_stamp) > debounceDelay) {
      if (reading != buttonState) {
        buttonState = reading;
        if (buttonState == HIGH) {
          Serial.print("press count:");
          Serial.println(press++);
          inputCharacteristic->setValue((uint8_t *)stopReport, sizeof(stopReport));
          inputCharacteristic->notify();
          inputCharacteristic->setValue((uint8_t *)keyReleaseReport, sizeof(keyReleaseReport));
          inputCharacteristic->notify();
          wasStopped = !wasStopped;
        }
        else {
        }
      }
    }
    lastButtonState = reading;
  }
}

void knob(void) {
  static unsigned long time_stamp = 0;
  static bool lastCLK = 0;

  if (millis() - time_stamp > 5) {
    bool clkValue = digitalRead(KNOB_A_IO_NUM);
    bool dtValue = digitalRead(KNOB_B_IO_NUM);
    if (lastCLK != clkValue) {
      lastCLK = clkValue;
      if (clkValue == dtValue) {
        inputCharacteristic->setValue((uint8_t *)volumeUpReport, sizeof(volumeUpReport));
        inputCharacteristic->notify();

        inputCharacteristic->setValue((uint8_t *)keyReleaseReport, sizeof(keyReleaseReport));
        inputCharacteristic->notify();
      } else {
        inputCharacteristic->setValue((uint8_t *)volumeDownReport, sizeof(volumeDownReport));
        inputCharacteristic->notify();

        inputCharacteristic->setValue((uint8_t *)keyReleaseReport, sizeof(keyReleaseReport));
        inputCharacteristic->notify();
      }
    }

    time_stamp = millis();
  }
}

