#include<LiquidCrystal.h>
#include <EEPROM.h>
#include <Wire.h>

LiquidCrystal lcd(7, 6, 2, 3, 4, 5);
const int  ADDRESS = 17; 
byte votes0 [4] ;
byte votes1 [4] ; 
byte votes2 [4] ;
byte votes3 [4] ;
byte totalvote[4] = {0 , 0 , 0 , 0};
byte savedvote[4];
void setup() {
  pinMode(13, INPUT);
  Serial3.begin(9600);
  Serial2.begin(9600);
  Serial1.begin(9600); // opens serial port, sets data rate to 9600 bps
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("    Voting Machine");
  delay(100);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CE");
  lcd.setCursor(4,0);
  lcd.print("CS");
  lcd.setCursor(8,0);
  lcd.print("EE");
  lcd.setCursor(12,0);
  lcd.print("ME");
  EEPROM.get(ADDRESS , savedvote);
  
//  memoryRead(savedvote , 4);
  for (int i = 0 ; i < 4 ; i++ ){
    if (savedvote[i] == 255){
      savedvote[i] = 0;
    }
  }
  
}

void loop() {
    totalvote[0] = savedvote[0] + votes0[0]+votes1[0]+votes2[0]+votes3[0];
    totalvote[1] = savedvote[1] + votes0[1]+votes1[1]+votes2[1]+votes3[1];
    totalvote[2] = savedvote[2] + votes0[2]+votes1[2]+votes2[2]+votes3[2];
    totalvote[3] = savedvote[3] + votes0[3]+votes1[3]+votes2[3]+votes3[3];

    if (digitalRead(13) == HIGH){
      EEPROM.put(ADDRESS,totalvote);
    }
    lcd.setCursor(0,0);
    lcd.print("CE");
    lcd.setCursor(1,1);
    lcd.print(totalvote[0],DEC);
    lcd.setCursor(4,0);
    lcd.print("CS");
    lcd.setCursor(5,1);
    lcd.print(totalvote[1], DEC);
    lcd.setCursor(8,0);
    lcd.print("EE");
    lcd.setCursor(9,1);
    lcd.print(totalvote[2],DEC);
    lcd.setCursor(12,0);
    lcd.print("ME"); 
    lcd.setCursor(13,1);
    lcd.print(totalvote[3],DEC);
    
  if (Serial3.available() > 0){
    Serial3.readBytes(votes3 , 4);
  }
  
  if (Serial2.available() > 0){
    Serial2.readBytes(votes2 , 4); 
  }
 
  
  if (Serial1.available() > 0) {
    Serial1.readBytes(votes1 , 4); 
  }

  if (Serial.available() > 0){
    Serial.readBytes(votes0 , 4); 
  }
 
}
