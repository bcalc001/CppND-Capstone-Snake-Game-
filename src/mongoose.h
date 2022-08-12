#ifndef MONGOOSE_H
#define MONGOOSE_H

#include <vector>
#include "SDL.h"

class Mongoose {
 public:
  

  Mongoose(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        bitecount(0){}

  bool BiteSnake();  
  void Burrough(int x, int y);
  int GetBiteCount();

  float speed{0.1f};
  
  
  int mgx;
  int mgy;

 private:
  //void UpdateMongoose();
  int grid_width;
  int grid_height;
  int bitecount;  
};

#endif