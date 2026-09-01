# Wiring Connections — Ultrasonic Parking Sensor

## HC-SR04 Ultrasonic Sensor

| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | D9 |
| ECHO | D10 |

## I2C LCD (16x2)

| Pin | Connects to |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## LED Range Indicator (9 LEDs, 3 per color)

Each color group shares one Arduino pin at the anode side; each LED has its own resistor before joining a shared GND rail.

| Color | Qty | Arduino Pin |
|---|---|---|
| Green | 3 | D2 |
| Yellow | 3 | D3 |
| Red | 3 | D4 |

## Buzzers

| Buzzer | Signal Pin | Power | Ground |
|---|---|---|---|
| Buzzer 1 (main) | D8 | 5V | GND |
| Buzzer 2 (danger-only) | D7 | 5V | GND |

**Behavior:** Buzzer 1 beeps alone at caution range; both buzzers sound together at danger range for an emergency-style effect.

## Grounding — Important

Use **all 3 of the Arduino's GND pins**, spread evenly across the breadboard's ground rail, rather than a single GND pin feeding the entire circuit. See `troubleshooting.md` for why this matters.
