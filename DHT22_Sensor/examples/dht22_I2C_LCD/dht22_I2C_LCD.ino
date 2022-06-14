//-------------------------------------------------
// DHT22 Sensor Temp/Humidity on I2C 1602 LCD
// using DHT22_Sensor.h & LCD_1602_I2C.h Libraries
// by: Anas Kuzechie (June, 2022)
//-------------------------------------------------
#include <DHT22_Sensor.h>
#include <LCD_1602_I2C.h>
//-----------------------------------------------------------------
DHT22_Sensor dht22(2);    /*sensor connected to digital pin 2*/
LCD_1602_I2C lcd(0x40);   /*I2C LCD with write address 0x40*/
//=================================================================
void setup()
{
  lcd.Initialize();       /*initialize 16x2 LCD*/
  delay(1000);
  //------------------------------------------------------
  lcd.writeText("--DHT22 Sensor--");
  lcd.writeChar(0, 0xC0); /*beginning of 2nd line*/
  lcd.writeText("Temp & Humidity");
  delay(2000);
  lcd.writeChar(0, 0x01); /*clear LCD*/
}
//=================================================================
void loop()
{
  delay(2000);
  //---------------------------------------------------
  dht22.getData();
  //---------------------------------------------------
  float temp = dht22.getTemperature();
  int temp_MSD = int(temp)/10 + 48;
  int temp_LSD = int(temp)%10 + 48;
  int temp_fraction = (temp - int(temp))*10 + 48;
  //---------------------------------------------------
  lcd.writeText("Temp    : ");
  lcd.writeChar(1, temp_MSD);
  lcd.writeChar(1, temp_LSD);
  lcd.writeChar(1, '.');
  lcd.writeChar(1, temp_fraction);
  lcd.writeText(" C");
  //---------------------------------------------------
  float hum = dht22.getHumidity();
  int hum_MSD = int(hum)/10 + 48;
  int hum_LSD = int(hum)%10 + 48;
  int hum_fraction = (hum - int(hum))*10 + 48;
  //---------------------------------------------------
  lcd.writeChar(0, 0xC0); /*beginning of 2nd line*/
  //---------------------------------------------------
  lcd.writeText("Humidity: ");
  lcd.writeChar(1, hum_MSD);
  lcd.writeChar(1, hum_LSD);
  lcd.writeChar(1, '.');
  lcd.writeChar(1, hum_fraction);
  lcd.writeText(" %");
  //---------------------------------------------------
  lcd.writeChar(0, 0x80); /*beginning of 1st line*/
}