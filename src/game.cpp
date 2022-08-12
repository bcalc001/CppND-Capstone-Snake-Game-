#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      mongoose(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      bites(0) {
  std::cout<<"Game() - constructor"<<std::endl;   //debug
  mongoose.push_back(Mongoose);
  PlaceFood();
  PlaceMongoose();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  std::cout<<"Run()"<<std::endl;
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, mongoose);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count, bites);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
     
    if (!snake.alive){
      std::cout<<"Your Snake has died. Game Over!"<<std::endl;
      return;}
  }
}

void Game::PlaceFood() {
  std::cout<<"PlaceFood()"<<std::endl;
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::PlaceMongoose() {
  std::cout<<"PlaceMongoose()"<<std::endl;
  int x, y;
  while (true) {
    for (auto mg : mongoose){
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake or food item before placing
    // mongoose.
    if (!snake.SnakeCell(x, y) && x!=food.x && y!=food.y) {
      mg.Burrough(x,y);
      return;
    }
    }
    
  }
}

void Game::Update() {
  std::cout<<"Update()"<<std::endl;
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here. If snake eats food, reset new food and new mongoose burrough
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    PlaceMongoose();

    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }

  // Check if the mongoose has bitten the snake. If it's bitten twice , snake dies!
  if (snake.SnakeCell(mongoose.mgx, mongoose.mgy))
    {
      snake.alive = mongoose.BiteSnake();
      bites = mongoose.GetBiteCount();
     if(snake.alive){PlaceMongoose();}
    }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
int Game::GetBites() const { return bites; }