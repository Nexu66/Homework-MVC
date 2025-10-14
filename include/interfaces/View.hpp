#pragma once
#include <iostream>
#include <sstream>

namespace view {

class View {
 public:
  virtual char AskForChoise() const noexcept = 0;
  virtual std::string AskForSequence() const noexcept = 0;
  virtual void PrintPrompt() const noexcept = 0;
  virtual void PrintResult(int result) const noexcept = 0;

  virtual ~View() = default;
};
}  // namespace view