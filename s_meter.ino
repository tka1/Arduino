//https://www.electronicsblog.net/
//Arduino LCD horizontal progress bar using custom characters
#include <LiquidCrystal.h>

#define lenght 16.0


double percent=100.0;
unsigned char b;
unsigned int peace;

// custom charaters

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
byte p1[8] = {
  0x10,
  0x10,
  0x10,
  0x10,
  0x10,
  0x10,
  0x10,
  0x10};

byte p2[8] = {
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18};

byte p3[8] = {
  0x1C,
  0x1C,
  0x1C,
  0x1C,
  0x1C,
  0x1C,
  0x1C,
  0x1C};

byte p4[8] = {
  0x1E,
  0x1E,
  0x1E,
  0x1E,
  0x1E,
  0x1E,
  0x1E,
  0x1E};

byte p5[8] = {
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F,
  0x1F};

  byte p6[8] = {
0b00010,
  0b00010,
  0b00010,
  0b00010,
  0b00010,
  0b00010,
  0b00010,
  0b00010
};

  byte p7[8] = {
 0b00100,
 0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100
};
byte p8[8] = {
0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000
};

void setup()   {
   
  delay(100);
  Serial.begin(9600);
  lcd.createChar(0, p1);
  lcd.createChar(1, p2);
  lcd.createChar(2, p3);
  lcd.createChar(3, p4);
  lcd.createChar(4, p5);
  lcd.createChar(5, p6);
  lcd.createChar(6, p7);
  lcd.createChar(7, p8);

  lcd.begin(16, 2);

}

void loop()
{

  lcd.setCursor(0, 0);

  //ADC conversion
 delay(2);
  unsigned int value = analogRead(1);
//  Serial.print("reading = ");
//  Serial.println(value);

  percent = value/1024.0*100.0;

  //lcd.print(value);

 // lcd.print(" - ");
 double a=lenght/100*percent;
//if (a<0.1){
  //lcd.print("OH2BBT         ");
//}
//else {
 //  lcd.print(" 6 7 8 9  III");
//}
 lcd.print(" 6 7 8 9");

 lcd.write(5);
 lcd.print(" ");
 lcd.write(7);
 lcd.write(5);
 lcd.print(" ");
 lcd.write(7);
     lcd.setCursor(0,1);

 // drawing black rectangles on LCD

  if (a>=1) {

    for (int i=1;i<a;i++) {

      lcd.write(4);

      b=i;
    }

    a=a-b;

  }

  peace=a*5;

// drawing charater's colums

  switch (peace) {

  case 0:

    break;

  case 1:
    lcd.print((char)0);

    break;

  case 2:
    lcd.write(1);
    break;

  case 3:
    lcd.write(2);
    break;

  case 4:
    lcd.write(3);
    break;

  }

//clearing line
  for (int i =0;i<(lenght-b);i++) {
    lcd.print(" ");
  }

  ;
}



