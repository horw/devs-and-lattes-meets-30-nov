---
# try also 'default' to start simple
theme: seriph
background: ./img/assembly/wallpaper.png
class: 'text-center'
highlighter: shiki
transition: slide-left
title: BLE Made Easy
mdc: true
---
# BLE Made Easy

## Your First ESP32 Bluetooth Device

---
transition: fade-out
---

# What is Today's Event About?

<v-clicks>

<div>

## Topic:

Programming Microcontrollers

</div>

<div>

## Focus:

How to Build BLE Devices Using ESP32
</div>


</v-clicks>
---
layout: default
---

# What You'll Learn:
<v-clicks>

- 📝 Program a button and a rotary encoder
- 🎨 Set up Bluetooth services
- 🧑‍💻 Use the ESP32 as a Bluetooth audio controller

</v-clicks>

---
layout: center
---

# What code will you create in this workshop?

---
layout: two-cols
---


# Part 1

<v-clicks>

<div>

**ESP32** to Serial(Console)  
<img src='./img/presentation/project/app1.png' width=300px>

</div>


<div>

**Button** to Serial(Console)
<img src='./img/presentation/project/app2.png' width=300px>

</div>


<div>

**Rotary Encoder** to Serial(Console)
<img src='./img/presentation/project/app3.png' width=300px>

</div>

</v-clicks>
::right::


<v-clicks>

# Part 2


<div>

**Button** to **BLE**  
<img src='./img/presentation/project/app4.png' width=300px>

</div>


<div>

**Rotary Encoder** to **BLE**  
<img src='./img/presentation/project/app5.png' width=300px>

</div>


<div>

**HID** with Button and Rotate
<img src='./img/presentation/project/app6.png' width=300px>

</div>

</v-clicks>

---
layout: center
---

# Disclaimer
<br/>

Everything we do in this workshop is done as **self-makers, not affiliated with any company**.
<br/>This PCB is for teaching purposes **only** and has **only** been tested to ensure it works during the workshop.
<br/>All code and related materials are open source and available at https://github.com/horw/devs-and-lattes-meets-30-nov

<v-click>
<img src='./img/presentation/qr-code.png' width=150px>
</v-click>


---
layout: center
---

# Let's meet

---
layout: default
---


<div style="display: flex; justify-content: space-between; text-align: center; margin-top:50px">

  <div style="flex: 1; margin: 10px;">    

# Igor Udot 吴一格
<p>Software developer in Espressif</p>
<img src="./img/igor-avatar.png" width="250px" alt="Igor Udot's avatar"/>
  </div>

<div style="flex: 1; margin: 10px;">

# Kainarx 陈纪昌
<p>Software developer in Espressif</p>
<img src="./img/chen-avatar.jpg" width="250px" alt="Kainarx's avatar"/>
  </div>

  <div style="flex: 1; margin: 10px;">

# Wan Lei 万磊
<p>Software developer in Espressif</p>
<img src="./img/wan-avatar.jpg" width="250px" alt="Wang Lei's avatar"/>
  </div>

</div>


---
layout: center
---

#  Introduction


---
layout: default
---

# What is the CPU, MCU, SOC

Let’s use a human body analogy to understand the differences between a CPU, MCU, and SoC.


<div style="display: flex; justify-content: space-between; text-align: center; margin-top: 50px;">
  <v-clicks>

  <div style="flex: 1; margin: 10px; display: flex; flex-direction: column; align-items: center;">
    <strong>CPU<br/>(Central Processing Unit)</strong>
    <img src='./img/presentation/brain.png' width=150px/>
  </div>

  <div style="flex: 1; margin: 10px; display: flex; flex-direction: column; align-items: center;">
    <strong>MCU<br/>(Microcontroller Unit)</strong>
    <img src='./img/presentation/brainwithconnectons.png' width=150px />
  </div>

  <div style="flex: 1; margin: 10px; display: flex; flex-direction: column; align-items: center;">
    <strong>SoC<br/>(System on Chip)</strong>
    <img src='./img/presentation/braintoorgans.png' width=150px/>
  </div>
  
  </v-clicks>
