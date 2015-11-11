/****************************************
Please connect input A to digital pin 2, B to 3, and C to 4.
It will run through each of the 8 logic combos and light up the 
on-board led if the breadboard led should be on. 
****************************************/

#define ledPin 13
#define aPin 2
#define bPin 3
#define cPin 4
int delay_time = 3000;

void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(aPin, OUTPUT);
pinMode(bPin, OUTPUT);
pinMode(cPin, OUTPUT);
}

void loop() {
//for logic statement: AC' + A'C + AB'C
for(int i = 0; i < 8; i++){
      int a = bitRead(i, 0);
      int b = bitRead(i, 1);
      int c = bitRead(i, 2);
      Serial.println(String(c) + String(b) + String(a));
      if((a =! b) || (a == b && a != c)) {
        digitalWrite(ledPin, HIGH);
      }
      digitalWrite(aPin, a);
      digitalWrite(bPin, b);
      digitalWrite(cPin, c);
      delay(delay_time);
      sw();
    }
}

void sw() {
  digitalWrite(ledPin, LOW);
  delay(150);
  digitalWrite(ledPin, HIGH);
  delay(150);
  digitalWrite(ledPin, LOW);
}

