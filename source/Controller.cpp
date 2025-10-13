#include "Controller.hpp"
namespace controller {
void Controller::PromptUser() {
  m_ui->PrintPrompt();
  switch (m_ui->AskForChoise()) {
    case view::Option::ENTER_SEQUENCE:
      m_processor->ProcessSequence(m_ui->AskForSequence());
      break;
    case view::Option::QUIT:
      std::cout << "Quitting...\n";
      return;
      break;
  }
}

void Controller::UpdateUI() {
  m_ui->PrintResult(m_processor->GetStoredResult());
}

Controller::Controller(view::View* ui, module::Module* processor)
    : m_ui{ui}, m_processor{processor} {}
}  // namespace controller
