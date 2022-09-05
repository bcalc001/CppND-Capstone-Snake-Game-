#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"
#include <mutex>
#include <vector>
std::mutex mtx;


void Controller::ChangeDirection(Snake &snake, Snake::Direction input, Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake) const 
{
  //std::lock_guard<std::mutex> lck(mtx);
  std::vector<SDL_Event> e;
  e.push_back(SDL_Event());	//snake 0
  e.push_back(SDL_Event());	//snake 1
    
    while (SDL_PollEvent(&e[snake.id])) 
    {
      if (e[snake.id].type == SDL_QUIT) {running = false;}
      else if (e[snake.id].type == SDL_KEYDOWN) 
      {
        if(e[snake.id].key.keysym.sym == _Up)
            ChangeDirection(snake, Snake::Direction::kUp,Snake::Direction::kDown);
        else if(e[snake.id].key.keysym.sym == _Down)
            ChangeDirection(snake, Snake::Direction::kDown,Snake::Direction::kUp);
        else if(e[snake.id].key.keysym.sym == _Left)
            ChangeDirection(snake, Snake::Direction::kLeft,Snake::Direction::kRight);
        else if(e[snake.id].key.keysym.sym == _Right)
            ChangeDirection(snake, Snake::Direction::kRight, Snake::Direction::kLeft);
   	 }
  	}
  
}

