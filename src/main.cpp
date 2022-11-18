#include "main.h"

#define DHTPIN 2                               // Пин к которому подключен датчик
#define DHTTYPE DHT22                          // Используемый датчик DHT 22 (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);                      // Инициализируем датчик
 
void setup() 
{
  Serial.begin(9600);                          // Задаем скорость передачи данных
  Serial.println("DHT22 TEST!");               // Выводим текст
  dht.begin();
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
}