/*** START MOTORS ***/
const int motorIn1L = 27;
const int motorIn2L = 26;
const int motorEnL = 12;
const int motorIn1R = 32;
const int motorIn2R = 33;
const int motorEnR = 12;
int dir;

void left();
void right();
void forward();
void back();
void brake();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorIn1L, OUTPUT);
  pinMode(motorIn2L, OUTPUT);
  pinMode(motorEnL, OUTPUT);
  pinMode(motorIn1R, OUTPUT);
  pinMode(motorIn2R, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  dir = Serial.read().toInt();
  switch(dir) {
    case 1:
      left();
      break;
    case 2:
      right();
      break;
    case 3:
      forward();
      break;
    case 4:
      back();
      break;
    case 5:
      brake();
      break;
    default:
      brake();
      break;    
  }
  delay(100);
}

void left() {
  analogWrite(motorEnL, 200);
  analogWrite(motorEnL, 200);
  digitalWrite(motorIn1L, LOW);
  digitalWrite(motorIn2L, HIGH);
  digitalWrite(motorIn1R, HIGH);
  digitalWrite(motorIn2R, LOW);
}

void right() {
  analogWrite(motorEnL, 200);
  analogWrite(motorEnL, 200);
  digitalWrite(motorIn1R, LOW);
  digitalWrite(motorIn2R, HIGH);
  digitalWrite(motorIn1L, HIGH);
  digitalWrite(motorIn2L, LOW);
}

void forward() {
  analogWrite(motorEnL, 255);
  analogWrite(motorEnL, 255);
  digitalWrite(motorIn1L, HIGH);
  digitalWrite(motorIn2L, LOW);
  digitalWrite(motorIn1R, HIGH);
  digitalWrite(motorIn2R, LOW);
}

void back() {
  analogWrite(motorEnL, 200);
  analogWrite(motorEnL, 200);
  digitalWrite(motorIn1L, LOW);
  digitalWrite(motorIn2L, HIGH);
  digitalWrite(motorIn1R, LOW);
  digitalWrite(motorIn2R, HIGH);
}

void brake() {
  analogWrite(motorEnL, 0);
  analogWrite(motorEnL, 0);
  digitalWrite(motorIn1L, HIGH);
  digitalWrite(motorIn2L, HIGH);
  digitalWrite(motorIn1R, HIGH);
  digitalWrite(motorIn2R, HIGH);  
}

