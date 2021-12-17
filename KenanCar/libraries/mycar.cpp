#include <Arduino.h>

int LeftAn = 11;
int LeftDig = 9;
int RightAn = 10;
int RightDig = 13;
int LeftDat = 5;
int RightDat = 6;
int flag = 0;

void setupCar() {
  pinMode(LeftAn, OUTPUT);
  pinMode(RightAn, OUTPUT);
  pinMode(LeftDig, OUTPUT);
  pinMode(RightDig, OUTPUT);
  pinMode(LeftDat, INPUT);
  pinMode(RightDat, INPUT);
}

void Left(int speed) { //Налево
  analogWrite(LeftAn, 0);
  analogWrite(RightAn, speed);
  digitalWrite(RightDig, HIGH);
}

void Right(int speed) { //Направо
  analogWrite(LeftAn, speed);
  analogWrite(RightAn, 0);
  digitalWrite(LeftDig, HIGH);
}

void Front(int speed) { //Прямо
  analogWrite(LeftAn, speed);
  analogWrite(RightAn, speed);
  digitalWrite(LeftDig, HIGH);
  digitalWrite(RightDig, HIGH);
}

void CheckLines() {
  Front(160);

  if (((digitalRead(LeftDat) == HIGH) && (digitalRead(RightDat) == LOW)))
  {
  flag = 1;
  Left(150);
  }

  if ((((digitalRead(LeftDat) == LOW) && (digitalRead(RightDat) == LOW)) && (flag == 1)))
  {
  Left(150);
  }

  if (((digitalRead(LeftDat) == LOW) && (digitalRead(RightDat) == HIGH)))
  {
  flag = 2;
  Right(150);
  }

  if (((digitalRead(LeftDat) == LOW) && (digitalRead(RightDat) == LOW)) && (flag == 2))
  {
  Right(150);
  }
}
