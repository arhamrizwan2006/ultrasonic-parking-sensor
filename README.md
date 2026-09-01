<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&amp;color=0:0F2027,50:203A43,100:2C5364&amp;height=220&amp;section=header&amp;text=Ultrasonic%20Parking%20Sensor&amp;fontSize=40&amp;fontColor=ffffff&amp;animation=fadeIn&amp;fontAlignY=38&amp;desc=Real-Time%20Distance%20Alarm%20with%20LCD%2C%20LEDs%20and%20Dual%20Buzzers&amp;descAlignY=58&amp;descSize=17" width="100%"/>

<img src="https://readme-typing-svg.demolab.com/?font=Fira+Code&amp;size=22&amp;pause=1000&amp;color=2C5364&amp;center=true&amp;vCenter=true&amp;width=650&amp;lines=HC-SR04+Distance+Sensing;3-Tier+LED+Range+Indicator;Escalating+Dual-Buzzer+Alarm" alt="Typing SVG" />

<br/>

![Status](https://img.shields.io/badge/Status-Complete-2C5364?style=for-the-badge&logo=checkmarx&logoColor=white)
![Board](https://img.shields.io/badge/Board-Arduino%20Uno-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/Language-C%2B%2B-203A43?style=for-the-badge&logo=cplusplus&logoColor=white)
![Sensor](https://img.shields.io/badge/Sensor-HC--SR04-0F2027?style=for-the-badge)

</div>

<img src="https://capsule-render.vercel.app/api?type=rect&amp;color=0:0F2027,50:203A43,100:2C5364&amp;height=3&amp;section=header" width="100%"/>

## 🎬 Demo

<div align="center">

![Demo photo](images/parking_sensor_demo.jpeg)

<!-- DRAG YOUR parking_sensor_demo.mp4 INTO THIS SPOT IN THE GITHUB README EDITOR -->
<!-- GitHub will auto-generate a video embed link here once uploaded -->

</div>

<img src="https://capsule-render.vercel.app/api?type=rect&amp;color=0:0F2027,50:203A43,100:2C5364&amp;height=3&amp;section=header" width="100%"/>

## ✨ Overview

A car park-assist style distance alarm — an HC-SR04 ultrasonic sensor measures distance to an object, an I2C LCD displays the live reading, three-color LED banks show range at a glance, and dual buzzers escalate their beeping as the object gets closer.

## 🚀 Features

| Feature | Description |
|---|---|
| 📏 **Live Distance Readout** | Real-time cm measurement on a 16x2 I2C LCD |
| 🟢🟡🔴 **3-Tier LED Indicator** | 9 LEDs (3 green / 3 yellow / 3 red) grouped by range |
| 🔊🔊 **Escalating Alarm** | Silent → single slow beep → dual fast alarm as distance shrinks |
| ⚙️ **Zero Extra Sensors** | Pure `pulseIn()` ultrasonic timing, no external distance libraries |

<img src="https://capsule-render.vercel.app/api?type=rect&amp;color=0:0F2027,50:203A43,100:2C5364&amp;height=3&amp;section=header" width="100%"/>

## 🧰 Hardware Used

| Component | Qty |
|---|:---:|
| Arduino Uno | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| 16x2 I2C LCD | 1 |
| LEDs (Green/Yellow/Red) | 9 (3 each) |
| Resistors (per LED) | 9 |
| 3-pin active buzzers | 2 |
| Breadboard | 1 |
| Jumper wires | ~30 |

<img src="https://capsule-render.vercel.app/api?type=rect&amp;color=0:0F2027,50:203A43,100:2C5364&amp;height=3&amp;section=header" width="100%"/>

## 🔌 Wiring

Full pin-by-pin breakdown in [`docs/wiring_connections.md`](docs/wiring_connections.md).

<details>
<summary><b>Quick reference (click to expand)</b></summary>
<br/>

| Sensor | Pin |
|---|:---:|
| TRIG | D9 |
| ECHO | D10 |

| LCD | Pin |
|---|:---:|
| SDA | A4 |
| SCL | A5 |

| LED Group | Pin |
|---|:---:|
| Green (x3) | D2 |
| Yellow (x3) | D3 |
| Red (x3) | D4 |

| Buzzer | Pin |
|---|:---:|
| Buzzer 1 (main) | D8 |
| Buzzer 2 (danger-only) | D7 |

⚠️ **Grounding note:** use all 3 of the Arduino's GND pins spread across the breadboard rail — a single GND pin isn't enough for this many components. See troubleshooting for why.

</details>

<img src="https://capsule-render.vercel.app/api?type=rect&amp;color=0:0F2027,50:203A43,100:2C5364&amp;height=3&amp;section=header" width="100%"/>

## ⚙️ How It Works

The HC-SR04 sends an ultrasonic pulse and measures how long it takes to bounce back, which the code converts into a distance in centimeters. Based on that distance, the system falls into one of three zones:

<div align="center">

| Zone | Distance | LEDs | Buzzer Behavior |
|:---:|:---:|:---:|---|
| 🟢 **Safe** | > 30 cm | Green | Silent |
| 🟡 **Caution** | 15–30 cm | Yellow | Buzzer 1 beeps slowly |
| 🔴 **Danger** | < 15 cm | Red | Both buzzers beep rapidly together |

</div>

The LCD continuously shows the live distance on the top line and the current status (SAFE / CAUTION / DANGER) on the bottom line.

<img src="https://capsule-render.vercel.app/api?type=rect&amp;color=0:0F2027,50:203A43,100:2C5364&amp;height=3&amp;section=header" width="100%"/>

## 🛠️ Setup

| Step | Action |
|:---:|---|
| 1 | Wire the circuit per [`docs/wiring_connections.md`](docs/wiring_connections.md) |
| 2 | Open `code/parking_sensor.ino` in the Arduino IDE |
| 3 | Install the `LiquidCrystal_I2C` library (Library Manager → search "LiquidCrystal I2C") |
| 4 | Select **Arduino Uno** as the board and the correct COM port |
| 5 | Upload, open Serial Monitor at 9600 baud, and test by moving an object toward the sensor |

<img src="https://capsule-render.vercel.app/api?type=rect&amp;color=0:0F2027,50:203A43,100:2C5364&amp;height=3&amp;section=header" width="100%"/>

## 🐛 Troubleshooting

See [`docs/troubleshooting.md`](docs/troubleshooting.md) — includes the ground-pin fix for LEDs that wouldn't light up.

<img src="https://capsule-render.vercel.app/api?type=waving&amp;color=0:2C5364,50:203A43,100:0F2027&amp;height=200&amp;section=footer"/>

<div align="center">

**Built with:** Arduino Uno · C++ · HC-SR04 · I2C LCD

*Know your distance before it's too late.* 🟢🟡🔴

</div>
