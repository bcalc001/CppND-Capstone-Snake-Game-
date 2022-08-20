

# CPPND: Capstone Snake Game : Bryan Calcagno
This game is extended from the snake game version supplied in the starter repository at:  [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project I have extended the snake game to include the following features:

1- a hazard in the form of a natural snake predator called a mongoose which the player must deftly avoid contacting as they manuver the snake to find food. 

2- Each time the player scores an additional 3 points, a new mongoose is added. 

3- If the snake and mongoose come into contact with each other by sharing a positional coordinate, the mongoose is assumed to attack the snake with a bite. The player's snake is allowed two bites before the snake is considered to lose its life. 

4- A life counter for snake/player has been added. The snake shall have 3 lives to use before game over

5- Rotten food. If the snake consumes rotten food it forces the snake to reverse direcdtion immediately with increased speed.


#Folder structure:   Note: build folder is not included in the repo. This is constructed by the user upon installation.
CPP_Captston_Snake_Game
  cmake
  CMakeLists.txt
  src
      controller.h
      controller.cpp
      game.h
      game.cpp
      main.cpp
      mongoose.h
      mongoose.cpp
      renderer.h
      renderer.cpp
      snake.h
      snake.cpp

# Rubric

1- The project demonstrates an understanding of C++ functions and control structures:
A variety of control structures are used in the project.
New functions added= 
game.h: 20
game.h:36
game.cpp:81
game.cpp:142

vector structure: 
game.h:23
game.cpp 86

2- The project accepts user input and processes the input.
The project accepts input from a user as part of the necessary operation of the program.
Controller.cpp:12-37

3- The project uses Object Oriented Programming techniques.
The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
mongoose.h
mongoose.cpp

4- Classes use appropriate access specifiers for class members.
All class data members are explicitly specified as public, protected, or private.
snake.h
mongoose.h

5- Class constructors utilize member initialization lists.
All class members that are set to argument values are initialized through member initialization lists.
mongoose.h:10

6- The project makes use of references in function declarations.
At least two variables are defined as references, or two functions use pass-by-reference in the project code.
mongoose.cpp:8
renderer.cpp:54


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
