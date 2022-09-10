# Sensor-Interfacing

framework used: PLATFORMIO;

for source codes goto " src/ " directory.

platfromio cheatsheet:
  include - folder contains headers (i have not placed any headers there for ease of readablity 
  lib - contains external library imports (which arent there in library manager
  src - folder containing source files ( our code is placed here)
  test - for unit tests
  .gitignore - version control related (google for more info)
  platformio.ini - contains framework configurations (eg . libs , serial baud rate )
  
Basic explanation of code:

config.h -> contains global setting for the project like pin-no for a sensor
            making it easy for us to change pins we connect our sensors to.
            macros are defined insted of global variables as we are statically 
            compiling our binaries and.. it saves stack space;
            (google about macros)

2 cpp files are there: main.cpp  & sensor_manger.cpp

main.cpp - starting point of the program (basically calls functions from sensor_manager.cpp

sensor_manager.cpp - file includes sensor_driver.h  - contains abstract class Sensor (defining rules for adding a sensor class)
                              temp_humidity_sensor.h - class which implements Sensor class which whill expose member
                                                       function to get temperature and humidity reading
                              gas_sensor.h - class which implements Sensor class which whill expose member function to get gas 
                                              concentration reading
                              config.h - to access pins connected to sensors for initialisations.
                     
                     and exposes some functions to acess the sensor reading data/
                     print it / and print data as json (as json object gets populated while getting sensor reading)
sensor_manager.h - contains declaration of functions in sensor_manager.cpp making it acessable when imported. (main.cpp imports it)


Overall - making a class of a certain sensor (implementing Sensor class) and instantiating it in the sensor_manger.cpp.
          and just by adding it to the init_all_sensor and get_all_reading functions the right way will make just any 
          kind of sensor data be added into our data list making it very easy to interface any sensor without any dependensies.
          
          as data can also be serialized into json format we can use the data anywhere (eg post to cloud) then use cases are huge .
                     
                     
