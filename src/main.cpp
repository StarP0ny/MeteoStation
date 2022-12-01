#include "main.h"

DHT dht(dht_data, DHTTYPE);    

TM1637Display display(disp_clk, disp_data);

void setup() 
{
  dht.begin();
  display.setBrightness(0x0f);
  display.setSegments(data, 4, 0);
}
 
void loop() 
{
  float h = dht.readHumidity();                 // Считывание влажности в процентах
  float t = dht.readTemperature();              // Считывание температуры в градусах цельсия

  display.showNumberDec(t, true, 2, 0);
  display.showNumberDec(h, true, 2, 2);
}