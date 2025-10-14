#pragma once
#include "interfaces/View.hpp"
namespace view {

class CLIUserInterface : public View {
 private:
  Option AskForChoise() const noexcept override;
  std::string AskForSequence() const noexcept override;
  void PrintPrompt() const noexcept override;
  void PrintResult(int result) const noexcept override;

 public:
  CLIUserInterface() = default;
  ~CLIUserInterface() = default;
  CLIUserInterface(const CLIUserInterface& other) = delete;
  CLIUserInterface(CLIUserInterface&& other) = delete;
  CLIUserInterface& operator=(const CLIUserInterface& other) = delete;
  CLIUserInterface& operator=(CLIUserInterface&& other) = delete;

  friend class Controller;
};
}  // namespace view