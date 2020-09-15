ANALOG READ SERIAL
==================

How to read analog input from the physical world using potentiometer.

*potentiometer* is a simple mechanical divice that provides a varying amount of resistance when its shaft is turned.
by passing voltage through a potentiometer and into an analog input on your board,
it its possible to measure the amount of resisance produced by potentiometer as an analog value.
in this example you will monitor the state of your potentiometer after establishing serial communication between arduino and running arduino software.

Hardware Required
-----------------

- Arduino or Genuino Board
- 10k ohm Potentiometer

Circuit
-------

- 5V    = I * 10000ohm
- I     = 5V / 10000ohm
- I     = 0.5milliamps