</div>

<!--
It’s responsible for the car’s power and driving the vehicle forward. It’s essential for operation, but it only provides one function: making the car move. It doesn't control the steering, brakes, or radio.


It not only drives the car (like the engine) but also has the ability to control other basic systems, like the headlights or the windshield wipers. It can handle simple tasks like turning things on and off or responding to simple inputs.

It has the engine (CPU), plus it also includes control systems for steering, brakes, air conditioning, GPS, music, and even safety systems. All of these functions are tightly integrated into one system, providing a smooth, all-in-one experience for the driver.
-->

---
layout: center
---

# Quiz Section!

---
layout: center
---

# Is it CPU, MCU or SOC


---
layout: center
---


<img src=./img/presentation/mcu.png width=500px />


---
layout: center
---

<img src='./img/presentation/mcs-question/mcu.png' width=100px />
<br/>
<v-click>
https://appcodelabs.com/what-is-soc-system-on-chip/block-diagram-mcu
</v-click>
---
layout: center
---

<img src='./img/presentation/mcs-question/cpu.png' width=400px />

---
layout: center
---

<img src='./img/presentation/mcs-question/soc.png' width=600px />
<br />
<v-click>
http://microcontrollerslab.com/wp-content/uploads/2020/10/system-on-chip-SoC.gif
</v-click>

---
layout: center
---

https://floooh.github.io/visualz80remix/

---
layout: center
---


<img src='./img/presentation/mcs-question/anothersoc.png' width=500px />
<br />
<v-click>
https://www.espressif.com/en/news/ESP32_C3
</v-click>

---
layout: default
---

# What is the ESP32
<br/>
ESP32 is a feature-rich <span v-mark.yellow="1">SoC</span> with integrated <span v-mark.blue="2">Wi-Fi</span> and <span v-mark.blue="2">Bluetooth</span> connectivity for a wide-range of IoT applications.

<div class="flex flex-col items-center">
<img src=./img/presentation/whatisesp32.png width=500px />
</div>

---
layout: default
---

# Why is ESP32 popular 

<v-click>
<img src='./img/presentation/esp32/googlesearch.png'>
</v-click>


---
layout: center
---

# Let's imagine you need to create your own device.

---
layout: center
---

# There are <span v-mark.circle.red="1">only</span> two parts of what we need to do:

<v-click at=2>

# Hardware and Software

</v-click>

<v-click at=3>
<span v-mark.red="3">only</span> :)
</v-click>
<v-click at=4>
<span v-mark.red="4">very simple right?</span> :)
</v-click>

---
layout: center
---

# Hardware

<v-clicks>

- Design PCB (Printed circuit board)
- Manufacture it
- Solder it
- Test it physically

</v-clicks>
<!--
During the workshop, there won't be enough time to create this hardware.


But the good news is, we did record it, so we can go through this process together.
-->



---
layout: two-cols
---

# Design PCB

<v-click>
We have:

<img src='./img/presentation/esp32-module.png' width=100px />
<img src='./img/presentation/btn.png' width=100px />
<img src='./img/presentation/rotateenco.png' width=100px />
<img src='./img/presentation/usbc.png' width=100px />
</v-click>

::right::
<v-click>

We can do it with a breadboard:
<img src='./img/presentation/breadboard.png' width=400px />
</v-click>
<v-click>
Or we can do it with a PCB:
<img src='./img/presentation/pcb.jpg' width=200px />
</v-click>
---
layout: center
---

#   For designing the PCB, we chose to use: JLCPCB

CN: 嘉立创 

<v-click>

Original PCB Link: https://oshwhub.com/esp-college/esp32-h2-switch


</v-click>

---
layout: center
---

# Simplified PCB 


<img src='./img/presentation/jlc/schema.png' width=800px >



---
layout: default
---

# Logical 0 and 1
<br/>
<br/>
<br/>
<br/>
<div class="flex flex-col items-center">
  <img src='./img/presentation/logic01.png' width=500px >
</div>


---
layout: default
---

# Button design with a pull-up resistor.

<div class="flex flex-col items-center">
  <img src='./img/presentation/pullup.png' width=400px >
