#include <Console.h>
#define trigPin 7
#define echoPin 8
#define RedPin 10
#define GreenPin 11
#define BluePin 9

int red, green, blue;

void setup() {
  // Serial.begin(9600);
  Bridge.begin();
  Console.begin();
  while (!Console);
  pinMode(13, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);

}

void loop() {
  int red = 255;
  int blue = 255;
  int green = 255;
  int duration;
  float distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(25);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(200);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance >= 401 || distance <= 0) {
    Console.println("Out of range");
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
  }
  else {
    Console.print(distance);
    Console.println(" cm");
    if (distance >= 1 && distance <= 50) {
      analogWrite (RedPin, 0);
      analogWrite (GreenPin, 255);
      analogWrite (BluePin, 0);
      //Console.println("Od 1 do 50");
    }
    else if (distance >= 51 && distance <= 100) {
      analogWrite (RedPin, 0);
      analogWrite (GreenPin, 255);
      analogWrite (BluePin, 0);
      //Console.println("Od 51 do 100");
    }
    else if (distance >= 101 && distance <= 150) {
      analogWrite (RedPin, 0);
      analogWrite (GreenPin, 0);
      analogWrite (BluePin, 255);
      //Console.println("Od 101 do 150");
    }
    else if (distance >= 151 && distance <= 200) {
      analogWrite (RedPin, 0);
      analogWrite (GreenPin, 0);
      analogWrite (BluePin, 255);
      //Console.println("Od 151 do 200");
    }
    else if (distance >= 201 && distance <= 250) {
      analogWrite (RedPin, 255);
      analogWrite (GreenPin, 255);
      analogWrite (BluePin, 255);
     // Console.println("Od 201 do 250");
    }
    else if (distance >= 251 && distance <= 300) {
      analogWrite (RedPin, 255);
      analogWrite (GreenPin, 255);
      analogWrite (BluePin, 255);
      //Console.println("Od 251 do 300");
    }
    else {
      analogWrite (RedPin, 255);
      analogWrite (GreenPin, 0);
      analogWrite (BluePin, 0);
      //Console.println("vise od 300");
    }
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }
}

