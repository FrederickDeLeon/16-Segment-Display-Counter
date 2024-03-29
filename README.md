The purpose of these programs is for the digits 0-9 to be displayed on a 16-segment display when a pushbutton is pressed. 
Each of the 19 pins of the 16-segment display are connected to a 220 Ohm resistor before being connected to the Arduino header on the Nucleo-64 board. 
The display is common anode and pins 1 and 19 are the common pins, which must be connected to power from the 5V header on the nucleo board. 
I decided to only drive 7 segments of the display since those are the only ones required to display the digits 0-9, and so connected the corresponding pins to the nucleo board. 
Pin 2 to D11, pin 3 to D8, pin 4 to D5, pin 6 to D6, pin 10 (DP) to D15, pin 11 to D14, pin 13 to D13, and pin 14 to D12. 
