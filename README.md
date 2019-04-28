# Simple Thermostat #

### Introduction ###

This is a simple circuit using an Arduino Uno to first read temperature values from a DS18B20 one-wire temperature sensor, then present the temperature readings on a 2x16 character LCD display, and finally turn on or off a fan motor if the temperature is higher or lower than the predefined temperature threshold.

### Circuit Drawing ###

<img src="Images/2019-04-28_SimpleThermostat_Tinkercad.png">

- - - -

### Bill of Materials ###

| Name | Quantity | Component |
| --- | --- | --- |
| U1 | 1 | Arduino Uno R3 |
| U2 | 1 | LCD 16 x 2 |
| Rpot2 | 1 | 250 kΩ, Potentiometer |
| R1 | 1 | 220 Ω Resistor |
| T1 | 1 | NPN Transistor (e.g. BC337-25) |
| R2 | 1 | 2.2 kΩ Resistor |
| M1 | 1 | DC Motor |
| U3 | 1 | Temperature Sensor (DS18B20) |
| R3 | 1 | 4.7 kΩ Resistor |
