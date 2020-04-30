// incorporate an analogue dial
// to display [0-9] on the single digit LCD 
// 5101AS

const int a = 7;  //middle -
const int b = 9;  //topleft |
const int c = 10; //top -
const int d = 11; //topright |
const int e = 4;  //bottomleft |
const int f = 5;  //bottom -
const int g = 3;  //bottomright |
const int h = 8;  // works. as pin 8 only

const int potPin = A0; // to read analogue dial
int digit = 0;
int prvdigit = 0; // helper. if previous number same, turnOff

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);  //.

  Serial.begin(9600);
  Serial.println("Starting val reads");
}


void displayDot() {
  digitalWrite(h, HIGH);
}


void turnOffDot() {
  digitalWrite(h, LOW);
}


void displayDigit(int digit) {
  //Conditions for displaying segment a
  if(digit!=1 && digit!=7 && digit!=0)
    digitalWrite(a,HIGH);
 
  //Conditions for displaying segment b
  if(digit!=1 && digit!=2 && digit!=3)
    digitalWrite(b,HIGH);
 
  //Conditions for displaying segment c
  if(digit!=1 && digit!=4)
    digitalWrite(c,HIGH);
 
 //Conditions for displaying segment d
  if(digit!=6 && digit!=5){
    digitalWrite(d,HIGH);
  }
  //Conditions for displaying segment e 
  if(digit==2 || digit==6 || digit==8 || digit==0){
    digitalWrite(e,HIGH);  
  }

 //Conditions for displaying segment f
 if(digit!=1 && digit!=4 && digit!=7 && digit!=9){
   digitalWrite(f, HIGH);
 }
 if(digit==0){
   digitalWrite(f,HIGH);
 } 
 
 //Condition for g
 if (digit!=2) {
  digitalWrite(g,HIGH);
 }
 if(digit==2){
  digitalWrite(g,LOW);
 }
}

void turnOff() {
  // turn off all but the dot
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

int analogDigit(int analogPin){
  // reads analogue pin 
  // and converts to appropriate [0-9]
  // some lazy edgecase error so 9 will
  // only be 1.24X as wide as the rest.
  int dial = analogRead(analogPin);
  float val = (float)dial / 1023. * 10.;
  if (val>=10.){
    val = 9;
  }
  return (int)val;

}
void loop() {
  //val = analogRead(potPin); // dial input
  digit = analogDigit(potPin); // ADC

  delay(1000);
  if (digit != prvdigit){
    turnOff();
    displayDigit(digit);
    prvdigit = digit;
  }
  delay(100);
}
