#define LED_PIN 13
volatile bool triggered = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  digitalWrite(LED_PIN, LOW);

  cli(); // interupt off
  EICRA |= (1 << ISC11) | (1 << ISC10);
  EIMSK |= (1 << INT1);
  sei(); // interupt on

}

void loop() {
  if(triggered){
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    triggered = false;
  }

}

ISR(INT1_vect){
  triggered = true;
}