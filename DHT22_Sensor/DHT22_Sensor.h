//-----------------------------------------------------
// DHT22_Sensor.h - Header File
// Library for Programming DHT22 Temp & Humidity Sensor
// by: Anas Kuzechie (June, 2022)
//-----------------------------------------------------
//header guards
#ifndef DHT22_Sensor_h
#define DHT22_Sensor_h
//-----------------------------------------------------------------------
//class definition
class DHT22_Sensor
{
    public:
        DHT22_Sensor(byte pin);
        void getData();
        float getTemperature();
        float getHumidity();
    private:
        byte _pin;
        byte RH_high, RH_low, temp_high, temp_low, checksum;
        unsigned int hum, temp;
        byte read_DHT22_byte();
};
//----------------------------------------------------------------------
#endif