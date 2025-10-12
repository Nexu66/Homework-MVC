#include "View.hpp"

namespace view {

void View::PrintPrompt() {
  std::cout << "1. Enter sequence of int's\n2. Quit\n";
}

void View::PrintResult(int result) {
  std::cout << "Our result is: " << result << "\n";
}

Option View::AskForChoise() {
  while (true) {
    std::cerr << "Enter your option: ";
    int choise = std::cin.peek();
    if (choise == '1' || choise == '2') {
      std::cin >> choise;
      switch (choise) {
        case Option::ENTER_SEQUENCE:
          return Option::ENTER_SEQUENCE;
          break;
        case Option::QUIT:
          return Option::QUIT;
        default:
          return Option::ENTER_SEQUENCE;
          break;
      }
    }
    std::cerr << "\nInvalid option, please try again\n";

    std::cin.ignore(2, '\n');
  }
}

std::string View::AskForSequence() {
  std::cin.ignore();
  std::cout << "Please, enter your sequence: ";
  std::string sequence;
  std::getline(std::cin, sequence);
  return sequence;
}

}  // namespace view