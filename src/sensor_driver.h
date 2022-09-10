#include <string>

struct sensor_data
{
    String name; // not using const char* for json object copy by value {note std::string and String class is different}
    float reading;
};

// implement this interface while adding new sensor class
class Sensor
{
protected:
    std::string name;
    int value_count;
    uint8_t pin_no;

public:
    virtual void init_driver() = 0;
    virtual sensor_data *get_reading() = 0;
    std::string get_sensor_name() { return name; }
    int get_value_count() { return value_count; }
};
