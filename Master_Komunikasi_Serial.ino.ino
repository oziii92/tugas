#include <SoftwareSerial.h>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.begin(9600);
    Serial1.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        char received = Serial.read();
        Serial1.write(received);

        if (received == '1') {
            digitalWrite(LED_BUILTIN, LOW);
        } else if (received == '2') {
            digitalWrite(LED_BUILTIN, HIGH);
        }
    }
}
