#include <iostream>
#include <string>

int main() {
  int numberA;
  int numberB;
  std::string operation;

  std::cout << "Number1: ";
  std::cin >> numberA;

  std::cout << "Number2: ";
  std::cin >> numberB;

  std::cout << "Operation: ";
  std::cin >> operation;

  int result;

  if (operation == "add") {
    result = numberA + numberB;
  } else if (operation == "sub") {
    result = numberA - numberB;
  } else {
    std::cerr << "Operation not supported!\n";
    return 1;
  }

  std::cout << result << std::endl;

  return 0;
}
