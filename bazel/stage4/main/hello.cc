#include <iostream>
#include <string>
#include "lib/hello-time.h"

int main(int argc, char** argv) {
  std::string who = "world";
  if (argc > 1) {
    who = argv[1];
  }
  std::cout << "hello " + who << std::endl;
  print_localtime();
  return 0;
}