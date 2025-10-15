#include "impl/CLIUserInterfaceImpl.hpp"

#include "CLIUserInterface.hpp"

namespace view::impl {

void CLIUserInterfaceImpl::PrintPrompt() const noexcept {
  std::cout << "1. Enter sequence of int's to add up\n2. Quit\n";
}

void CLIUserInterfaceImpl::PrintResult(int result) const noexcept {
  std::cout << "Our result is: " << result << "\n";
}

char CLIUserInterfaceImpl::AskForChoise() const noexcept {
  std::cerr << "Enter your option: ";
  char choise;
  std::cin >> choise;
  switch (choise) {
    case Option::ENTER_SEQUENCE:
      return Option::ENTER_SEQUENCE;
      break;
    case Option::QUIT:
      return Option::QUIT;
  }
  return Option::INVALID;
}

std::string CLIUserInterfaceImpl::AskForSequence() const noexcept {
  std::cin.ignore();
  std::cout << "Please, enter your sequence: ";
  std::string sequence;
  std::getline(std::cin, sequence);
  return sequence;
}

}  // namespace view::impl

namespace view {
CLIUserInterface::CLIUserInterface()
    : m_impl{std::make_unique<impl::CLIUserInterfaceImpl>()} {}
CLIUserInterface::~CLIUserInterface() {}
char CLIUserInterface::AskForChoise() const noexcept {
  return this->m_impl->AskForChoise();
}
std::string CLIUserInterface::AskForSequence() const noexcept {
  return this->m_impl->AskForSequence();
}
void CLIUserInterface::PrintPrompt() const noexcept {
  this->m_impl->PrintPrompt();
}
void CLIUserInterface::PrintResult(int result) const noexcept {
  this->m_impl->PrintResult(result);
}
}  // namespace view
