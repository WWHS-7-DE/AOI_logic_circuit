/****************************************
Please connect input A to digital pin 2, B to 3, and C to 4.
It will run through each of the 8 logic combos and light up the 
on-board led if the breadboard led should be on. 
****************************************/

#define ledPin 13
#define aPin 2
#define bPin 3
#define cPin 4

void setup() {
int delay_time = 3000;
pinMode(ledPin, OUTPUT);
pinMode(aPin, OUTPUT);
pinMode(bPin, OUTPUT);
pinMode(cPin, OUTPUT);
}

void loop() {
//for logic statement: AC' + A'C + AB'C
for(int a = 0; a < 2; a++)
  for(int b = 0; b < 2; b++)
    for(int c = 0; c < 2; c++) {
      if((a =! b) || (a == b && a != c)) {
        digitalWrite(ledPin, HIGH);
      }
      pinMode(aPin, a);
      pinMode(bPin, b);
      pinMode(cPin, c);
      delay(delay_time);
      switch();
    }
}

void switch() {
  digitalWrite(ledPin, LOW);
  delay(150);
  digitalWrite(ledPin, HIGH);
  delay(150);
  digitalWrite(ledPin, LOW);
}

