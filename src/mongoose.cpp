#include "mongoose.h"
#include <cmath>
#include <iostream>

bool Mongoose::BiteSnake() {
 return (++bitecount == 3?false:true);
  
}

void Mongoose::Burrough(int x, int y){
  mgx = x;
  mgy = y;
}

int Mongoose::GetBiteCount(){return bitecount;}