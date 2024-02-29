# include <Servo.h>
Servo servoMotorIzq;
Servo servoMotorDer;
int LDRPinIzq = 0;
int LDRValor = 0;
int LDRPinDer = 1;
int LDRValor2 = 1;
int Amongus;
int Amongus2;

void setup()
{
  pinMode(LDRPinIzq,INPUT);
  pinMode(LDRPinDer, INPUT);
  servoMotorIzq.attach(2);
  servoMotorDer.attach(3);
  Serial.begin(9600);
}

void loop()
{ 
  LDRValor = analogRead(LDRPinIzq);
  LDRValor2 = analogRead(LDRPinDer);
  Amongus = map(LDRValor, 3, 450, 93, 180);
  Amongus2 = map(LDRValor2, 3, 450, 93, 180);
  Serial.println(LDRValor);
  delay(100);
  servoMotorIzq.write(Amongus);
  servoMotorDer.write(Amongus2);
}
