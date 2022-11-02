
#include <Servo.h>
#define trigPin 7
#define echoPin 6
#define RELAY 3
Servo servoini;
int sound = 250;

void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(RELAY, OUTPUT);
servoini.attach(8);
}
void loop() {
digitalWrite(RELAY, LOW);
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 10) {
Serial.println("the distance is less than 10");
digitalWrite(RELAY, HIGH);
delay(1000);

int sudut = 0;
    for (sudut = 0; sudut <= 90; sudut += 1)
    {
      servoini.write(sudut);
      delay(15);
    }
    delay(5000);
    for (sudut = 90; sudut >= 0; sudut -= 1)
    {
      servoini.write(sudut);
      delay(15);
    }
}
else {
servoini.write(0);
}
if (distance > 60 || distance <= 0){
Serial.println("The distance is more than 60");
}
else {
Serial.print(distance);
Serial.println(" cm");
}
delay(500);
}
