#include <Adafruit_CircuitPlayground.h>
#include <math.h>
#include <stdlib.h>
#define N_PINS 10
#define E 2.718281828459045

short N = N_PINS - 1;
uint16_t DELAY = 2000;
uint16_t MAX_DELAY = 2000;
uint16_t NORMALIZER = 50;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(0);
  CircuitPlayground.begin();
}

void loop() {
  move();
  if(Serial.available() > 0){
    int cpuUsage = Serial.parseInt();
    if(cpuUsage > 0)
      DELAY = MAX_DELAY * (1 - (1 / (1 + pow(E, -((cpuUsage - 50) * 6 / 50))))) + NORMALIZER; // Reversed Sigmoid Function
  }
  delay(DELAY);
//  Serial.println(DELAY);
}

void move() {
  if(N < 0){
    CircuitPlayground.clearPixels();
    N = N_PINS - 1;
  }
  
  CircuitPlayground.setPixelColor(N, 0, 0, 255);
  N--;
}

