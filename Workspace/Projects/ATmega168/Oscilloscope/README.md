# Oscilloscope


### Description

The following project is the expanded version of `Light Sensor` project.
It adds the USART functionality into the project, and changes from ADC0 
single conversion to continuous conversion. LEDs are turned off.
Additionally, the informations gathered from ADC0 and sent over serial port
are used by the `Oscilloscope.py` desktop app to draw a graph.


### Parts

| Nr.  |              Name             |  Amount  |
|:-----|:------------------------------|:--------:|
| 1    | ATmega168                     |    1     |
| 2    | 10K [Ohms] Resistor           |    2     |
| 3    | 220 [Ohms] Resistor           |    9     |
| 4    | Red/Green LED                 |    8     |
| 5    | Photoresistor                 |    1     |
| 6    | L7805CV Voltage Regulator     |    1     |
| 7    | 10 [nF] Ceramic Capacitor     |    3     |
| 8    | 470 [nF] Monolithic Capacitor |    1     |
| 9    | 2N7000 N-MOSFET Transistor    |    1     |
| 10   | FT232R - FTDI USB-UART        |    1     |


### Layout Diagram
