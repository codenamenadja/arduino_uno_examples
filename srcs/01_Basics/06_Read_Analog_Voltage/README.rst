Read Analog Voltage
===================

how to read an analog input on analog pin 0,
convert values from ``analogRead()`` into voltage.
and print it out to serial monitor of Arduino Software.

Hardware Required
-----------------

   - Arduino
   - 10K ohm potentiometer

Circuit
-------

   1. Connect the three wires from potentiometer to board.

      - first gose ground.
      - second gose to 5V from outer left pin.
      - last pin in the middle to analog input 0.

   #. when resistances are reversed, the voltage at center pin nears 0V, or ground. this voltage is the analog volatage reading as an input.
   #. microcontroller of the board has a circuit inside called an ADC(analog to digital converter) that reads this changing volatege and 
      converts it to a number 0~1023 that is proportional to amount of voltage being applied to the pin.

Code
----
