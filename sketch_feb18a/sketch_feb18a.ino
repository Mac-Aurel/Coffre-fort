#include <Keypad.h>
#include <Servo.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

Servo servo;

const char* ACCESS_CODE = "1234";
const int LOCKED_POSITION = 0;
const int UNLOCKED_POSITION = 90;

bool locked = true;
int attempts = 0;

void setup() {
  servo.attach(10);
  servo.write(LOCKED_POSITION);
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  
  if (key != NO_KEY) {
    Serial.print("Key Pressed: ");
    Serial.println(key);
    if (key == '#') {
      if (locked) {
        if (attempts >= 3) {
          Serial.println("Too many attempts. Wait 5 seconds and try again.");
          delay(5000);
          attempts = 0;
        }
        else {
          String code = "";
          for (int i = 0; i < 4; i++) {
            char key = keypad.getKey();
            if (key != NO_KEY) {
              code += key;
            }
            delay(50);
          }
          if (code == ACCESS_CODE) {
            locked = false;
            servo.write(UNLOCKED_POSITION);
            Serial.println("Unlocked");
          }
          else {
            attempts++;
            Serial.println("Access Denied");
          }
        }
      }
      else {
        locked = true;
        servo.write(LOCKED_POSITION);
        Serial.println("Locked");
      }
    }
  }
}
