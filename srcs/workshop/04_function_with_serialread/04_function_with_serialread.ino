#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define findSide(x, y) (sqrt(x * x + y * y))

char    buf[3];
float   find_side(int x, int y);

void        setup() {
    Serial.begin(9600);
}

void        loop() {
    int     a;
    int     b;
    size_t  a_rc;
    //size_t  b_rc;
    float   result;
    
    Serial.print("Enter a side value");
    while (!Serial.available())
        continue;
    Serial.print(": ");

    memset(buf, 0, 8);
    while (!(a_rc = Serial.readBytes(buf, 7)))
        continue;
    Serial.println(buf);
    a = atoi(buf);
    Serial.print("Enter the other side value");
    while (!Serial.available())
        continue;
    Serial.print(": ");
    b = Serial.parseInt();
    Serial.println(b);
    result = find_side(a, b);
    Serial.println(result);
}

float       find_side(int x, int y)
{
    return findSide(x, y);
}
