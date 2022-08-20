#include "mongoose.h"
#include <cmath>
#include <iostream>


Mongoose::Mongoose(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height)
        {}

Mongoose::~Mongoose(){}

void Mongoose::BiteSnake(Snake &snake) {
   snake.SetBites();  
}

void Mongoose::Burrough(int x, int y){
  mgx = x;
  mgy = y;
}

