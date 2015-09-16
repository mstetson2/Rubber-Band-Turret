/*To control the direction of the motor, the pins in1 and in2 must be set to opposite values.
If in1 is HIGH and in2 is LOW, the motor will spin one way, if on the other hand in1 is HIGH
and in2 LOW then the motor will spin in the opposite direction.
The '!' command means 'not'. So the first digitalWrite command for in1 sets it to the opposite
of whatever the value of 'reverse' is, so if reverse is HIGH it sets it to LOW and vice versa.
The second digitalWrite for 'in2' sets the pin to whatever the value of 'reverse' is. This means
that it will always be the opposite of whatever in1 is.
 */

const int enableMotorX = 12;
const int in1MotorX = 11;
const int in2MotorX = 10;
const int enableMotorY = 9;
const int in1MotorY = 8;
const int in2MotorY = 7;
//fireMotor -> 6
const int xButton1 = 5;
const int xButton2 = 4;
const int yButton1 = 3;
const int yButton2 = 2;
const int fireButton = 1;
const int led = 13;

int xButton1State = 0;
int xButton2State = 0;
int yButton1State = 0;
int yButton2State = 0;
int fireButtonState = 0;

int speed = 200;

//0=left, 1=off, 2=right
int xMotor = 1;
//0=down, 1=off, 2=up
int yMotor = 1;
//false=idle, true = firing
boolean fire = false;

void setup() {

  Serial.begin(9600);

  pinMode(enableMotorX, OUTPUT);
  pinMode(in1MotorX, OUTPUT);
  pinMode(in2MotorX, OUTPUT);
  pinMode(enableMotorY, OUTPUT);
  pinMode(in1MotorY, OUTPUT);
  pinMode(in2MotorY, OUTPUT);
  pinMode(xButton1, INPUT_PULLUP);
  pinMode(xButton2, INPUT_PULLUP);
  pinMode(yButton1, INPUT_PULLUP);
  pinMode(yButton2, INPUT_PULLUP);
  pinMode(fireButton, INPUT_PULLUP);
  pinMode(6, OUTPUT); //turret motor
  pinMode(led, OUTPUT);


}

void loop() {

  xButton1State = digitalRead(xButton1);
  xButton2State = digitalRead(xButton2);
  yButton1State = digitalRead(yButton1);
  yButton2State = digitalRead(yButton2);
  fireButtonState = digitalRead(fireButton);

  // readButtons();
  //  setXMotor();
  //  setYMotor();

  boolean xMotor1 = xButton1State;
  boolean xMotor2 = xButton2State;

  boolean yMotor1 = yButton1State;
  boolean yMotor2 = yButton2State;

  if ((xButton1State == LOW || xButton2State == LOW) && (xButton1State != xButton2State)) {
    if (xButton1State == LOW) {
      setMotorX(speed, xMotor1);
    }

    if (xButton2State == LOW) {
      setMotorX(speed, xMotor1);
    }
  }
  else {
    analogWrite(enableMotorX, 0);
  }

  if (yButton1State == LOW || yButton2State == LOW) {
    if (yButton1State == LOW) {
      setMotorY(speed, yMotor1);
    }

    if (yButton2State == LOW) {
      setMotorY(speed, yMotor1);
    }
  }
  else {
    analogWrite(enableMotorY, 0);
  }

  fireTurret();

}

void setMotorX(int speed, boolean xMotor1) {

  analogWrite(enableMotorX, speed);
  digitalWrite(in1MotorX, ! xButton1State);
  digitalWrite(in2MotorX, xButton1State);

}

void setMotorY(int speed, boolean yMotor1) {

  analogWrite(enableMotorY, speed);
  digitalWrite(in1MotorY, ! yButton1State);
  digitalWrite(in2MotorY, yButton1State);

}

void fireTurret() {
  if(fireButtonState == LOW) {
    analogWrite(6, 200);
  }
  else {
    analogWrite(6, 0);
  }
}




/*
void readButtons() {

  if (xButton1State == LOW && yButton2State == HIGH) {
    xMotor = 0;
  }
  else {
    xMotor = 1;
  }

  if (xButton2State == LOW && xButton1State == HIGH) {
    xMotor = 2;
  }
  else {
    xMotor = 1;
  }

  if (yButton1State == LOW && yButton2State == HIGH) {
    yMotor = 0;
  }
  else {
    yMotor = 1;
  }

  if (yButton2State == LOW && yButton1State == HIGH) {
    yMotor = 2;
  }
  else {
    yMotor = 1;
  }

  if (fireButtonState == LOW) {
    analogWrite(6, 100);
  }
  else {
    analogWrite(6, 0);
  }

}


void setMotorX(speed,

void setXMotor() {

  switch (xMotor) {

    case 0:
      analogWrite(enableMotorX, speed);
      digitalWrite(in1MotorX, 1);
      digitalWrite(in2MotorX, 0);
      break;

    case 1:
      digitalWrite(in1MotorX, 0);
      digitalWrite(in2MotorX, 0);
      break;

    case 2:
      analogWrite(enableMotorX, speed);
      digitalWrite(in1MotorX, 0);
      digitalWrite(in2MotorX, 1);
      break;
  }
}

void setYMotor() {

switch (yMotor) {

    case 0:
      analogWrite(enableMotorY, speed);
      digitalWrite(in1MotorY, 1);
      digitalWrite(in2MotorY, 0);
      break;

    case 1:
      digitalWrite(in1MotorY, 0);
      digitalWrite(in2MotorY, 0);
      break;

    case 2:
      analogWrite(enableMotorY, speed);
      digitalWrite(in1MotorY, 0);
      digitalWrite(in2MotorY, 1);
      break;
  }

}
*/
