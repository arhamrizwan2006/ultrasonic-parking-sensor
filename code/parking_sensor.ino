#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD setup - address 0x27 is most common; if your LCD shows nothing or garbled text, try 0x3F instead
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin definitions
const int trigPin = 9;
const int echoPin = 10;

const int greenLED = 2;
const int yellowLED = 3;
const int redLED = 4;

const int buzzer1 = 8;
const int buzzer2 = 7;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Send a short pulse to trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure how long the echo pulse takes to return
  duration = pulseIn(echoPin, HIGH);

  // Convert that time into a distance in centimeters
  distance = duration * 0.034 / 2;

  // Show the distance on the LCD's first line
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm   ");

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 30) {
    // Safe range
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);

    digitalWrite(buzzer1, LOW);
    digitalWrite(buzzer2, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Status: SAFE   ");
  }
  else if (distance > 15) {
    // Caution range - only buzzer1 beeps, slower pace
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Status: CAUTION");

    digitalWrite(buzzer1, HIGH);
    delay(200);
    digitalWrite(buzzer1, LOW);
    delay(300);
  }
  else {
    // Danger range - both buzzers beep together, fast pace
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("Status: DANGER ");

    digitalWrite(buzzer1, HIGH);
    digitalWrite(buzzer2, HIGH);
    delay(80);
    digitalWrite(buzzer1, LOW);
    digitalWrite(buzzer2, LOW);
    delay(80);
  }
}
