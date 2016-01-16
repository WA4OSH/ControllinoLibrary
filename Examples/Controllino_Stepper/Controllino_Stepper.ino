#include <Stepper.h>
#include <SPI.h>
#include <Controllino.h>

/* 
 Stepper Motor Control - one revolution

 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 Modified for Controllino 15 Jan. 2015
 by Konrad Roeder
 
 */

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
const int wire1 = CONTROLLINO_D0;
const int wire2 = CONTROLLINO_D1;
const int wire3 = CONTROLLINO_D2;
const int wire4 = CONTROLLINO_D3;


// for your motor

// initialize the stepper library on pins D0 through D3:
Stepper myStepper(stepsPerRevolution, wire1, wire2, wire3, wire4);     

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}  
