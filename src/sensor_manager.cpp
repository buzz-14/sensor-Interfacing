#include <vector>
#include <ArduinoJson.h>
#include "config.h"

// All Sensor Classes
#include "sensor_driver.h"
#include "temp_humidity_sensor.h"
#include "gas_sensor.h"

std::vector<sensor_data> value_arr; // stores Array of structs(of all reading)
static int total_value_count = 0;   // stores total sensor values count
DynamicJsonDocument json_doc(DOCSIZE);
// StaticJsonDocument<200> json_doc;    //[for  allocation of json doc in stack)]

// create objects on heap
static Temp_Humidity_Sensor *ths = new Temp_Humidity_Sensor();
static Gas_Sensor *gs = new Gas_Sensor();

// routine to init all sensors -- add more by calling init member method of <sensor> class objects
void init_all_sensor()
{
    json_doc.clear();
    ths->init_driver();
    gs->init_driver();
}

// add sensor reading to value_arr from a single Sensor object
void add_data(Sensor *s)
{
    sensor_data *data = s->get_reading();
    total_value_count += s->get_value_count();
    for (int i = 0; i < s->get_value_count(); ++i)
    {
        value_arr.push_back(data[i]);
        json_doc[data[i].name] = data[i].reading;
    }
}

// force generate json
void generate_json(void)
{
    void get_all_reading();
    for (auto it = value_arr.begin(); it != value_arr.end(); it++)
    {
        json_doc[it->name] = it->reading;
    }
}

// routine to add all sensor data to value_arr -- pass sensor object to add data()
void get_all_reading(void)
{
    value_arr.clear();
    total_value_count = 0;
    add_data(ths);
    add_data(gs);
}

void print_all_readings(void)
{
    get_all_reading();
    for (auto it = value_arr.begin(); it != value_arr.end(); it++)
    {
        Serial.print(it->name);
        Serial.print(": \t");
        Serial.println(it->reading);
    }
}

void print_all_readings_in_json(void)
{
    get_all_reading();
    serializeJsonPretty(json_doc, Serial);
    Serial.println();
    Serial.println(json_doc.capacity());
    Serial.println(json_doc.overflowed());
    Serial.println(json_doc.isNull());
    Serial.println();
}
