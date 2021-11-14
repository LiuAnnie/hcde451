/* Annie Liu
 * Last Updated 11/04/2021
 * 
 * Description: This program continuously moves the stepper motor.
 * Reference Tutorial: https://randomnerdtutorials.com/esp8266-nodemcu-stepper-motor-28byj-48-uln2003/
 */

#include <AccelStepper.h>

const int stepsPerRevolution = 2048;

// ULN2003 Motor Driver Pins
#define IN1 D1
#define IN2 D2
#define IN3 D5
#define IN4 D6

// Initializing stepper
AccelStepper stepper(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);

// This runs once at the beginning.
void setup() {  
  stepper.setMaxSpeed(200);       // Set maximum speed.
  stepper.setAcceleration(100);   // Set acceleration.
}

// This section loops. Each loop will have the stepper motor make
// one full revolution.
void loop() {
  stepper.move(stepsPerRevolution);
  stepper.run();
}
