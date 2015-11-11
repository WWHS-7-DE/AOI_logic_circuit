/****************************************
Please connect input A to digital pin 2, B to 3, C to 4, and the output to 0.
It will run through each of the 8 logic combos and light up the 
on-board led if the breadboard led should be on. This evaluates AC' + A'C + AB'C
****************************************/

#define ledPin 13
#define aPin 2
#define bPin 3
#define cPin 4
#define inPin 0
int delay_time = 5;
boolean on = false;
int errors = 0;

void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(aPin, OUTPUT);
pinMode(bPin, OUTPUT);
pinMode(cPin, OUTPUT);
}

void loop() {

  for(int i = 0; i < 8; i++){
      int c = bitRead(i, 0);
      int b = bitRead(i, 1);
      int a = bitRead(i, 2);
      if(a != c) 
        on = true;
      else if((a == c && a == 1) && b == 0)
        on = true;
      else
        on = false;
      digitalWrite(aPin, a);
      digitalWrite(bPin, b);
      digitalWrite(cPin, c);
      delay(delay_time);

      boolean boolin = digitalRead(inPin);
      Serial.println("Expected: " + String(on) + " and Receved: " + String(boolin));
      if(boolin != on) 
        errors++;
    }
    
  if(errors != 0)
    fail();
  else 
    pass();
}
void fail() {
  while(true) {
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
  }
}
void pass() {
  while(true) {
    digitalWrite(13, HIGH);
    delay(1000);
  }
}

