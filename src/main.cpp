#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "SDL.h"
int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{940};
  constexpr std::size_t kScreenHeight{940};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Game game(kGridWidth, kGridHeight);
  game.Run(renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "P1_Score: " << game.GetScore(0) << "\n";
  std::cout << "Snake1 Size: " << game.GetSize(0) << "\n";
  std::cout << "P2_Score: " << game.GetScore(1) << "\n";
  std::cout << "Snake2 Size: " << game.GetSize(1) << "\n";
  

  return 0;
}