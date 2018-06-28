#include <INTERVAL.h>
#include <SoftwareSerial.h>

SoftwareSerial nex_serial(10, 11); // RX, TX
SoftwareSerial laser_serial(8, 9); // RX, TX

char nex_buffer[30];

#define P(str) (strcpy_P(nex_buffer, PSTR(str)), nex_buffer)

uint8_t current_page;

void setup(void) {
  nex_serial.begin(9600);
  laser_serial.begin(38400);

  send_to_nextion(P("bkcmd=0"));
  send_to_nextion(P("page 0"));

  delay(25);

  send_to_nextion(P("page 1"));
}

void send_to_nextion(char ss[]) {
  /*
    send_to_nextion():
    sends nextion string and terminates it
  */

  nex_serial.print(ss);
  nex_serial.write(0xFF);
  nex_serial.write(0xFF);
  nex_serial.write(0xFF);
}

void get_distance(void) {
  laser_serial.print(F("/020D0e0C."));
}


void read_distance_and_display(void) {
  char temp_buffer[14];

  while (laser_serial.available() > 0) {
    uint8_t cc = laser_serial.read();

    if (cc == '/') {
      delay(10);
      if (laser_serial.available() >= 13) {
        for (uint8_t ii = 0; ii < 13; ii++) {
          temp_buffer[ii] = laser_serial.read();
        }
      }
    }
  }

  char distance_buffer[6];
  for (uint8_t ii = 4; ii < 9; ii++) {
    distance_buffer[ii - 4] = temp_buffer[ii];
  }

  if (distance_buffer[0] == 'l') {
    send_to_nextion(P("txt_dist.txt=\"Zu nah!\""));
  }
  else if (distance_buffer[0] == 'h') {
    send_to_nextion(P("txt_dist.txt=\"Zu weit!\""));
  }
  else {
    double distance = 60.0 + atof(distance_buffer) / 100.0;

    char str_temp[7];
    dtostrf(distance, 6, 3, str_temp);
    sprintf_P(nex_buffer, PSTR("txt_dist.txt=\"%s\""), str_temp);
    send_to_nextion(nex_buffer);
  }
}

void loop(void) {
  INTERVAL(200) {
    get_distance();

    delay(25);

    read_distance_and_display();
  }
}
