#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Adjust LCD address if needed (0x27 or 0x3F are common)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int signalPin = 7;  // Input signal pin

void setup() {
  pinMode(signalPin, INPUT);

  lcd.init();        // Initialize LCD
  lcd.backlight();   // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(1500);
  lcd.clear();
}

void loop() {
  int signalState = digitalRead(signalPin);

  lcd.clear();  // Clear screen before writing new text
  lcd.setCursor(6, 0);  // Column 6, Row 0 → centers 4-letter word

  if (signalState == LOW) {
    lcd.print("PASS");
  } else {
    lcd.print("STOP");
  }

  delay(200);
}
