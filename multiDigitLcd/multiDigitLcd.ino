// 4-digit 7-segment 5461AS
// no purpose other than to fiddle

const int a = 4; // top -            pin 11 (bottom left is 1. going counter clockwise)
const int b = 5; // topright |       pin  7
const int c = 6; // topright |       pin  4
const int d = 7; // topright |       pin  2
const int e = 8; // topright |       pin  1
const int f = 9; // topright |       pin 10
const int g = 10; // topright |      pin  5
const int h = 11; // decimal point   pin  3

const int d4 = 3; // digit 4         pin  6
const int d3 = 2; // digit 3         pin  8
const int d2 = 1; // digit 2         pin  9
const int d1 = 0; // digit 1         pin 12

// some delay time
int dt = 500;


void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);  //.
  pinMode(d4, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d1, OUTPUT);

  turnOffDot(1);
  turnOffDot(2);
  turnOffDot(3);
  turnOffDot(4);  
}


void displayDot(int location) {
  switch (location){
    case 4:
      digitalWrite(d4, LOW);
      break;
    case 3:
      digitalWrite(d3, LOW);
      break;
    case 2:
      digitalWrite(d2, LOW);
      break;
    case 1:
      digitalWrite(d1, LOW);
      break;
  }
  digitalWrite(h, HIGH);
}


void displayDigit(int digit, int location){
  switch (location){
    case 4:
      digitalWrite(d4, LOW);
      break;
    case 3:
      digitalWrite(d3, LOW);
      break;
    case 2:
      digitalWrite(d2, LOW);
      break;
    case 1:
      digitalWrite(d1, LOW);
      break;
  }
  
  //Conditions for displaying segment a
  if(digit!=1 && digit!=4){
    digitalWrite(a,HIGH);
  }
  
  //Conditions for displaying segment b
  if(digit!=5 && digit!=6){
    digitalWrite(b,HIGH);
  }
  
  //Conditions for displaying segment c
  if(digit!=2){
    digitalWrite(c,HIGH);
  }
 //Conditions for displaying segment d
  if(digit!=1 && digit!=4 && digit!=7){
    digitalWrite(d,HIGH);
  }
  //Conditions for displaying segment e 
  if(digit==2 || digit==6 || digit==8 || digit==0){
    digitalWrite(e,HIGH);  
  }

  //Conditions for displaying segment f
  if(digit!=1 && digit!=2 && digit!=3){
    digitalWrite(f, HIGH);
  }
 
  //Condition for g
  if (digit!=7 && digit!=0 && digit!=1) {
    digitalWrite(g,HIGH);
  }
}


void turnOff() {
  // turn off all but the dot
  digitalWrite(d4, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d1, HIGH);
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);


}


void turnOffDot(int location) {
  switch(location){
    case 4:
      digitalWrite(d4, HIGH);
      digitalWrite(h, LOW);
      break;
    case 3:
      digitalWrite(d3, HIGH);
      digitalWrite(h, LOW);
      break;
    case 2:
      digitalWrite(d2, HIGH);
      digitalWrite(h, LOW);
      break;
    case 1:
      digitalWrite(d1, HIGH);
      digitalWrite(h, LOW);
      break;
  }
}


void loop() {
  turnOff();
  delay(1000);
  for(int i=1;i<5;i++){
    for(int j=9;j>-1;j--){
      displayDigit(j,i);
      delay(1000);
      turnOff();
      delay(200);
    }
  }
}
