#include "game.h"
#include <iostream>
#include "SDL.h"


Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),      
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      random_food(0, 1.0),
      grid_width(grid_width),
      grid_height(grid_height) {
  std::cout<<"Game() - constructor"<<std::endl;   //debug
  mongoose.push_back(Mongoose(grid_width, grid_height));
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
      renderer.UpdateWindowTitle(score, frame_count, snake.GetBites(), snake.GetLives());
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
    SetFoodType();
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
  std::cout<<"mongoose count: "<<mongoose.size()<<std::endl;
  while (true) {
    for (auto mg = mongoose.begin();mg <= mongoose.end(); mg++){
     
    x = random_w(engine);
    y = random_h(engine);
    //std::cout<<"mg_xy: "<<x<<" "<<y<<std::endl;
    // Check that the location is not occupied by a snake or food item before placing
    // mongoose.
      if (!snake.SnakeCell(x, y) && x!=food.x && y!=food.y) {
        (*mg).Burrough(x,y);
         std::cout<<(*mg).mgx<<" "<<(*mg).mgy<<std::endl;
        return;
        }
    }
    
  }
}

void Game::Update() {
  //std::cout<<"Update()"<<std::endl;
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here. If snake eats food, reset new food 
  if (food.x == new_x && food.y == new_y )
  {
    if(GetFoodType()){score++;}    //Good food?
    if (!GetFoodType()){snake.RunFromBadFood();} //bad food?
     PlaceFood();
      if (score%3 ==0) 
        {
          mongoose.push_back(Mongoose(grid_width, grid_height));
          PlaceMongoose();
        }
    
     //std::cout<<"mongoose count: "<<mongoose.size()<<std::endl;


    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }

  // Check if the mongoose has bitten the snake. If it's bitten three times , snake dies!
   for (auto mg = mongoose.begin(); mg<= mongoose.end(); mg++){
    
     if (snake.SnakeCell((*mg).mgx, (*mg).mgy))
    {
      (*mg).BiteSnake(snake);
      if(snake.GetLives() == 0){snake.alive=false;}
     if(snake.alive){PlaceMongoose();}
    }
   }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
int Game::GetBites() {return snake.GetBites();}
int Game::GetLives() {return snake.GetLives();}
void Game::SetFoodType()
  {
    double foodtype = random_food(engine);
    rotten_food = (foodtype > 0.50)? true:false;
  } //good food=true

bool Game::GetFoodType(){return rotten_food;}
