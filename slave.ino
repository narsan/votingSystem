#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {22, 23, 24, 25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {26, 27, 28}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int vote1=0;
int vote2=0;
int vote3=0;
int vote4=0;
void setup() {
//  pinMode(53 , OUTPUT);
  pinMode(52, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  char customKey = keypad.waitForKey();
  
  if(customKey == '1'){
    vote1++;
    digitalWrite(52, HIGH);
    delay(20);
    digitalWrite(52 , LOW);
//    tone(53,1000);
//    delay(20);
//    noTone(53);
//    delay(20);
  }
  if(customKey == '2'){
    vote2++;
    digitalWrite(52, HIGH);
    delay(20);
    digitalWrite(52 , LOW);
//    tone(53,1000);
//    delay(20);
//    noTone(53);
//    delay(20);
  }
  if(customKey == '3'){
    vote3++;
    digitalWrite(52, HIGH);
    delay(20);
    digitalWrite(52 , LOW);
//    tone(53,1000);
//    delay(20);
//    noTone(53);
//    delay(20);
  }
  if(customKey == '4'){
    vote4++;  
    digitalWrite(52, HIGH);
    delay(20);
    digitalWrite(52 , LOW);
//    tone(53,1000);
//    delay(20);
//    noTone(53);
//    delay(20);
  }
  
  byte data [] = {vote1 , vote2 , vote3 , vote4};
  Serial.write(data,4);
  delay(100);

}
