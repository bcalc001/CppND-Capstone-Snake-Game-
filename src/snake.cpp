#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update() {
    //std::cout<<"Snake::Update()"<<std::endl;

  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead(1);
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateHead(int fwd_rev) {
   // std::cout<<"Sanke::UpdateHead()"<<std::endl;

  switch (direction) {
    case Direction::kUp:
      head_y = (head_y - speed)*fwd_rev;
      break;

    case Direction::kDown:
      head_y = (head_y + speed)*fwd_rev;
      break;

    case Direction::kLeft:
      head_x = (head_x - speed)*fwd_rev;
      break;

    case Direction::kRight:
      head_x = (head_x + speed)*fwd_rev;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
   // std::cout<<"Snake::UpdateBody()"<<std::endl;

  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}
int Snake::GetBites() const { return bites; }
int Snake::GetLives() const {return lives;}
void Snake::SetBites() 
  { ++bites; 
    if(bites==3)
      {
        --lives;
        bites = 0;       

       }
    if(lives == 0){alive = false;}
  }
void Snake::RunFromBadFood()
{  
  std::cout<<"Snake::RunFromBadFood()"<<std::endl;
UpdateHead(-1);
}