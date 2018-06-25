# simple_laser_distance_measurement
a small project to use a wenglor OCP662X0080 laser sensor for distance measurement

18/06/25

For a project i want to measure the distance between machine and a wood part precisely and without touch.
I first thought about cheap distance measurement sensors used for Arduinos. But e.g. ultrasonic sensors 
have a low range and aren't very precise, infrared sensors are better but still only precise within some
millimeters and TOF-sensors measure via a small laser but are only precise within some millimeters.

So i forgot about those sensors and looked at industrial ones, which work with a laser and reciever, that
calculates the distance from the reflected light - i think. There are many manufacturers, which build them
e.g. Contrinex, Pepperl & Fuchs, Sick or Wenglor just to name a few.

From these i chose the sensor OCP662X0080 from Wenglor as i got it cheap from eBay and its measured distance
can be easily queried via RS232.

For the project i just display the distance on a 2.4'' Nextion screen and put everything into a plastic box.
The sensor is connected to an Arduino Nano via a MAX3232 and SoftwareSerial. (This is enough as i only send and 
recieve one by one.) The Nextion is also connected via SoftwareSerial as i don't need the touchscreen.

The sensor already works very fine:
It gives the distance in 1/100 mm e.g. "/060D12345nqq." for 123.45 mm. If you are to far it gives "hhhhh" and too close it gives "lllll"
as distance. The distance zero is 60.00 mm away from the sensor, which i just added to the distance. For more there is the [data sheet](https://www.wenglor.com/fileadmin/functions/wdm.php?dfile=OCP662X0080.PDF&pfad=fileadmin/download/DATA_SHEETS/EN/&sfile=Data_sheet_OCP662X0080.pdf&zip=false).

Here is a picture of the electric connections:

![wiring](https://github.com/anwofis/simple_laser_distance_measurement/blob/master/wiring/wiring.png)

Testing via Serial0 on my PC is working fine: the sensor seems accurate within 0.1 mm. When the display arrives, i'll install everything and write an update.