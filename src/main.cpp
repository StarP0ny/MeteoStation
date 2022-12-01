#include "main.h"

DHT dht(dht_data, DHTTYPE);    

TM1637Display display(disp_clk, disp_data);

void setup() 
{
  //Serial.begin(9600);                          // Задаем скорость передачи данных
  //Serial.println("DHT22 TEST!");               // Выводим текст
  dht.begin();
  display.setBrightness(0x0f);
  //data[0] = display.encodeDigit(0);
  //data[1] = display.encodeDigit(1);
  //data[2] = display.encodeDigit(2);
  //data[3] = display.encodeDigit(3);
  display.setSegments(data, 4, 0);
  //disp.showNumberDec(1, true);
}
 
void loop() 
{
  float h = dht.readHumidity();                 // Считывание влажности в процентах
  float t = dht.readTemperature();              // Считывание температуры в градусах цельсия

  display.showNumberDec(t, true, 2, 0);
  display.showNumberDec(h, true, 2, 2);
  //display.showDots(1, 4);

}