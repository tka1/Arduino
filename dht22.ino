

#include "cactus_io_DHT22.h"
#include <LiquidCrystal.h>

#define DHT22_PIN 6     
DHT22 dht(DHT22_PIN);
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
 void setup() {
  Serial.begin(9600); 
  Serial.println("DHT22 Humidity - Temperature Sensor");
  Serial.println("RH\t\tTemp (C)\tTemp (F)\tHeat Index (C)\t Heat Index (F)");
  lcd.begin(16, 2);
 dht.begin();
}

void loop() {
   lcd.setCursor(0, 0);

  dht.readHumidity();
  dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(dht.humidity) || isnan(dht.temperature_C)) {
    Serial.println("DHT sensor read failure!");
    return;
  }
  Serial.print(dht.humidity); Serial.print(" %\t\t");
  Serial.print(dht.temperature_C); Serial.print(" *C\t");
  Serial.print(dht.temperature_F); Serial.print(" *F\t");
  Serial.print(dht.computeHeatIndex_C()); Serial.print(" *C\t");
  Serial.print(dht.computeHeatIndex_F()); Serial.println(" *F");
  lcd.print(dht.temperature_C);
  lcd.print(" C ");
  lcd.setCursor(0, 1);
  lcd.print(dht.humidity);
  lcd.print(" %");
 
  delay(5000);
}

