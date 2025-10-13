#pragma once
#include "Module.hpp"
#include "View.hpp"
namespace controller {
class Controller {
  view::View* m_ui;
  module::Module* m_processor;

 public:
  void PromptUser();

  void UpdateUI();

  Controller(view::View* ui, module::Module* processor);
};
}  // namespace controller
