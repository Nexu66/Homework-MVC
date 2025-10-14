#pragma once
#include <iostream>
#include <sstream>

namespace view {
enum Option { ENTER_SEQUENCE = '1', QUIT = '2' };

class View {
 public:
  virtual Option AskForChoise() const noexcept = 0;
  virtual std::string AskForSequence() const noexcept = 0;
  virtual void PrintPrompt() const noexcept = 0;
  virtual void PrintResult(int result) const noexcept = 0;

  virtual ~View() = default;
};
}  // namespace view