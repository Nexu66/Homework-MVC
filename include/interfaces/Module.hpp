#pragma once
#include <sstream>
#include <string>

namespace module {
class Module {
 public:
  int m_result;
  virtual int ProcessSequence(std::string sequence) = 0;
  virtual int GetStoredResult() const noexcept = 0;

  virtual ~Module() = default;
};
}  // namespace module
