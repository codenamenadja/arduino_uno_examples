Digital Read Serial
===================

This examples shows you howto monitor the state of a switch by establishing *serial commuication* between 
your arduino and your computer over USB.

Hardware Required
-----------------

   - Arduino
   - momentary switch, button
   - 10k ohm resistor
   - hook-up wires
   - breadboard

Circuit
-------

   1. connect three wires to board. red and black, connect to two long vertical rows 
      on the side of the breadboard to provide access to 5V supply and ground.
   #. Third wire gose from *digital pin 2* to one leg of the push button.
   #. That same leg of the button connects through a pull-down resistor(10Kohm) to ground,
   #. The other leg of the button connects to 5V supply.
   #. button connect two points in circuit.
   
      - when unpressed, no connection between two legs of button. so, pin is connected to ground(through pulldown resistor) and reads 0.
      - when pressed, makes connection between two legs, connection pin to 5V, so pin reads as 1.

   .. note::

      만약 digital i/o핀을 해제하면, LED는 이상하게 blink할 것이다. 
      이것은 input이 "floating"하기 때문인데,
      이는, 전압이 GROUND등에 대해 분명한 연결이 없다면, Randomly return 1 or 0이다.
      이것이 왜 pull-down resistor가 필요한 이유이다.

Code
----



