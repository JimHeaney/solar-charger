#include <Servo.h>

Servo myservo;

int pos = 128;
int ButtonState = 0;
int Pressed = 0;
int Down = 0;
int Up = 0;
int PhotoDelta = 0;
int Stationary = 0;
float Voltage = 0;
int travel = 0;
int delta = 10;

const int servo = 13;
const int PhotoDown = A0;
const int PhotoUp = 01;
const int Button = 13;
const int Blue = 9;
const int Green = 10;
const int Red = 11;
const int Voltmeter = A6;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

myservo.attach(3);
pinMode(Button, INPUT);
pinMode(Blue, OUTPUT);
pinMode(Green, OUTPUT);
pinMode(Red, OUTPUT);
pinMode(Voltmeter, INPUT);
pinMode(PhotoDown, INPUT);
pinMode(PhotoUp, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

ButtonState = digitalRead(Button);

Up = 0;
Down = 0;
Stationary = 0;

PhotoDelta = analogRead(PhotoUp) - analogRead(PhotoDown);

Serial.println("");
Serial.print("PhotoDelta: ");
Serial.println(PhotoDelta);

if (PhotoDelta < -50){
  Down = 1;
  Up = 0;
  Stationary = 0;
  Serial.println("Moving Down");
}

if (PhotoDelta >delta){
  Down = 0;
  Up = 1;
  Stationary = 0;
  Serial.println("Moving Up");
}

if ((PhotoDelta > -50) && (PhotoDelta <delta)){
  Down = 0;
  Up = 0;
  Stationary = 1;
  Serial.println("Not Moving");
}

if ((Pressed == 0) && (ButtonState == 1)){
  Pressed = 1;
}

if ((Pressed == 1) && (ButtonState == 0)){
  Serial.println("Button Released");
  Pressed = 0;
  pos = 128;
  myservo.write(pos);
  travel = 1;
  PhotoDelta = analogRead(PhotoUp) - analogRead(PhotoDown);
  Serial.println("Calibrating...");
  while((PhotoDelta < -50) || (PhotoDelta >delta)){
       PhotoDelta = analogRead(PhotoUp) - analogRead(PhotoDown);
       Serial.print("PhotoDelta: ");
       Serial.println(PhotoDelta);
       if (travel == 0){
        pos++;
        Serial.println("Moving Up");
       }
       if (travel == 1){
        pos = pos - 1;
        Serial.println("Moving Down");
       }
       if (pos > 255){
        travel = 1;
        Serial.println("Setting Travel 1");
       }
       if (pos < 0){
        travel = 0;
        Serial.println("Setting Travel 0");
       }
       myservo.write(pos);
       Serial.print("Current pos: ");
       Serial.println(pos);
       delay(15);
  }
  Serial.println("Calibration Complete");
}


Voltage = analogRead(Voltmeter) * 0.02445;
Serial.print("Voltage: ");
Serial.println(Voltage);

if (Voltage < 5){
  digitalWrite(Red, LOW);
  digitalWrite(Blue, HIGH);
  digitalWrite(Green, HIGH);
}

if ((Voltage >= 5) && (Voltage <= 11)){
  digitalWrite(Red, HIGH);
  digitalWrite(Blue, LOW);
  digitalWrite(Green, HIGH);
}

if (Voltage > 11){
  digitalWrite(Red, HIGH);
  digitalWrite(Blue, HIGH);
  digitalWrite(Green, LOW);
}

if (Down == 1){
  pos = pos + 1;
  Serial.println("Down Move Confirmed");
  Serial.print("Current pos: ");
  Serial.println(pos);
}

if (Up == 1){
  pos = pos - 1;
  Serial.println("Up Move Confirmed");
  Serial.print("Current pos: ");
  Serial.println(pos);
}

if (pos < 0){
  pos = 0;
}

if (pos > 255){
  pos = 255;
}

myservo.write(pos);

delay(100++);

}
