Blink
=====

shows the simpliest thing youcan do with an arduino to see physical output:
blinks the on-board LED.

Hardware Required
-----------------

   - Arduino
   - LED
   - 220 ohm resistor

Circuit
-------

   uses built-in LED that most Arduino bpards have.
   This LED is connected to digital pin and its number may vary from board type to board type.
   To make life easier, we have a constant taht specified in every board descriptor file.
   this constant is *LED_BUILTIN* and allows you to control the built-in LED easily.
   Here is correspondence between the constant and digital pin.::

      - D13     - 101
      - D13     - Due
      - D1      - Gemma
      - D13     - Intel Edison
      - D13     - Intel Galileo Gen2
      - D13     - Leonardo and Micro
      - D13     - LilyPad
      - D13     - LilyPad USB
      - D13     - MEGA2560
      - D13     - Mini
      - D13     - MKR1000
      - D13     - Nano
      - D13     - Pro
      - D13     - Pro Mini
      - D13     - UNO
      - D13     - Yun
      - D13     - Zero

   if want to lit an External LED with this sketch, Build this circuit, 
   where you connect one end of the resistor to the digital pin correspondent to the *LED_BUILTIN* constant.::
   
      1. Connect the Long leg of the LED(positive leg, called anode) to the other end of the resistor.
      #. Connect the short leg of the LED(negative leg, called cathode) to the GND/

   The value of resistor in series with LED may be different value than 220 ohml
   the LED will lit up also with values up to 1k ohm.

Code
----

   After you build circuit plug your Arduino into your computer, start ide and entehr code below
   first this you do is to initialize LED_BUILTIN pin as an output pin with the line.::

      ``pinMode(LED_BUILTIN, OUTPUT);``

   in the main loop, you turn LED on with line::

      ``digitalWrite(LED_BUILTIN, HIGH);``

   This supplies 5V to LED anode. that creates a voltage difference across the pins of LED,
   and lights it up. then you turn it off with the line::

      ``digitalWrite(LED_BUILTIN, LOW);``

   takes the LED_BUILTIN pin back to 0V. and turns LED off.
   in between on and off, you want enough time for a person to see the change,
   so the ``delay()`` commands tell the board to do nothing for 1000 milliseconds.

