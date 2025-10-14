#pragma once
#include <memory>

#include "CLIUserInterface.hpp"
#include "SummarizeSequence.hpp"
namespace controller {
namespace impl {
class ControllerImpl;
}
class Controller {
  std::unique_ptr<impl::ControllerImpl> impl;

 public:
  void PromptUser() const;

  void UpdateUI() const;

  Controller(view::View* ui, module::Module* processor);
  ~Controller();
};
}  // namespace controller
