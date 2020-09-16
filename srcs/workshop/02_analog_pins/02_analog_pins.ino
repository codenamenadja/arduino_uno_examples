const char LP_p = 3;
const char LP_b = 5;
const char PP = A0;

unsigned int p_value;
unsigned char brt;


void setup() {
    Serial.begin(9600);
    pinMode(LP_p, OUTPUT);
    pinMode(LP_b, OUTPUT);
    pinMode(PP, INPUT);
}

void stat_led(void)
{
    Serial.print("bright: ");
    Serial.print(brt, DEC);
    Serial.print('\t');
    Serial.print("Duration: ");
    Serial.println(p_value, DEC);
    Serial.print('\n');
}

void loop() {
    p_value = analogRead(PP);
    brt = p_value / 4;
    analogWrite(LP_b, brt);
    digitalWrite(LP_p, HIGH);
    stat_led();
    delay(p_value);

    p_value = analogRead(PP);
    brt = p_value / 4;
    analogWrite(LP_b, brt);
    digitalWrite(LP_p, LOW);
    stat_led();
    delay(p_value);

    Serial.print('\n');
}
