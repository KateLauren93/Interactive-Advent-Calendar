#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;
const int servo1Pin =  9;
const int servo2Pin =  10;
const int servo3Pin =  11;

// variables will change:
int buttonState = 0; // variable for reading the pushbutton status
int buttonPressed = 0; // variable to remember the previous state of the button (make sure they have let go of the button)
int pos = 0; // variable to store the servo position
int servo = 0; // variable for the servo loop


void setup() {
  pinMode(buttonPin, INPUT);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    if (buttonPressed == 0) {
      buttonPressed = 1;
      
      servo++;
      if (servo == 3) {
        servo = 0;
      }
      
      switch(servo) {
        case 0:
        servo1.write(0);
        servo2.write(0);
        servo3.write(0);
        break;
        
        case 1:
        servo1.write(90);
        servo2.write(0);
        servo3.write(0);
        break;
        
        case 2:
        servo1.write(0);
        servo2.write(90);
        servo3.write(0);
        break;
        
        case 3:
        servo1.write(0);
        servo2.write(0);
        servo3.write(90);
        break;
      }
    }
  }
  else {
    buttonPressed = 0;
  }
}
