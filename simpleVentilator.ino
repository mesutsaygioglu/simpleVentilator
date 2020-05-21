const int STEP = 10;
const int DIR = 11;
const int EN = 12;
int sSpeed = 25;
int speed_ = 1;
int direction_ = 1;
signed long nTime = micros();
signed long nSpeed = micros();
long rotationTime = 10000;
const int pot1    = A0; // Hız potansiyometresinin bağlı olduğu pin
const int pot2    = A1; // Zaman potansiyometresinin bağlı olduğu pin
signed long minimumTime = 1000; // Minimum süre ms bazında
signed long maximumTime = 5000; // Maksimum süre ms bazında
signed long minimumSpeed = 200; // Minimum hız adım bazında
signed long maximumSpeed = 10000; // Maksimum hız adım bazında

void setup() {
Serial.begin(9600);
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(DIR, HIGH);
  digitalWrite(EN, LOW);
}

void loop() {

  // Serial.println(micros());
  int val = analogRead(pot1);
  int val2 = analogRead(pot2);

  if (micros() - nTime > rotationTime)
  { 
    direction_ *= -1;
    nTime = micros();
  }

  if (micros() - nSpeed > sSpeed)
  { 
    speed_ *= -1;
    nSpeed = micros();
  }

  if (  rotationTime != map(val, 0, 1023, minimumTime, maximumTime) )
  {
     Serial.println("rotationTime: ");
     Serial.println(rotationTime);
    rotationTime = map(val, 0, 1023, minimumTime, maximumTime);
    rotationTime = rotationTime*1000;
  }

  if (  sSpeed != map(val2, 0, 1023, maximumSpeed, minimumSpeed) )
  {
     Serial.println("sSpeed: ");
     Serial.println(sSpeed); 
    sSpeed = map(val2, 0, 1023, maximumSpeed, minimumSpeed);
  }

  if (direction_ == 1)
    digitalWrite(DIR, LOW);
  if (direction_ == -1)
    digitalWrite(DIR, HIGH);
  if (speed_ == 1)
    digitalWrite(STEP, LOW);
  if (speed_ == -1)
    digitalWrite(STEP, HIGH);

}