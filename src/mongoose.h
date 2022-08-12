#ifndef MONGOOSE_H
#define MONGOOSE_H
#include <vector>
#include "SDL.h"
#include "snake.h"
class Mongoose {
 public:
  

  Mongoose(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height)
        {}

  void BiteSnake(Snake &snake);  
  void Burrough(int x, int y);
  float speed{0.1f};
  
  
  int mgx;
  int mgy;

 private:
  int grid_width;
  int grid_height;
    
};

#endif