</div>


---
layout: center
---

# Simplified PCB 


<img src='./img/presentation/jlc/schema.png' width=800px >

---
layout: default
---

# Simplified PCB 


<img src='./img/presentation/pcb-circuit.png' width=500px >
---
layout: two-cols
---

# 3d model
<img src='./img/presentation/jlc/image copy.png' width=300px/>

::right::
<br/>
<br/>
<img src='./img/presentation/jlc/image.png' width=300px/>

---
layout: center
---

# We manufactored PCB, and it arrived in 2-3 days. 
<img src='./img/presentation/pcb-wo-el.jpg' width=600px>

---
layout: two-cols
---

# Soldering PCB 
<br/>


::right::
<img src='./img/presentation/jlc/cook0.jpg' width=400px />

---
layout: center
---

# Soldering PCB
<br/>
<video controls src="./video/cook-wo-audio.mp4" title="Title" width="250px"></video>


---
layout: center
---

# Result 
<img src='./img/presentation/resulpcb.jpg' width=600px>

---
layout: center
---

# Testing PCB 
<br/>
<video controls src="./video/click.mp4" title="Title" width="700px"></video>


---
laytout: center
---

# Modeling the case
<img src='./img/presentation/3d-corpus.png' width=500px/>

---
layout: center
---

# Printing the case
<br/>
<video controls src="./video/printing.mp4" title="Title" width="270px"></video>

---
layout: center
---

# Printing the case
<br/>
<video controls src="./video/printing.webm" title="Title" width="700px"></video>


---
layout: center
---

# We manufactored more PCB...
<img src='./img/assembly/wallpaper.png' width=600px>


---
layout: center
---

# Final result
<br/>

<img src='./img/presentation/output.gif' >

---
layout: center
---

# Software

<br/>
<v-clicks>

We have hardware, and we need to control it somehow. 

You can write your own app (baremetal) from scratch, but it is painful and hard.

But there is an SDK for it; it helps you run your program on the chip.

</v-clicks>



---
layout: default
---

# There are a few ways to program the ESP32 chip.
https://github.com/espressif/esp-idf

- **ESP-IDF** is an open-source project. It is usually used for professional development.

- ...

- For fast and easy development, it has a package for the **Arduino IDE**. 
<v-click>


https://github.com/horw/devs-and-lattes-meets-30-nov

<img src='./img/presentation/qr-code.png' width=150px>

</v-click>


---
layout: default
---

# Example 1

<img src='./img/presentation/project/app1.png' width=500px/>

<v-click>

```cpp

void setup() {
  Serial.begin(9600);
}

void loop(){
  Serial.println("Hello world!");
  delay(100);
}

```
</v-click>

---
layout: default
---

# Example 2
<img src='./img/presentation/project/app2.png' width=500px />

<v-click>

````md magic-move

```cpp

void setup() {
  Serial.begin(9600);
}

void loop(){
  Serial.println("Hello world!");
  delay(100);
}

```

```cpp

#define BUTTON_IO_NUM 10

void setup() {
  Serial.begin(9600);
}

void loop(){
  Serial.println("Hello world!");
  delay(100);
}

```


```cpp

#define BUTTON_IO_NUM 10

void setup() {
  pinMode(BUTTON_IO_NUM, INPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.println("Hello world!");
  delay(100);
}

```
```cpp

#define BUTTON_IO_NUM 10


void setup() {
  pinMode(BUTTON_IO_NUM, INPUT);
  Serial.begin(9600);
}

void loop(){
  bool btnPressed = digitalRead(BUTTON_IO_NUM);
  Serial.println("Hello world!");
  delay(100);
}

```
```cpp

#define BUTTON_IO_NUM 10

void setup() {
  pinMode(BUTTON_IO_NUM, INPUT);
  Serial.begin(9600);
}

void loop(){
  bool btnPressed = digitalRead(BUTTON_IO_NUM);
  if (btnPressed){
    Serial.println("Hello world!");
  }
  delay(100);
}

```



````
</v-click>

---
layout: two-cols
---

# Example 3
<img src='./img/presentation/project/app3.png' width=500px />

