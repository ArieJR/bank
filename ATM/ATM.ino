// counter that register how many of which note are in queue
int var10;
int var20;
int var50;

// Pins for 10 notes
int in1Pin = 13;
int in2Pin = 2;
int in3Pin = 3;
int in4Pin = 4;
// Pins for 20 notes
int in5Pin = 5;
int in6Pin = 6;
int in7Pin = 7;
int in8Pin = 8;
// Pins for 50 notes
int in9Pin = 9;
int in10Pin = 10;
int in11Pin = 11;
int in12Pin = 12;
// set speed for all steppers
int stepperSpeed = 8;
int steps = 2000;
const int stepsPerRevolution = 2048;

int pause =  500;

#include <Stepper.h>

// setup for steppers
  Stepper stepper10 = Stepper(stepsPerRevolution, in1Pin, in2Pin, in3Pin, in4Pin);
  Stepper stepper20 = Stepper(stepsPerRevolution, in5Pin, in6Pin, in7Pin, in8Pin);
  Stepper stepper50 = Stepper(stepsPerRevolution, in9Pin, in10Pin, in11Pin, in12Pin);

void setup() {
  Serial.begin(9600);

// speed for all steppers
  stepper10.setSpeed(stepperSpeed);
  stepper20.setSpeed(stepperSpeed);
  stepper50.setSpeed(stepperSpeed);

  var10 = 100;
}

void loop() {

  give10();
  give20();
  give50();
  
}

void give10() {
    while (var10 != 0) {
    stepper10.step(steps);
    var10--;
    delay(pause);
  }
}

void give20() {
    while (var20 != 0) {
    stepper20.step(steps);
    delay(pause);
    var20--;
  }
}

void give50() {
    while (var50 != 0) {
    stepper50.step(steps);
    delay(pause);
    var50--;
  }
}
