#define LS 2
#define RS 3
#define LM1 9
#define LM2 8
#define RM1 5
#define RM2 4
#define IR_LED 7
#define LEDPIN 13

void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(IR_LED, OUTPUT);
  digitalWrite(IR_LED, HIGH); 
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, HIGH);
}

void loop() {
  bool leftSensor = digitalRead(LS);
  bool rightSensor = digitalRead(RS);

  if (leftSensor && rightSensor) {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    digitalWrite(LEDPIN, HIGH);
  } 

  else if (leftSensor && !rightSensor) {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  } 

  else if (!leftSensor && rightSensor) {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  } 

  else {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}
