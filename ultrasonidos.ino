const int Trigger = 3;
const int Echo = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  digitalWrite(Trigger, LOW);
}

void loop()
{
  long t; 
  long d; 
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(2);       
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH); 
  d = t/59;
  Serial.print("Distancia: ");
  Serial.print(d);    
  Serial.print("cm");
  Serial.println();
  delay(100);      
}
