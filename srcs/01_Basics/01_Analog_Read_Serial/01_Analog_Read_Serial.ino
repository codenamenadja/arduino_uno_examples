int sensor_value;

void setup() {
    // init serial commu at 9600 bits per sec.
    Serial.begin(9600);
}

void loop() {
    sensor_value = analogRead(A0);
    Serial.println(sensor_value);
}
