#include "impl/ControllerImpl.hpp"

#include "impl/CLIUserInterfaceImpl.hpp"
#include "Controller.hpp"
namespace controller::impl {
void ControllerImpl::PromptUser() const {
  m_ui->PrintPrompt();
  switch (m_ui->AskForChoise()) {
    case view::impl::Option::ENTER_SEQUENCE:
      m_processor->ProcessSequence(m_ui->AskForSequence());
      break;
    case view::impl::Option::QUIT:
      std::cout << "Quitting...\n";
      return;
      break;
  }
}

void ControllerImpl::UpdateUI() const {
  m_ui->PrintResult(m_processor->GetStoredResult());
}

ControllerImpl::ControllerImpl(view::View* ui, module::Module* processor)
    : m_ui{ui}, m_processor{processor} {}
}  // namespace controller::impl

namespace controller {
Controller::Controller(view::View* ui, module::Module* processor)
    : impl{std::make_unique<impl::ControllerImpl>(ui, processor)} {}
Controller::~Controller() {}

void Controller::PromptUser() const { this->impl->PromptUser(); }

void Controller::UpdateUI() const { this->impl->UpdateUI(); }
}  // namespace controller
