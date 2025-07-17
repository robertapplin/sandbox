#include <iostream>


int main(int argc, char *argv[]) {
  std::cout << "In main..." << std::endl;

  int* ptr = nullptr;
  std::cout << *ptr << std::endl;  // Dereferencing nullptr causes crash

  return 0;
}
