#include <Wire.h>
#include <LiquidCrystal_I2C.h>

byte x = 0;
char addr = 0;
char error = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Wire.begin(); // join i2 bus.
    while (++addr < 127)
    {
        Wire.beginTransmission(addr);
        if (!(error = Wire.endTransmission()))
            break;
    }
    if (addr == 127)
        while(1);
    lcd.init();
    delay(3000);
}


void loop() {
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(3,0);
    lcd.print("Hello, world!");
    delay(1000);
    lcd.setCursor(2,1);
    lcd.print("Ywrobot Arduino!");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("Arduino LCM IIC");
    delay(1000);
    lcd.setCursor(2,3);
    lcd.print("Power By Ec-yuan!");
    delay(1000);
}
