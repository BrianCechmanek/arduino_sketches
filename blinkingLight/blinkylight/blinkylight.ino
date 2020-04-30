int delay_value = 1000; 
int delay_value2= 300;
int delay_value3= 100;
int led_pin = 13;
 
void setup() { 
  pinMode(led_pin, OUTPUT);
}
 
 
void loop() { 
  digitalWrite(LED_BUILTIN, HIGH);
  delay(delay_value);
  digitalWrite(LED_BUILTIN, LOW);
  delay(delay_value2); 
  digitalWrite(LED_BUILTIN, HIGH);
  delay(delay_value2);
  digitalWrite(LED_BUILTIN, LOW);
  delay(delay_value); 
  digitalWrite(LED_BUILTIN, HIGH);
  delay(delay_value3);
  digitalWrite(LED_BUILTIN, LOW);
  delay(delay_value3);   
}
