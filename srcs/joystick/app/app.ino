#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <unistd.h>
#include <string.h>
#include "app.h"

void app_init();
void print_mod(int x, int y);
int move_mod(char n); 
size_t print_line(const char *str, int line);

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo motor;

void setup() {
    app_init();
}

void loop() {
    if (digitalRead(SW_PIN) == HIGH)
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("X:");
        print_mod(analogRead(X_PIN));
        lcd.setCursor(0, 1);
        lcd.print("Y:");
        print_mod(analogRead(Y_PIN));
        delay(50);
    } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("motor mode...");
        delay(600);
        lcd.clear();
        lcd.noBacklight();
        move_mod(X_PIN); 
        lcd.backlight();
    }
}

/*
** Custom functions
*/

int move_mod(char n)
{
    while (digitalRead(SW_PIN) == HIGH)
    {
        motor.write(map(analogRead(n), 0, 1023, 0, 179));
        delay(22);
    }
    delay(600);
    return (0);
}

size_t print_mod(int n)
{
    int     div;
    size_t  len;
    
    div = 1;
    len = 1;
    lcd.print(n);
    if (!n)
        n++;
    while ((div *= 10) <= n) 
       len++;
    return (len); 
}

void app_init()
{
    Serial.begin(9600);
    pinMode(SW_PIN, INPUT_PULLUP);
    pinMode(M_PIN, OUTPUT);
    lcd.init();
    motor.attach(M_PIN);
    delay(400);
}
