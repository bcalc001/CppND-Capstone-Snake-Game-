#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(std::vector<Snake>  const  &snake, SDL_Point const &food, std::vector<Mongoose> const  &mongoose) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

   // Render mongoose(s)
  for (auto mg = mongoose.begin(); mg<= mongoose.end(); mg++){
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    block.x = (*mg).mgx * block.w;
    block.y = (*mg).mgy * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
    //std::cout<<"Mongoose rendered"<<std::endl;    
  }

for (auto snakes = snake.begin(); snakes <= snake.end(); snakes++)
    {
    // Render snake's body
    switch ( (*snakes).GetBites())
    {
      case 0:
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        break;
      case 1:
        SDL_SetRenderDrawColor(sdl_renderer, 0xCC, 0xCC, 0xCC, 0xFF);
        break;
      case 2:
        SDL_SetRenderDrawColor(sdl_renderer, 0xAA, 0xAA, 0xAA, 0xFF);
        break;
      case 3:
        SDL_SetRenderDrawColor(sdl_renderer,0xFF, 0x00, 0x00, 0xFF);
      break;
      
      default:
        break;
    }
    
    for (SDL_Point const &point :  (*snakes).body) {
      block.x = point.x * block.w;
      block.y = point.y * block.h;
      SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render snake's head
    block.x = static_cast<int>( (*snakes).head_x) * block.w;
    block.y = static_cast<int>( (*snakes).head_y) * block.h;
    if ( (*snakes).alive)
    {
      switch ( (*snakes).GetBites())
      {
      case 0:
        SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
      break;
      case 1:
        SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0x7A, 0xFF);
      break;
      case 2:
        SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x75, 0x75, 0xFF);
      break;
      case 3:
        SDL_SetRenderDrawColor(sdl_renderer,0xFF, 0x00, 0x00, 0xFF);
      break;
      
      default:
        break;
      }
    } 
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score[2],  std::vector<Snake> const &snake) {
  std::string title{"P1 Score: " + std::to_string(score[0]) +  
                    "P1_Bites: " + std::to_string(snake.front().GetBites()) +
                    "P1_Lives: " + std::to_string(snake.front().GetLives()) +
                    "   " +
                    "P2 Score: " + std::to_string(score[1]) +  
                    "P2_Bites: " + std::to_string(snake.back().GetBites()) +
                    "P2_Lives: " + std::to_string(snake.back().GetLives())};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
