/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/AnalogInput

 */

int sensorPin = A0;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(57600);
}

// insert delay in the loop function 

// setup this environment in vscode

// setup juniper as well? so that I have piping partials etc


float to_distance(float v){
//return round ( 5461 ÷ (data - 17) -2, places)

  // subtracting 1 extra to compensate maybe it's just the hardware???
  //return round ( 5461 ÷ float((data - 17) -3), places)
  //return round ( 5461 ÷ float((data - 17) -2), places)
  //return 13.5 ÷ volts

  //return 16.2537 * pow(v, 4) - 129.893 * pow(v, 3) + 382.268 * pow(v, 2) - 512.611 * v + 306.439;
 // return 65 * pow(1 / v, 0.10);
  return v;
 //return (4.104815014 * 10 ** -12) * (x**10) - (7.50448734 * 10 ** -10 ) * (x**9) + (5.754181221*10**-8) * (x**8) - 2.386526798·10-6 x7 + 5.700833884·10-5 x6 - 7.452731288·10-4 x5 + 3.565112317·10-3 x4 + 3.087640411·10-2 x3 - 4.920343313·10-1 x2 + 2.002517114 x + 2.206473192·10-1
}

float to_volts(int data){
  float volts = (data * 3.3) / float(1023);
  return volts;
}


void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  
  Serial.println("Level: " + String(sensorValue) + " Distance: " + String(to_distance(to_volts(sensorValue))));
  delay(100);

}
