/****************************************
Please connect input A to digital pin 2, B to 3, and C to 4.
It will run through each of the 8 logic combos and light up the 
on-board led if the breadboard led should be on. 
****************************************/

#define ledPin 13
#define aPin 2
#define bPin 3
#define cPin 4
int delay_time = 1500;

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
      int c = bitRead(i, 0);
      int b = bitRead(i, 1);
      int a = bitRead(i, 2);
      Serial.println(String(a) + String(b) + String(c));
      if(a != c) {
        digitalWrite(ledPin, HIGH);
      }
      if((a == c && a == 1) && b == 0) {
        digitalWrite(ledPin, HIGH);
      }
      digitalWrite(aPin, a);
      digitalWrite(bPin, b);
      digitalWrite(cPin, c);
      delay(delay_time);
      sw();
    }
while(true) {
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(50);              // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(50);              // wait for a second
}
}

void sw() {
  digitalWrite(ledPin, LOW);
  delay(150);
  digitalWrite(ledPin, HIGH);
  delay(150);
  digitalWrite(ledPin, LOW);
}
