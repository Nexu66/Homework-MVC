#include "impl/ControllerImpl.hpp"

#include "Controller.hpp"
#include "impl/CLIUserInterfaceImpl.hpp"
namespace controller::impl {
void ControllerImpl::PromptUser() const {
  m_ui->PrintPrompt();
  while (true) {
    switch (m_ui->AskForChoise()) {
      case view::impl::Option::ENTER_SEQUENCE:
        m_processor->ProcessSequence(m_ui->AskForSequence());
        return;
      case view::impl::Option::QUIT:
        std::cout << "Quitting...\n";
        return;
      case view::impl::Option::INVALID:
        std::cerr << "Invalid option, please try again\n";
    }
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
    : m_impl{std::make_unique<impl::ControllerImpl>(ui, processor)} {}
Controller::~Controller() {}

void Controller::PromptUser() const { this->m_impl->PromptUser(); }

void Controller::UpdateUI() const { this->m_impl->UpdateUI(); }
}  // namespace controller
