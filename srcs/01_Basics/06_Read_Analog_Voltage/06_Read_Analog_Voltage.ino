
void setup() {
    Serial.begin(9600);
}

void loop() {
    int sensor_value = analogRead(A0);
    float voltage = sensor_value * (5.0 / 1023.0);

    Serial.println(voltage);
}

