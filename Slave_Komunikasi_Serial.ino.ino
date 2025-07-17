#include <SoftwareSerial.h>

SoftwareSerial Serial1(10, 9); // RX, TX

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.begin(9600);
    Serial1.begin(9600);
}

void loop() {
    if (Serial1.available() > 0) {
        char received = Serial1.read();

        if (received == '1') {
            digitalWrite(LED_BUILTIN, LOW);
        } else if (received == '2') {
            digitalWrite(LED_BUILTIN, HIGH);
        }
    }
}