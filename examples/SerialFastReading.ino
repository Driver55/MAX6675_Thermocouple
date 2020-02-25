/*
  Average Thermocouple

  Reads a temperature from a thermocouple based
  on the MAX6675 driver and displays it in the default Serial.

  https://github.com/YuriiSalimov/MAX6675_Thermocouple

  Created by Yurii Salimov, May, 2019.
  Released into the public domain.
*/
#include <Thermocouple.h>
#include <MAX6675_Thermocouple.h>
/*
#define SCK_PIN 3
#define CS_PIN 4
#define SO_PIN 5
*/
#define SCK_PIN 13
#define CS_PIN 10
#define SO_PIN 12

double starttime_ms, conversiontime_ms, starttime_us, conversiontime_us;

Thermocouple* thermocouple;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);

  thermocouple = new MAX6675_Thermocouple(SCK_PIN, CS_PIN, SO_PIN);
}

// the loop function runs over and over again forever
void loop() {
  // Reads temperature

  // Read Temperature original timing ( delay in msec. )
  starttime_ms = millis();
  const double celsius = thermocouple->readCelsius();
  conversiontime_ms = millis() - starttime_ms;

  // Read Temperature original timing ( delay in usec. )
  starttime_us = micros();
  const double celsius_fast = thermocouple->FastReadCelsius();
  conversiontime_us = micros() - starttime_us;

  const double kelvin = thermocouple->readKelvin();
  const double fahrenheit = thermocouple->readFahrenheit();

  // Output of information
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(kelvin);
  Serial.print(" K, ");
  Serial.print(fahrenheit);
  Serial.print(" F ");
  Serial.print("Convertiontime : ");
  Serial.print(conversiontime_ms);
  Serial.print(" msec.");
  Serial.print("|| Fast Version : ");
  Serial.print(celsius_fast);
  Serial.print(" C, ");
  Serial.print(conversiontime_us);
  Serial.println(" usec.");
  
  delay(500); // optionally, only to delay the output of information in the example.
}
