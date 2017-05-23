#include <Adafruit_CircuitPlayground.h>
#include <math.h>
#include <stdlib.h>
#define N_PINS 10
#define N_COLORS 11
#define E 2.718281828459045

short N = N_PINS - 1;
uint16_t DELAY = 1000;
uint16_t MAX_DELAY = 1000;
uint16_t NORMALIZER = 50;

typedef struct Color{
  uint8_t r, g, b;
};
Color COLORS[N_COLORS] = {
  {250, 0, 0},
  {225, 20, 25},
  {200, 40, 50},
  {175, 60, 75},
  {150, 80, 100},
  {125, 100, 125},
  {100, 120, 150},
  {75, 140, 175},
  {50, 160, 200},
  {25, 180, 225},
  {0, 200, 250}
};
short RGB = 0; // Just a colors counter

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
  
  CircuitPlayground.setPixelColor(N, COLORS[RGB].r, COLORS[RGB].g,  COLORS[RGB].b);
  N--;
  RGB = (RGB + 1) % N_COLORS;
}

