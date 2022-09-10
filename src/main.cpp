#include <Arduino.h>
#include <string>
#include "sensor_manager.h"

void setup()
{
  Serial.begin(115200);
  init_all_sensor();
}

void loop()
{
  // get_all_reading();
  // print_all_readings();
  print_all_readings_in_json();
  delay(1000);
}