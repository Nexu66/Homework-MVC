#pragma once
#include <memory>

#include "interfaces/View.hpp"
namespace view {

namespace impl {
class CLIUserInterfaceImpl;
}  // namespace impl

class CLIUserInterface : public View {
 private:
  std::unique_ptr<impl::CLIUserInterfaceImpl> impl;

  char AskForChoise() const noexcept override;
  std::string AskForSequence() const noexcept override;
  void PrintPrompt() const noexcept override;
  void PrintResult(int result) const noexcept override;

 public:
  CLIUserInterface();
  ~CLIUserInterface();
  CLIUserInterface(const CLIUserInterface& other) = delete;
  CLIUserInterface(CLIUserInterface&& other) = delete;
  CLIUserInterface& operator=(const CLIUserInterface& other) = delete;
  CLIUserInterface& operator=(CLIUserInterface&& other) = delete;

  friend class Controller;
};
}  // namespace view