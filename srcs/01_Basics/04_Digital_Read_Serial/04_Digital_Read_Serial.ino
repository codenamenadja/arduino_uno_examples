int button;


void setup() {
    button = 2;
    Serial.begin(9600);
    pinMode(button, INPUT);
}

void loop() {
    int button_state;

    button_state = digitalRead(button);
    Serial.println(button_state);
    delay(1);
}
