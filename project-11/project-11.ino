// -*-mode: c++; indent-tabs-mode: nil; -*-

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
}

#define DEBUG 0

void loop() {
  switchState = digitalRead(switchPin);

  // Added a debug block which was helpful to see when the state change occured. 
#if DEBUG == 1
  lcd.clear();
  lcd.setCursor(0, 0);
  if (switchState == LOW) {
    lcd.print("LOW");
  } else {
    lcd.print("HIGH");
  }
  delay(500);
  return;
#endif

  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says:");
      lcd.setCursor(0, 1);
      switch (reply) {
      case 0:
        lcd.print("Yes");
        break;
      case 1:
        lcd.print("Most likely");
        break;
      case 2:
        lcd.print("Certainly");
        break;
      case 3:
        lcd.print("Outlook good");
        break;
      case 4:
        lcd.print("Unsure");
        break;
      case 5:
        lcd.print("Ask again");
        break;
      case 6:
        lcd.print("Doubtful");
        break;
      case 7:
        lcd.print("No");
        break;
      default:
        lcd.print("WHAT?");
        break;
      }
    }
  }
  prevSwitchState = switchState;
}
