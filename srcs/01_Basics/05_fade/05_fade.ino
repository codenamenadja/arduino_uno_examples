const int ledpin = 9;

void setup() {
}

void loop() {
    unsigned char brightness;
    char fadeAmount;
   
    brightness = 0;
    fadeAmount = 5;

    while (brightness != 255)
    {
        analogWrite(ledpin, brightness);
        brightness += fadeAmount;
        delay(15);
    }
    analogWrite(ledpin, brightness);
    delay(15);
    fadeAmount = ~fadeAmount + 1;
    while (brightness)
    {
        brightness += fadeAmount;
        analogWrite(ledpin, brightness);
        delay(10);
    }
}
