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

I/O Functions
-------------

pins can configured as input or output.

.. note::

   very important to note that majority of Arduino analog pins.

Pins confiugured as INPUT
^^^^^^^^^^^^^^^^^^^^^^^^^

| arduino pins are default configured as input.
| 아두이노 핀들은 기본값으로 input pin으로 설정되어있다.
| pins configured this way are said to be in a high-impedance state. equivalent to series resistor of 100 megaohm in front of the pin.
| 이러한 방식으로 설정된 핀들은 고저항 상태에 있는 것으로 말해진다. 연속적으로 100megaohm이 핀 앞에 있는 것과 동일하다.
| this means that it takes very little current to switch the input pin from one state to another.
| 이것은 그들의 상태를 바꾸기 위해서는 아주 적은 전류가 흐르게 된다는 것이다.
| this makes the pins useful for such tasks as implementing a capacitive touch sensor or reading an LED as a photodiode.
| photodiode(빛을 전기 흐름으로 바꾸는 semiconductor)로서 led를 읽게 하거나 정전용량 센서를 구현하는데 유용하게 작용한다.
| Pins configured as pinMode(pin, INPUT) with notthing connected to them, or with wires connected to them that are not connected to other circuits
| 입력핀으로 설정되었으나 아무것도 연결되어있지 않은 핀들,
| these pins report seemingly random changes in pin state, picking up electrical noise from environment, or coupling the state of a nearby pin.
| 이러한 핀들은 임의의 변화를 핀상태에서 보고하며, 환경에서부터 전기적 노이즈를 수령하거나, 주변핀의 상태에 영향을 받는다.

Pull-up Resistors
^^^^^^^^^^^^^^^^^

pull-up resistors are often useful to steer an input pin to known state if no input is present.
이것은 pullup resistor를 +5V로 input에 더하거나, pulldown resistor를 ground로 향하게 하여 input에 더하는 것으로 이루어 질 수 있다,
10K resistor는 pullup pulldown resistor에게 좋은 value.

*using Built-in Pull-Up resistor with Pins Configured as input*

Atmege chip에 20000 pullup resistors가 내장되어 있어 코드로 접근할 수 있다.
이 builtin pullup resistors는 ``pinMode()`` 를 ``INPUT_PULLUP`` 으로 설정하는 것으로 접근할 수 있다.
이것이 효과적으로 INPUT 모드를 반전 할 수 있다. 
the value of this pullup depends on microcontroller에 달린다.
대부분의 AVR보드에서 이 값은 20kohm ~ 5-kohm으로 보장된다.

센서를 핀으로 INPUT_PULLUP으로 설정한 pin으로 연결할 때, 반대편은 gnd로 연결되어야 한다.
simple switch case, switch open -> read HIGH, switch pressed -> read LOW.
pullup resistors provide enough current to light an LED dimly connected to pin configured as input.
만약 LED가 아주 약하게 동작하는 것으로 보인다면, 제대로 동작하는 것이다.

내부 칩 메모리주소가 같은 same registers, controls whether pin is HIGH or LOW,가 control the pullup registors.
동시에 pin is in INPUTmode일때 turned on 된 pullup resistors를 가진 핀이 
will have the pin configured as HIGH, if pin is then switched to OUTPUT mode with ``pinMode()``.

.. code-block:: arduino

   pinMode(3, INPUT); // set pin to input without using built in pullup resistor.
   pinMode(5, INPUT_PULLUP);

*Pins Configured as output*

``pinMode()`` 로 OUTPUT으로 설정된 핀들은 said to be in low-impedance state.
이는, 그들으 잠재적으로 많은 전류를 다른 서큣로 전달 할 수 있다는 것.
Atmega pins는 can source (provide positive current) or sink (provide negative current) up to 40mA of current to other circuits.
20mA 이면 잘 동작하는 LED엔 충분하며, also run many sensors but not enough current to tun relays, solenoids, or motors.

from outpins, attempting to run high current device는 output transistors in pin, entire Atmega chip을 손상시킬 수 있다.
이러한 이유로, it is good idea to connect the OUTPUT pins to other devices through 470ohm or 1k resistors, unless
그렇지 않으면 maximum current drwawn from the pins is required for particular application.

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

