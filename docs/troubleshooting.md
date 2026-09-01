# Troubleshooting — Ultrasonic Parking Sensor

## Green and yellow LEDs never light up
**Cause:** Only one Arduino GND pin was feeding the entire breadboard ground rail. With 9 LEDs, 2 buzzers, the LCD, and the sensor all pulling ground through a single pin, the later components on the rail weren't getting a solid ground reference — so their LEDs stayed dark even though the code and wiring looked correct.

**Fix:** Use all 3 of the Arduino Uno's GND pins, spacing them out evenly along the breadboard's ground rail instead of relying on one. This resolved the issue completely.

## LCD shows nothing or garbled characters
Try changing the I2C address in the code from `0x27` to `0x3F` (or run an I2C scanner sketch to find your display's actual address) — this varies by LCD backpack manufacturer.

## Distance readings are erratic or stuck at 0
- Double-check TRIG and ECHO aren't swapped
- Make sure nothing is directly blocking the sensor at very close range (HC-SR04 has a minimum reliable distance, typically ~2cm)
- Loose jumper wires on VCC/GND are a common cause of intermittent readings
