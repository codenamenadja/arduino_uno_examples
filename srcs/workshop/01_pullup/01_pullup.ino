int led_pin = 3;
int button_pin = 4;
int button_state;

void setup() {
    pinMode(led_pin, OUTPUT);
    Serial.begin(9600);
    pinMode(button_pin, INPUT_PULLUP);
}

void loop() {
    button_state = digitalRead(button_pin);
    Serial.println(button_state, BIN);
    digitalWrite(led_pin, button_state);
}