<img src='./img/presentation/rotate.png' width=500px/>

::right::

````md magic-move
```cpp

#define BUTTON_IO_NUM 10

void setup() {
  pinMode(BUTTON_IO_NUM, INPUT);
  Serial.begin(9600);
}

void loop(){
  bool btnPressed = digitalRead(BUTTON_IO_NUM);
  if (btnPressed){
    Serial.println("Hello world!");
  }
  delay(100);
}

```

```cpp

#define KNOB_A_IO_NUM 6
#define KNOB_B_IO_NUM 7


void setup() {
  pinMode(KNOB_A_IO_NUM, INPUT_PULLUP);
  pinMode(KNOB_B_IO_NUM, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  bool btnPressed = digitalRead(BUTTON_IO_NUM);
  if (btnPressed){
    Serial.println("Hello world!");
  }
  delay(100);
}

```

```cpp

#define KNOB_A_IO_NUM 6
#define KNOB_B_IO_NUM 7


void setup() {
  pinMode(KNOB_A_IO_NUM, INPUT_PULLUP);
  pinMode(KNOB_B_IO_NUM, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  bool aHigh = digitalRead(KNOB_A_IO_NUM);
  bool bHigh = digitalRead(KNOB_B_IO_NUM);
  ...
  if (btnPressed){
    Serial.println("Hello world!");
  }
  delay(100);
}

```

```cpp

#define KNOB_A_IO_NUM 6
#define KNOB_B_IO_NUM 7


void setup() {
  pinMode(KNOB_A_IO_NUM, INPUT_PULLUP);
  pinMode(KNOB_B_IO_NUM, INPUT_PULLUP);
  Serial.begin(9600);
}

void knob(){
  bool aHigh = digitalRead(KNOB_A_IO_NUM);
  bool bHigh = digitalRead(KNOB_B_IO_NUM);
}

void loop(){
  if (btnPressed){
    Serial.println("Hello world!");
  }
  delay(100);
}

```

```cpp

#define KNOB_A_IO_NUM 6
#define KNOB_B_IO_NUM 7


void setup() {
  pinMode(KNOB_A_IO_NUM, INPUT_PULLUP);
  pinMode(KNOB_B_IO_NUM, INPUT_PULLUP);
  Serial.begin(9600);
}

void knob(){
  bool aHigh = digitalRead(KNOB_A_IO_NUM);
  bool bHigh = digitalRead(KNOB_B_IO_NUM);
}

void loop(){
  attachInterrupt(
    digitalPinToInterrupt(KNOB_A_IO_NUM),
    knob, CHANGE
  );
  if (btnPressed){
    Serial.println("Hello world!");
  }
  delay(100);
}

```

```cpp

#define KNOB_A_IO_NUM 6
#define KNOB_B_IO_NUM 7


void setup() {
  pinMode(KNOB_A_IO_NUM, INPUT_PULLUP);
  pinMode(KNOB_B_IO_NUM, INPUT_PULLUP);
  Serial.begin(9600);
}

int total = 0;
void knob(){
  bool aHigh = digitalRead(KNOB_A_IO_NUM);
  bool bHigh = digitalRead(KNOB_B_IO_NUM);
  total ++;
}

void loop(){
  attachInterrupt(
    digitalPinToInterrupt(KNOB_A_IO_NUM),
    knob, CHANGE
  );
  Serial.printf("total = %d \n", total);
  delay(100);
}

```
  



````



---
layout: default
---

# Example 4
<img src='./img/presentation/project/app4.png' />

<v-click>
We have Bluetooth,
<br/> but it requires more power, so most wearable devices currently use BLE (Bluetooth Low Energy).

</v-click>

<v-click>

**GATT** (Generic Attribute Profile) is conceptually similar to an HTTP server but operates over BLE.<br/> 
It defines how data is structured, transmitted, and accessed between BLE devices.

</v-click>


---
layout: default
---


# GATT Server Like an HTTP Server

