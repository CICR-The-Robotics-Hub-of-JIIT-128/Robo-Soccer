double ch1;
double ch2;

int a = 4;
int b = 5;
int c = 6;
int d = 7;

void setup() {
  //Baud Rate
  Serial.begin(9600);

  pinMode(2, INPUT);
  pinMode(3, INPUT);

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
}

void loop() {
  ch1 = pulseIn(2, HIGH);
  ch2 = pulseIn(3, HIGH);

  //STOP
  if (ch1 > 1400 && ch1 < 1500 && ch2 > 1400 && ch2 < 1500) {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
  } 
  else if (ch1 == 0 && ch2 == 0 ) {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
  } 
  //left
  else if (ch2 > 1750 ) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    delay(100); 
  } 
  //right
  else if (ch2 < 1250) {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    delay(100); 
  } 
  //backward
  else if (ch1 > 1750) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    delay(0); 
  } 
  //forward
  else if (ch1 < 1250 ) {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    delay(0); 
  } else {
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
  }
}
