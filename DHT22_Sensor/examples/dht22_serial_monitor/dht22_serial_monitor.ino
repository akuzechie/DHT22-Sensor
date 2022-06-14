//----------------------------------------------
// DHT22 Sensor Temp/Humidity on Serial Monitor
// using DHT22_Sensor.h Library
// by: Anas Kuzechie (June, 2022)
//----------------------------------------------
#include <DHT22_Sensor.h>
//-----------------------------------------------------------------
DHT22_Sensor dht22(2);  /*sensor connected to digital pin 2*/
//=================================================================
void setup()
{
  Serial.begin(9600);
}
//=================================================================
void loop()
{
  delay(2000);
  //-----------------------------------------------------------
  dht22.getData();      /*communicate with sensor & get data*/
  //-----------------------------------------------------------
  float t = dht22.getTemperature(); /*temp in Celcius*/
  float h = dht22.getHumidity();    /*humidity in percentage*/
  //-----------------------------------------------------------
  Serial.print(t); Serial.print("°C   ");
  Serial.print(h); Serial.println("%");
}