| **Concept**          | **BLE GATT**                                  | **HTTP Server**               |
|-----------------------|-----------------------------------------------|--------------------------------|
| **Server Role**       | GATT Server: Device that holds data.          | HTTP Server: Host serving web data. |
| **Client Role**       | GATT Client: Requests data (e.g., smartphone). | Browser/HTTP Client.          |
| **Endpoint**          | Characteristics (within Services).           | URLs/Paths (REST endpoints).  |
| **Request Type**      | Read, Write, Notify, Indicate.               | GET, POST, PUT, DELETE.       |
| **Data Format**       | Binary/Custom Data in Characteristics.       | JSON, XML, HTML.              |


---
layout: default
---

# GATT Structure

<img src='./img/presentation/gatt.png'>



---
layout: default
---

# Example 4
<img src='./img/presentation/project/app4.png' width=300px />

````md magic-move

```cpp
#include <BLEDevice.h>
#include <BLEUtils.h>
```
```cpp
void setup() {
  Serial.begin(115200);

  BLEDevice::init("Hello world");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
    "4fafc201-1fb5-459e-8fcc-c5c9c3319112",
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
  );
  pCharacteristic->setValue("Hello World!");
  pService->start();

  BLEDevice::startAdvertising();
}
```

```cpp
#include <BLEDevice.h>
#include <BLEUtils.h>

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c3314112"
void setup() {
  Serial.begin(115200);

  BLEDevice::init("Hello world");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
    "4fafc201-1fb5-459e-8fcc-c5c9c3319112",
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
  );
  pCharacteristic->setValue("Hello World!");
  pService->start();

  BLEDevice::startAdvertising();
}

```

````
---
layout: default
---

# Example 5
<img src='./img/presentation/project/app5.png' />


---
layout: default
---

# Example 6
<img src='./img/presentation/project/app6.png' />

---
layout: default
---

````md magic-move

```cpp
uint8_t REPORT_MAP[] = {
  USAGE_PAGE(1), 0x0C,  // Usage Page (Consumer Devices)
  USAGE(1), 0x01,       // Usage (Consumer Control)
  COLLECTION(1), 0x01,  // Collection (Application)
    REPORT_ID(1), 0x01,   // Report ID (1)

    // Volume Controls
    USAGE(1), 0xCD,         // Usage (Pause)
    USAGE(1), 0xE9,    // Usage Minimum (Volume Up)
    USAGE(1), 0xEA,    // Usage Maximum (Volume Down)
    LOGICAL_MINIMUM(1), 0x00,  // Logical Minimum (0)
    LOGICAL_MAXIMUM(1), 0x01,  // Logical Maximum (1)
    REPORT_SIZE(1), 0x01,      // Report Size (1)
    REPORT_COUNT(1), 0x02,     // Report Count (2 - Volume Up and Volume Down)
    0x81, 0x02,            // Input (Data, Variable, Absolute)

    REPORT_COUNT(1), 0x05,  // Report Count (4 - Padding)
    0x81, 0x03,         // Input (Constant, Variable, Absolute)
  END_COLLECTION(0)
};
// This report have few problems
```

```cpp
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEHIDDevice.h> //<--
```

```cpp
void setup() {
  BLEDevice::init("ESP32-HID-Button");
  BLEServer *pServer = BLEDevice::createServer();

  BLEHIDDevice *hid = new BLEHIDDevice(pServer);
  inputCharacteristic = hid->inputReport(1);
  hid->pnp(0x02, 0x0810, 0xe501, 0x0106);
  hid->hidInfo(0x00, 0x01);

  uint8_t REPORT_MAP[] = {...};
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
}

```
```cpp

inputCharacteristic->setValue((uint8_t *)volumeUpReport, sizeof(volumeUpReport));
inputCharacteristic->notify();

inputCharacteristic->setValue((uint8_t *)keyReleaseReport, sizeof(keyReleaseReport));
inputCharacteristic->notify();
```
````

https://www.usb.org/sites/default/files/hut1_4.pdf


---
layout: default
---

# Result
<br/>
<video controls src="./video/hid-result2.mp4" title="Title" width="230px"></video>


---
layout: center
---

# Thanks to all who were involved in this workshop!


---
layout: center
---

# Take a photo together!