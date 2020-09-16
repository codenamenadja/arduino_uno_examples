const char led_p = 2;
const char button_p = 3;

unsigned int toggle_state;
unsigned int last_button_state;
unsigned int button_state;
long unsigned int last_pressed;
const long unsigned int debounce_t = 200;

void stat()
{
    Serial.print("last_button state: ");
    Serial.print(last_button_state, DEC);
    Serial.print("\t");
    Serial.print("curr_button state: ");
    Serial.print(button_state, DEC);
    Serial.print("\n");
}

void setup() {
    toggle_state        = 0;
    last_button_state   = 0;
    last_pressed        = millis();

    pinMode(led_p, OUTPUT);
    pinMode(button_p, INPUT_PULLUP);

    Serial.begin(9600);
}

void loop() {
    if ((millis() - last_pressed) > debounce_t) // time between pressings. easy to say, function loop if specific time passed.
    {
        button_state        = digitalRead(button_p);

        if (!button_state == last_button_state)
            return 0;

        last_pressed        = millis();
        if (!button_state && !last_button_state) // pullup so, pressed -> 0, !0 is 1. means pressed.
        { 
            toggle_state    = !toggle_state; // if not initialized its 0 in arduino architechture.
            digitalWrite(led_p, toggle_state);
        }
        /*
        if (button_state && !last_button_state) // press in
            digitalWrite(led_p, toggle_state);
        */
        stat();
        last_button_state   = !last_button_state;
    }
}
