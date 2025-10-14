#include "CLIUserInterface.hpp"

namespace view {

void CLIUserInterface::PrintPrompt() const noexcept {
  std::cout << "1. Enter sequence of int's to add up\n2. Quit\n";
}

void CLIUserInterface::PrintResult(int result) const noexcept {
  std::cout << "Our result is: " << result << "\n";
}

Option CLIUserInterface::AskForChoise() const noexcept {
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

std::string CLIUserInterface::AskForSequence() const noexcept {
  std::cin.ignore();
  std::cout << "Please, enter your sequence: ";
  std::string sequence;
  std::getline(std::cin, sequence);
  return sequence;
}

}  // namespace view