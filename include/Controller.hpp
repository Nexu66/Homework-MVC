#pragma once
#include "Module.hpp"
#include "View.hpp"
namespace controller {
class Controller {
  view::View* m_ui;
  module::Module* m_processor;

 public:
  std::string PromptUser();

  int ProcessSequence(std::string sequence);

  void UpdateUI(int result);

  Controller(view::View* ui, module::Module* processor);
};
}  // namespace controller
