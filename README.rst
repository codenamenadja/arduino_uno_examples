Intro
-----

Arduino programs canbe divided in three main parts

   - Structure
      consists with 2 main functions
         1. Setup() function
            called when a sketch starts.
            use it to initialize the variable, pinModes, start using libraries

             after each power up or reset of Arduino board, only run once
         2. Loop() function
            After creating a setup() function, loop() function dies precisely what its name suggersts.
            and loops consecutively.

   - Values(variables and constants)
   - Functions
   
I/O Functions
-------------

pins can configured as input or output.

.. note::

   very important to note that majority of Arduino analog pins.

arduino pins re default configured as input.
input pins make extremely small demands on circuit that they are sampling.
equivalent to series resistor of 100 megaohm in front of the pin.

this means that it takes very little current to switch the input pin from one state to another.
this makes the pins useful for such tasks as implementing a capacitive touch sensor or reading an LED as a photodiode.
pins report seemingly random changes in pin state, picking up electrical noise from environment, or coupling the state of a nearby pin.

Pull-up Resistors
-----------------

pull up resistors are often useful to steer an input pin to a known state
if no input is present.
this can be done by adding a pull-up resistor to +5V, or pull-down
resistor to ground on the input. 
a 10k resistor is good value for a pull-up or pull-down resistor.

*using Built-in Pull-Up resistor with Pins Configured as input*

there are 20000 pullup resistors built into the atmega chip that can be
accessed from software.
built-in pull up resistors are accessed by setting the pinMode() as
INPUT_PULLUP.
those effectively inverts the behavior of the INPUT mode.
where HIGH means sensor is OFF and LOW vise versa.
value of this pull-up depends on the microocontroller used.
on most AVR-based boards, the value is guaranteed to be between 20kohm and 50kohm.

when connecting sensor to a pin configured wuth INPUT_PULLUP
*the other end should be connected to the ground.*
in case of simple switch, this causes the pin to read HIGH when switch is open.
the pull-up resistors provide enough current to light an LED dimly connected to a pin configured as an input.

*same registers (internal chip memory locations) that controls
whether a pin is HIGH or LOW control the pull-up resistors.*

Consequently, a pin that is configured to have pull-up resistors
turned on when the pin is in INPUT mode, will have the pin configured 
as HIGH if the pin is then switched to OUTPUT mode with pinMode().

.. code-block:: arduino

   pinMode(3, INPUT);
   pinMode(5, INPUT_PULLUP);

pinMode() Function
^^^^^^^^^^^^^^^^^^

``pinMode()`` function is used to configure a specific pin to behave
either as an input or an output. it is possible to enable the 
internal pull-up resistors with the mode INPUT_PULLUP.
Additionally, the INPUT mode explicitly disables the internal pull-ups

.. code-block:: arduino

   int button   = 5;
   int LED      = 6;

   void setup()
   {
       pinMode(button, INPUT_PULLUP);
       // set the digital pin as input with pull-up resistor

       pinMode(button, OUTPUT);
       // set the digital pin as output
   }

   void loop()
   {
       if (digitalRead(button) == LOW) // if button pressed : button as INPUT_PULLUP
       {
           digitalWrite(LED, HIGH); // turn on led : button as OUTPUT
           delay(500);
           digitalWrite(LED, LOW); // turn off led
       }
   }

- pin: the number of the pin whose mode you wish to set
- mode: INPUT, OUTPUT, INPUT_PULLUP

digitalWrite() Function
^^^^^^^^^^^^^^^^^^^^^^^

used to write a HIGH or LOW value to digital pin.
if pin has been configured as an OUTPUT with ``pinMode``,
its voltage will be set to corresponding value:
5V or 3,3V on boards. for HIGH 0V for LOW.
if, the pin is configured as an INPUT, digitalWrite will 
enable(HIGH) or disable(LOW) the internal pullup on the input pin.
it is recommended to set the pinMode to INPUT_PULLUP to enable the internal pull-up resistor.

Sketch build process
--------------------

Overview
^^^^^^^^

1. Arduino development software performs some minor pre-proceesing to turn your sketch into a cpp program.
#. depecdancies of sketch are located.
#. it then gets passed to compiler(avr-gcc), which turns code to machine readable instructions or object file.
#. your code gets linked with the standard Arduino libraries that provide basic functions like ``digitalWrite()`` or ``Serial.print()``.
#. result is single intel hex file.

   - contains specific bytes that need to be written to th program memory of the chip on Arduino board.

#. this file is then uploaded to the board

   - transmitted over USB or serial connection via the bootloader already on the chip or extermnal hardware.

Pre-Processing
^^^^^^^^^^^^^^

Arduino development software performs a few transformations to your sketch before passing it to avr-gcc compiler

   1. All .ino and pde file in sketch folder and concatenated together
      strating wiht the file and matches the folder name by the other
      in alphabetical order and cpp extention is added to the filename.
   #. if not already present, ``#include <Arduino.h>`` is added to sketch.
      this header file includes all the definitions needed for standard Arudino core.
   #. Prototypes are generated for all function definition in .ino/.pde files
      that dont already have prototypes. in some rare cases
      prototype generation may fail for some functions. to work around this,
      you can provide your own prototypes for these functions
   #. ``#line`` directives are added to make warning 
      or error messages reflect the original sketch layout.

No pre-processing is done to files in sketch with any extension
other than .ino or .pde. Additionally .h files in the sketch
are not automatically #included from the main sketch file.
Further, if you want to call functions defined in a .c file from .cpp file,
you'll need to wrap this declaration in an ``extern "C" {}`` block
that is defined only inside of C++ files.
