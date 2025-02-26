#define CH1 2  // Receiver Right/Left
#define CH2 3  // Receiver Forward/Backward
#define IN1 4  // Motor A Input 1
#define IN2 5  // Motor A Input 2
#define IN3 6  // Motor B Input 1
#define IN4 7  // Motor B Input 2
#define ENA 9  // Speed Control Motor A
#define ENB 10 // Speed Control Motor B

int ch1Value, ch2Value;
int speedA, speedB;

void setup() {
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600); // Debugging
}

void loop() {
  ch1Value = pulseIn(CH1, HIGH, 25000); // Read PWM from CH1
  ch2Value = pulseIn(CH2, HIGH, 25000); // Read PWM from CH2

  if (ch1Value == 0 || ch2Value == 0) {
    Serial.println("No signal detected!");
    return;
  }

  int x = map(ch1Value, 1000, 2000, -255, 255); // Right/Left
  int y = map(ch2Value, 1000, 2000, -255, 255); // Forward/Backward

  speedA = constrain(abs(y + x), 0, 255);
  speedB = constrain(abs(y - x), 0, 255);

  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);

  // Control motor direction
  if (y > 50) { // Forward
    moveMotors(HIGH, LOW, HIGH, LOW);
  } else if (y < -50) { // Backward
    moveMotors(LOW, HIGH, LOW, HIGH);
  } else if (x > 50) { // Right
    moveMotors(HIGH, LOW, LOW, HIGH);
  } else if (x < -50) { // Left
    moveMotors(LOW, HIGH, HIGH, LOW);
  } else { // Stop
    moveMotors(LOW, LOW, LOW, LOW);
  }

  Serial.print("CH1: "); Serial.print(ch1Value);
  Serial.print(" | CH2: "); Serial.print(ch2Value);
  Serial.print(" | SpeedA: "); Serial.print(speedA);
  Serial.print(" | SpeedB: "); Serial.println(speedB);

  delay(20);
}

void moveMotors(int m1, int m2, int m3, int m4) {
  digitalWrite(IN1, m1);
  digitalWrite(IN2, m2);
  digitalWrite(IN3, m3);
  digitalWrite(IN4, m4);
}
