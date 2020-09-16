01_pullup
---------

   .. note::

      inputpullup with nothing means 1 so, wire should buttoned to GND!


02_analog_pins
--------------

Voltage divider (Potentiometer)::

   - 10k to 0ohm
   - mid line to ananlog input will receive voltage from anode of potentiometer

Analog input
^^^^^^^^^^^^

   - Analog input takes real volatage and recongnize as corresponding 0 ~ 1023 value.(1023 unsigned 10bit max)

Digital_with DAC (digital analog converter)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

   - DAC values max is 8 bits. (0 ~ 255), ``AnalogWrite`` with DAC writes out max 255.

2 Very important components::

   - judy cycle
   - Frequency

03_Using_serial_monitor
^^^^^^^^^^^^^^^^^^^^^^^



