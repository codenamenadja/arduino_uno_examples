const int data_p = 6;
const int clock_p = 7;
const int latch_p = 8;

byte led_map = 0b11110000;
int delay_t = 3000;

void shiftWrite(byte value);

void setup() {
    pinMode(data_p, OUTPUT);
    pinMode(clock_p, OUTPUT);
    pinMode(latch_p, OUTPUT);

    Serial.begin(9600);
    shiftWrite(0x00);
    Serial.println("Enter a number between 0-255");

}

void loop() {
    if (Serial.available())
    {
        int input_val = Serial.parseInt();

        if (input_val > 255)
            return;

        Serial.print("Decimal: ");
        Serial.println(input_val, DEC);
        Serial.print("BINaRY: ");
        Serial.println(input_val, BIN);
        Serial.println();

        Serial.print("AND RESULT: ");
        Serial.println(led_map & input_val);
        shiftWrite(led_map & input_val);
        delay(delay_t);
        Serial.println();

        Serial.print("OR RESULT: ");
        Serial.println(led_map | input_val);
        shiftWrite(led_map | input_val);
        delay(delay_t);
        Serial.println();

        Serial.print("XOR RESULT: ");
        Serial.println(led_map ^ input_val);
        shiftWrite(led_map ^ input_val);
        delay(delay_t);
        Serial.println();

        Serial.print("OR RESULT: ");
        Serial.println(led_map | input_val);
        shiftWrite(led_map | input_val);
        delay(delay_t);

    }
}

void shiftWrite(byte value)
{
    digitalWrite(latch_p, LOW);
    shiftOut(data_p, clock_p, MSBFIRST, value);
    digitalWrite(latch_p, HIGH);
}
