int potenciometro = 0;
#include <Servo.h>
Servo servomotor;
int Map;

Asi quedaría esta parte del código:

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  servomotor.attach(13);
}

void loop()
{
  Map = map(potenciometro, 0, 107, 93, 180);
  potenciometro = analogRead(A0);
  servomotor.write(Map);
  Serial.println(potenciometro);
}