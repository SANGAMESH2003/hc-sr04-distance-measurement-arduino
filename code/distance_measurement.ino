#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trigPin = 9;
int echoPin = 10;
int ledPin = 7;   // optional LED

long duration;
int distance;

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Human Detect");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;

  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print("cm ");

  // Detection condition
  if (distance > 0 && distance < 50) {
    lcd.setCursor(0, 1);
    lcd.print("Object Detected ");
    digitalWrite(ledPin, HIGH);  // LED ON
  } else {
    lcd.setCursor(0, 1);
    lcd.print("No Object ");
    digitalWrite(ledPin, LOW);   // LED OFF
  }

  delay(500);
}
