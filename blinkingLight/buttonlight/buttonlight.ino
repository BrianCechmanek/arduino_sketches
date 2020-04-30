const int led_pin = 13;
const int button = 2;

int buttonState = 0;
int pressed = 0;

void setup() { 
  pinMode(led_pin, OUTPUT);
  pinMode(button, INPUT);
}
 
 
void loop() { 
  buttonState = digitalRead(button);

  if (buttonState == HIGH) {
    pressed = (pressed + 1) % 2;
    switch (pressed) {
      case 1:
          digitalWrite(led_pin, LOW);
          break;
      case 0:
          digitalWrite(led_pin, HIGH);
          break;
    }
    delay(500);    // need to slow looping else turns off immediately
  }
}
