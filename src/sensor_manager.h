// includes
#include <string>
#include <vector>
#include <sensor_driver.h>

// sensor readings
void init_all_sensor(void);
void get_all_reading(void);
void print_all_readings(void);
void print_all_readings_in_json(void);

// global vars
extern std::vector<sensor_data> value_arr;