//-----------------------------------------------------
// DHT22_Sensor.cpp - Source File
// Library for Programming DHT22 Temp & Humidity Sensor
// by: Anas Kuzechie (June, 2022)
//-----------------------------------------------------
#include <Arduino.h>
#include <DHT22_Sensor.h>
//========================================================================
// Constructor
//========================================================================
DHT22_Sensor::DHT22_Sensor(byte pin)
{
  _pin = pin;
}
//========================================================================
// Public Methods
//========================================================================
void DHT22_Sensor::getData()
{
  /*start signal*/
  pinMode(_pin, OUTPUT);             /*set data pin for o/p*/
  digitalWrite(_pin, LOW);           /*first send low pulse*/
  delayMicroseconds(1000);           /*for 1ms*/
  digitalWrite(_pin, HIGH);          /*then send high pulse*/
  delayMicroseconds(40);             /*for 40us*/
  //-------------------------------------------------------------------
  /*response signal*/
  pinMode(_pin, INPUT);              /*set data pin for i/p*/
  while(digitalRead(_pin));          /*wait for DHT22 low pulse*/
  while(!digitalRead(_pin));         /*wait for DHT22 high pulse*/
  while(digitalRead(_pin));          /*wait for DHT22 low pulse*/
  //-------------------------------------------------------------------
  /*read sensor data*/
  RH_high = read_DHT22_byte();       /*read high byte humidity*/
  RH_low = read_DHT22_byte();        /*read low byte humidity*/
  temp_high = read_DHT22_byte();     /*read high byte temp*/
  temp_low = read_DHT22_byte();      /*read low byte temp*/
  checksum = read_DHT22_byte();      /*read checksum*/
  //------------------------------------------------------------------
  hum  = (RH_high << 8) | RH_low;    /*get 16-bit value of humidity*/
  temp = (temp_high << 8) | temp_low;/*get 16-bit value of temp*/
}
//========================================================================
float DHT22_Sensor::getTemperature()
{
  return(float(temp)/10.0);
}
//========================================================================
float DHT22_Sensor::getHumidity()
{
  return(float(hum)/10.0);
}
//========================================================================
// Private Method
//========================================================================
byte DHT22_Sensor::read_DHT22_byte()
{
  byte dataByte;
  for(byte i=0; i<8; i++)
  {
    while(!digitalRead(_pin));       /*detect data bit (high pulse)*/
    delayMicroseconds(50);
    //--------------------------------------------------------------------
    if(digitalRead(_pin)) dataByte = (dataByte<<1)|(0x01);
    else dataByte = (dataByte<<1);   /*store 1 or 0 in dataByte*/
    //--------------------------------------------------------------------
    while(digitalRead(_pin));        /*wait for DHT22 low pulse*/
  }
  return dataByte;
}