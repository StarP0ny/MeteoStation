#pragma once

#include <Arduino.h>
#include "DHT.h"
#include "TM1637Display.h"

#define DHTTYPE DHT22

#define TEST_DELAY 2000

const uint8_t dht_data = 4;
const uint8_t disp_clk = 2;
const uint8_t disp_data = 3;

uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };