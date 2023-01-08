#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "functions.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./bin/exec word" << std::endl;
    return 1;
  }

  std::string word = argv[1];

  // std::string phonetics;
  // std::cout << phonetics << std::endl;

  std::cout << Replace(word) << std::endl;
}