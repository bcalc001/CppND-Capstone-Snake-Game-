#include "mongoose.h"
#include <cmath>
#include <iostream>




void Mongoose::BiteSnake(Snake &snake) {
   snake.SetBites();  
}

void Mongoose::Burrough(int x, int y){
  mgx = x;
  mgy = y;
}

