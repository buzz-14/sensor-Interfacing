// Defining gas sensor class implimenting the Sensor interface.

// Library import (none here)

class Gas_Sensor : public Sensor
{
private:
    float gas_concentration;

public:
    Gas_Sensor()
    {
        name = "MQ2 (gas sensor)";
        value_count = 1;
        pin_no = GASPIN;
    }
    void init_driver()
    {
        pinMode(GASPIN, INPUT);
    }
    sensor_data *get_reading()
    {
        gas_concentration = analogRead(GASPIN);
        static sensor_data gas_reading[] = {{"Gas Concentration", gas_concentration}};
        return gas_reading;
    }
};
