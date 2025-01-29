#include <Arduino.h>

int greenLEDpin = 2; // Pin green LED is connected to. Low resistance (lots of light)
int yellowLEDpin = 3; // Pin yellow LED is connected to
int redLEDpin = 4; // Pin red LED is connected to. High resistance (little light)

int lightSensorPin = A0; // Pin light sensor is connected to, analog pin (continuous and not discrete like digital pins)
int analogValue = 0; // Variable to store the analog value read from the sensor

void setup() {
  // Set pins to outputs
  pinMode(greenLEDpin, OUTPUT);
  pinMode(yellowLEDpin, OUTPUT);
  pinMode(redLEDpin, OUTPUT);
}

void loop() {

  analogValue = analogRead(lightSensorPin); // Read the analog value from the photoresistor and store it in the variable

  if(analogValue < 50) {
    digitalWrite(redLEDpin, HIGH); // Turn on red LED when analog value is less than 50
  }

  if(analogValue >= 50 && analogValue <= 100) { 
    digitalWrite(yellowLEDpin, HIGH); // Turn on yellow LED when analog value is between 50 and 100
  }

  else {
    digitalWrite(greenLEDpin, HIGH); // Turn on green LED when analog value is greater than 100
  }

  delay(200); // Delay for 200 milliseconds
  
  digitalWrite(greenLEDpin, LOW); // Turn off green LED by setting to low voltage
  digitalWrite(yellowLEDpin, LOW); // Turn off yellow LED by setting to low voltage
  digitalWrite(redLEDpin, LOW); // Turn off red LED by setting to low voltage
}
