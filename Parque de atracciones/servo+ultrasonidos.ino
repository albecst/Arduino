int trigger = 12;
int echo = 13;
int buzzer = 4;
const float sonido = 34300.0;
const float umbral1 = 10.0;
# include <Servo.h>
Servo servoMotor;

void setup() {
  Serial.begin(9600); 
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  pinMode(buzzer, OUTPUT); 
  servoMotor.attach(11);
}
 
void loop() {
  iniciarTrigger();
  float distancia = calcularDistancia();
  if (distancia < umbral1)
  {
   servoMotor.write(180);
   tone(buzzer, 1000);
   delay(3600);
  }
 if (distancia > umbral1)
 {
   servoMotor.write(90);
   noTone(buzzer);
 }
}

float calcularDistancia()
{
  
  unsigned long tiempo = pulseIn(echo, HIGH);
 
  float distancia = tiempo * 0.000001 * sonido / 2.0;
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println();
  delay(500);
 
  return distancia;
}
 
void iniciarTrigger()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
}
