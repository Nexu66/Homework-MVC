#include "View.hpp"

namespace view {

void View::PrintPrompt() {
  std::cout << "1. Enter sequence of int's to add up\n2. Quit\n";
}

void View::PrintResult(int result) {
  std::cout << "Our result is: " << result << "\n";
}

Option View::AskForChoise() {
  while (true) {
    std::cerr << "Enter your option: ";
    std::string choise;
    std::cin >> choise;
    if ((choise[0] == '1' || choise[0] == '2') && choise.size() == 1) {
      switch (choise[0]) {
        case Option::ENTER_SEQUENCE:
          return Option::ENTER_SEQUENCE;
          break;
        case Option::QUIT:
          return Option::QUIT;
      }
    }
    std::cerr << "\nInvalid option, please try again\n";
    choise.clear();
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