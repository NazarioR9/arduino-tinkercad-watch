#include <LiquidCrystal.h>

#define LBOUND 34
#define UBOUND 39

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensorValue(0);
int outputValue(0);
int latestCriticalValue(0);

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.print("Temperature:");
}

void loop() {
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue, 20, 358, 30, 45);
  
  lcd.setCursor(0, 1);
  lcd.print(outputValue);
  lcd.print(" °C");
  
  bool condition = outputValue < LBOUND || outputValue > UBOUND;
  condition &= (latestCriticalValue != outputValue);
  
  if (condition) {
    latestCriticalValue = outputValue;
    
    Serial.print("Critical temperature: ");
    Serial.print(outputValue);
    Serial.println(" %");
  }
  
  // delay a bit
  delay(50);
}
 