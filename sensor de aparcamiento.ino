int trigger = 12;
int echo = 13;
int buzzer = 3;
const float sonido = 34300.0;
const float umbral1 = 25.0;
const float umbral2 = 15.0;
const float umbral3 = 5.0;
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
    alertas(distancia);
  }
 
}
 
 
void alertas(float distancia)
{
    if (distancia > umbral1)
  {
    servoMotor.write (93);
    tone(buzzer, 2000, 200);
    delay(500);
    }
 
  if (distancia < umbral1 && distancia >= umbral2)
  {
    servoMotor.write (distancia + 90.3);
    tone(buzzer, 2000, 200);
    delay(500);
  }
  else if (distancia < umbral2 && distancia > umbral3)
  {
    servoMotor.write (distancia + 90.3);
    tone(buzzer, 2500, 200);
    delay(189);
  }
  else if (distancia <= umbral3)
  {
    servoMotor.write (distancia + 90.3);
    tone(buzzer, 3000, 200);
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
