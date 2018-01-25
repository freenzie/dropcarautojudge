/*
Adafruit Arduino - Lesson 5. Serial Monitor
*/

#include <SoftwareSerial.h>
#include <Servo.h>

int latchPin = 6;
int clockPin = 7;
int dataPin = 5;

byte leds = 0;

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  updateShiftRegister();
  Serial.begin(9600);
  while (! Serial); // Wait untilSerial is ready - Leonardo
  Serial.println("Setup complete");
  Serial.println("Enter Lane Number 0 to 3 or 's' to START or 'r' to RESET");
}

void loop() 
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch >= '0' && ch <= '3')
    {
      int led = ch - '0';
      bitSet(leds, led);
      updateShiftRegister();
      Serial.print("Turned on LED ");
      Serial.println(led);
    }
    if (ch == 's')
    {
      leds = 0;
      updateShiftRegister();
      Serial.println("Start Action");
      Serial.println("Release car");
      delay(2000);
      Serial.println("Reset gate");
      delay(1000);
    }
    if (ch == 'r')
    {
      leds = 0;
      Serial.println("Reset Action");
      updateShiftRegister();
      }
  }
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
   Serial.println("Update Shift Register");
}
