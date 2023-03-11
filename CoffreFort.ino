#include <Keypad.h>
const byte ROWS = 4; // quatre lignes
const byte COLS = 4; // quatre colonnes
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // se connecte aux broches des rangées du clavier
byte colPins[COLS] = {5, 4, 3, 2}; // se connecte aux broches des colonnes du clavier

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

#include <Servo.h>
Servo myservo;  // crée un objet servo pour contrôler un servo
int servoPin = 13;
int pos = 0;


#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

#include <Stepper.h>
const int stepsPerRevolution = 200;

bool estMotPasseTrouver = false;
String motPasseConcatener = "";
const String motPasse = "487";

void setup() {
  myservo.attach(servoPin);
  myservo.write(0);
  lcd.init();
  lcd.backlight();
}
void loop() {
  char customKey = customKeypad.getKey();

  if (motPasseConcatener.length() == 0) {
    lcd.setCursor(0, 0);
    lcd.print("  Entrer votre  ");
    lcd.setCursor(0, 1);
    lcd.print("  mot de passe  ");
  }

  if (customKey) {
    if (customKey == '#') {
      if (motPasseConcatener == motPasse) {
        myservo.write(0);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("   Fermeture ");
        lcd.setCursor(0, 1);
        lcd.print("     en cours ");

        estMotPasseTrouver = false;
        delay(1000);

        lcd.clear();
      } else {        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  Mot de passe ");
        lcd.setCursor(0, 1);
        lcd.print("     efface ");
        delay(1000);

        lcd.clear();
      }
      motPasseConcatener = "";
    } else if (!estMotPasseTrouver) {
      if (customKey == '*') {
        verifierMotPasse();
      } else {
        motPasseConcatener = motPasseConcatener + customKey;

        if (motPasseConcatener.length() > 15) {
          lcd.clear();
          motPasseConcatener = "";
          //passwordEnter = false;
        } else if (!estMotPasseTrouver) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Mot de passe : ");
          lcd.setCursor(0, 1);
          lcd.print(motPasseConcatener);
        }
      }
    }
  }
}

void verifierMotPasse()
{
  if (motPasseConcatener == motPasse) {
    myservo.write(110);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Bonjour");
    lcd.setCursor(0, 1);
    lcd.print("  Lydia-Rose");
    estMotPasseTrouver = true;

    delay(1000);

  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Mot de passe");
    lcd.setCursor(0, 1);
    lcd.print("   incorrect");
    delay(1000);
    lcd.clear();
    //passwordEnter = false;
    motPasseConcatener = "";
  }
}
