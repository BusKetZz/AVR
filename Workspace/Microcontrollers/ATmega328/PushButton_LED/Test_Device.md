# Test device prototype - black box

### Introduction

The "black box' is a device or a system, which can be viewed in terms
of its inputs and outputs without any knowledge of its internal workings.


### Test device purpose

1. Check whether a push button works correctly. The correct behaviour
means that when the push button is pressed, PIN0 of PORTB is grounded.

2. Check whether a LED1, after pressing the push button, turns on.

3. Check whether a LED1, while pressing the push button, works in given
manner: 500ms ON, 250 OFF, iterates 3 times then turns off. 


### Test device characteristic

Test device would be based on ATmega168 or any other MCU from ATmega family.
Three LEDs would signal whether systems works in specified manner:

1. Blue LED:    `ON`  - PORTB, PIN0 pulled ground while pressing push button
                `OFF` - PORTB, PIN0 pulled to Vcc while pressing push button

2. Yellow LED:  `ON`  - PORTB, PIN1 is high state while push button is pressed
                `OFF` - PORTB, PIN1 is grounded while push button is pressed

3. Green LED:   `ON`  - program counts that LED have been turned on and off 
                        three times in specified manner while pressing the
                        push button (program would read pin state: high or low)
                `OFF` - program doesn't count that LED have been turned on and
                        off three times

Signals from the tested device would be connected to the GPIO pins of the 
"black box" device. "Black box" device would utilize only two GPIO pins
for the test probes, and three GPIO pins for LEDs.
