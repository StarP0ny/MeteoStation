#include "main.h"

DHT dht(dht_data, DHTTYPE);    

TM1637Display display(disp_clk, disp_data);

void setup() 
{
  Serial.begin(9600);                          // Задаем скорость передачи данных
  Serial.println("DHT22 TEST!");               // Выводим текст
  dht.begin();
  display.setBrightness(0x0f);
  data[0] = display.encodeDigit(0);
  data[1] = display.encodeDigit(1);
  data[2] = display.encodeDigit(2);
  data[3] = display.encodeDigit(3);
  display.setSegments(data, 4, 0);
  //disp.showNumberDec(1, true);
}
 
void loop() 
{
  delay(2000);                                  // Задежка в 2 с
  float h = dht.readHumidity();                 // Считывание влажности в процентах
  float t = dht.readTemperature();              // Считывание температуры в градусах цельсия
 
  if (isnan(h) || isnan(t))                     // Проверяем, получилось считать данные 
    {
      Serial.println("Read error DHT22");    // Выводим текст
      return;                                  
    }
  
  //float hic = dht.computeHeatIndex(t, h, false);// Расчет типла по целсию
  Serial.print("Humidity: ");                   // Выводим текст
  Serial.print(h);                              // Отображаем влажность
  Serial.print(" %\t");                         // Выводим текст
  Serial.print("Temperature: ");                // Выводим текст
  Serial.print(t);                              // Отображаем температуру
  Serial.println(" *C ");                       // Выводим текст
  display.showNumberDec(t, false, 2, 0);
  //display.setSegments(data+2, 2, 3);
  display.showNumberDec(h, false, 2, 2);

}