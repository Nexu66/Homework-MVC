#pragma once
#include "Module.hpp"
#include "View.hpp"
namespace controller {
class Controller {
  view::View* m_ui;
  module::Module* m_processor;

 public:
  std::string PromptUser() {
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

  int ProcessSequence(std::string sequence) {
    return m_processor->ProcessSequence(sequence);
  }

  void UpdateUI(int result) { m_ui->PrintResult(result); }

  Controller(view::View* ui, module::Module* processor)
      : m_ui{ui}, m_processor{processor} {}
};
}  // namespace controller
