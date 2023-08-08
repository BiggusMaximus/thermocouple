#include "paramater.h"
#include <Arduino.h>
#include "thermocouple.h"
#include "display.h"
#include "kalman.h"

void setup()
{
  Serial.begin(115200);
  calibrate_thermocouples();
  delay(1000);
  start_display();
  show_thermocouples_pin();
}

void loop()
{
  float *thermocouple_data = read_temperatures();
  float *kalman_thermocouple_data = kalmanThermocouple(thermocouple_data);
  // show_thermocouple_data(thermocouple_data);
  display_thermocouple_data(thermocouple_data);
  thermocouple_data[NUMBER_OF_THERMOCOUPLES] = {};
  kalman_thermocouple_data[NUMBER_OF_THERMOCOUPLES] = {};

  delay(1000);
}
