#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height, int offset, int id)
      : grid_width(grid_width),
        grid_height(grid_height),
        offset(offset),
        head_x(grid_width + offset),
        head_y(grid_height + offset),
        id(id) {}

  void Update();
  int GetBites() const;
  int GetLives() const;
  void SetBites();
  void GrowBody();
  void RunFromBadFood();
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;
  int id=0;
 private:
  void UpdateHead(int fwd_rev);
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);
  int bites{0};
  int lives{3};
  bool growing{false};
  int grid_width;
  int grid_height;
  int offset; 
};

#endif