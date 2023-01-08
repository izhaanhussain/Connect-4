#include <iostream>

#include "board.hpp"

int main() {
  Board b; 
  InitBoard(b);
  std::string out = BoardToStr(b);
  std::cout << out << std::endl;
}