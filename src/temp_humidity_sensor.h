/* Defining Temperature and Humiidity Class implimenting Sensor */

// Library Import
#include "DHT.h"

DHT dht(DHTPIN, DHTTYPE);

class Temp_Humidity_Sensor : public Sensor
{
private:
    float humi;
    float temp;

public:
    Temp_Humidity_Sensor()
    {
        name = "DHT 11 (temperatue & humidity)";
        value_count = 2;
        pin_no = DHTPIN;
    }
    void init_driver()
    {
        dht.begin();
    }

    sensor_data *get_reading()
    {
        temp = dht.readTemperature();
        humi = dht.readHumidity();
        static sensor_data ths_reading[] = {{"Temperature", temp}, {"Humidity", humi}};
        return ths_reading;
    }
};
