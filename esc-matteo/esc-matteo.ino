#include <Servo.h>

char inByte[4];
int value;
String inputString = ""; 
// a String to hold incoming data
char motor;
bool stringComplete = false;  // whether the string is complete

Servo ESC1;
Servo ESC2;
Servo ESC3;
Servo ESC4;

int pos = 0;
int velocity=99;


void setSpeed(int val, int motor){
  if (motor ==1)
    ESC1.write(val);
  else if (motor ==2)
    ESC2.write(val);
  else if (motor ==3)
    ESC3.write(val);
  else if (motor==4)
    ESC4.write(val);
  else
    Serial.println("Motor undefined");
}

void arm(){ 
  setSpeed(0,1); //Sets speed variable delay(1000);
  setSpeed(0,2);
  setSpeed(0,3);
  setSpeed(0,4);
  }

void setup() {
  Serial.begin(9600);
  ESC1.attach(9);  // attaches the servo on pin 9 to the servo object
  ESC2.attach(10);
  ESC3.attach(11);
  ESC4.attach(6);
  arm();
  inputString.reserve(200);
}

void loop() {
  if (stringComplete) {
    value=inputString.toInt();
    inputString = "";
    Serial.print("PWM");
    Serial.print(value);
    Serial.print(", Motor: ");
    Serial.println(motor);
    stringComplete = false;
    if (value>=0 && value <=160) 
      setSpeed(value, motor-'0');
    else
      Serial.println("Value out ranges");
  }
}
