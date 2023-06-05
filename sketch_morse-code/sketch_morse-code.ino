#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Define the mapping of characters to Morse code
const char* morseCode[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
};

void setup() {
  lcd.begin(16, 2);  // Initialize the LCD display

  lcd.print("Morse Code:");
  delay(2000);
  lcd.clear();

  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.toUpperCase();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(input);  // Display the input string

    lcd.setCursor(0, 1);
    for (size_t i = 0; i < input.length(); i++) {
      char c = input.charAt(i);
      if (c >= 'A' && c <= 'Z') {
        int index = c - 'A';
        lcd.print(morseCode[index]);  // Display the corresponding Morse code
        lcd.print(" ");
      }
    }

    delay(5000);  // Wait for 5 seconds before clearing the LCD
    //lcd.clear();
  }
}
