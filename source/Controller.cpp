#include "Controller.hpp"
namespace controller {
std::string Controller::PromptUser() {
  m_ui->PrintPrompt();
  switch (m_ui->AskForChoise()) {
    case view::Option::ENTER_SEQUENCE:
      return m_ui->AskForSequence();
      break;
    case view::Option::QUIT:
      std::cout << "Quitting...\n";
      break;
  }
  return std::string{};
}

int Controller::ProcessSequence(std::string sequence) {
  return m_processor->ProcessSequence(sequence);
}

void Controller::UpdateUI(int result) { m_ui->PrintResult(result); }

Controller::Controller(view::View* ui, module::Module* processor)
    : m_ui{ui}, m_processor{processor} {}
}  // namespace controller
