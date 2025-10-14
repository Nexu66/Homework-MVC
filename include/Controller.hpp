#pragma once
#include "CLIUserInterface.hpp"
#include "SummarizeSequence.hpp"
namespace controller {
class Controller {
  view::View* m_ui;
  module::Module* m_processor;

 public:
  void PromptUser() const;

  void UpdateUI() const;

  Controller(view::View* ui, module::Module* processor);
};
}  // namespace controller
