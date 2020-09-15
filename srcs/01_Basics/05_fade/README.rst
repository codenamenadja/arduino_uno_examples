Fade
====

This example demonstrates the use of ``analogWrite()`` function in fanding an LED off and on.
AnalogWrite uses *Pulse width modulation*, turning a digital pin on and off very quickly with
different ratio between on and off, to create a fading effect.

Hardware Required
-----------------

   - arduino
   - LED
   - 220ohm resistor
   - hookup wires
   - breadboard

Circuit
-------

   connect the anode(positive road) of LED to digital pin 9 on your board through a 220 ohm
   resistor.  Connect the cathod(positive road) directly to ground.

Code
----

   1. Declare a pin 9 with ``ledpin``. then nothing to do in setup().
   #. ``analogWrite()`` func that you will be using in the main loop requires two argument,

      - which pin to write to.
      - indicating what PWM value to write. 

   #. to fade LED on and off, gradually increase PWM value from 0 to 255.
   #. then back to 0 once again to complete cycle.
   #. in sketch, PWM value is set using variable named ``brightness``.
   #. if brightness is at either extreme of its value(0 or 255), then ``fadeAmount`` is changed to its negative.
   #. it means, if ``fadeAmount`` is 5, then is set to -5. if -5 then vise versa.
   #. ``ananlogWrite()`` can chage the PWM value very fast, so delay at the end of the sketch contrls the
      speed of fade.

