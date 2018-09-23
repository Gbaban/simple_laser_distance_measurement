# simple_laser_distance_measurement

a small project to use a wenglor OCP662X0080 laser sensor for distance measurement

## Device description:

* A simple Arduino Nano with a 2.4'' Nextion display and a laser distance sensor attached.
* The display shows the current measured distance or too far away/ too near.
* The device is used in production to measure distance between a wood part and a machine tool (e.g. a drill or saw).

## Firmware:

The MCU is a Atmega 328P (Arduino Nano) and the firmware is written with Arduino IDE 1.8.6. I used:

* [INTERVAL.h](https://forum.arduino.cc/index.php?topic=413734.0)
* SoftwareSerial (standard library)

## Wiring:

<img src="https://github.com/anwofis/simple_laser_distance_measurement/blob/master/wiring/wiring.png" title="wiring" width="750">

## Pictures:

Here are some pictures:

<img src="https://github.com/anwofis/simple_laser_distance_measurement/blob/master/images/box.jpg" title="box" width="750">
<img src="https://github.com/anwofis/simple_laser_distance_measurement/blob/master/images/sensor.jpg" title="sensor" width="750">
