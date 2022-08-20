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
  int GetScore(int player) const;
  int GetSize(int player) const;
  int GetBites(int player);
  int GetLives(int player); 
  void SetFoodType();
  bool GetFoodType();

 private:
  std::vector<Snake> snake;
  std::vector<Mongoose> mongoose;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  std::uniform_real_distribution<double> random_food;

  
  int grid_width;
  int grid_height;
  bool rotten_food = false;
  int score[2] = {0,0};
  void PlaceFood();
  void PlaceMongoose();
  void Update();
};

#endif