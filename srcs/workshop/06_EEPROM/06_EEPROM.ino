#include <EEPROM.h>

#define LEDPIN      13
#define BUTTONPIN   2

char button_state_l = 1;
int debounce_t      = 20;
int counter;
long unsigned int l_pressed;
int debounce(long unsigned int press_t);

void setup() {
    pinMode(LEDPIN, OUTPUT);
    pinMode(BUTTONPIN, INPUT_PULLUP);

    Serial.begin(9600);
    counter = EEPROM.read(0); // 1argument : Address(0 - 1023) to read.

    EEPROM.write(0, 0); // 2arguments : Address, value(0 - 255)
}

void loop() {
    int     button_state;

    if (!debounce(l_pressed))
        return;

    button_state = digitalRead(BUTTONPIN);
    l_pressed = millis();
    if (!button_state && button_state_l)
    {
        counter++;
        EEPROM.write(0, counter);
        digitalWrite(LEDPIN, HIGH);
        button_state_l = button_state;
        Serial.print("Counter: ");
        Serial.print(counter);
    } 
    if (button_state && !button_state_l)
    {
        button_state_l = button_state;
        digitalWrite(LEDPIN, LOW);
    }
}



int debounce(long unsigned int press_t)
{
    return ((millis() - press_t) > debounce_t);
}
