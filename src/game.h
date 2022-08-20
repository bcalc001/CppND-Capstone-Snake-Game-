#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "mongoose.h"
#include <vector>


class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  int GetBites();
  int GetLives(); 
  void SetFoodType();
  bool GetFoodType();

 private:
  Snake snake;
  std::vector<Mongoose> mongoose;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  std::uniform_real_distribution<double> random_food;

  int score{0};
  int grid_width;
  int grid_height;
  bool rotten_food = false;
  
  void PlaceFood();
  void PlaceMongoose();
  void Update();
};

#endif