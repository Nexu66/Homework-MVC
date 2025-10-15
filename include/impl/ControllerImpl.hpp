#pragma once
#include "interfaces/Module.hpp"
#include "interfaces/View.hpp"
namespace controller::impl {
class ControllerImpl {
 public:
  view::View* m_ui;
  module::Module* m_processor;
  void PromptUser() const;

  void UpdateUI() const;

  ControllerImpl(view::View* ui, module::Module* processor);
  ~ControllerImpl();
};
}  // namespace controller::impl
