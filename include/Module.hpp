#pragma once
#include <sstream>
#include <string>

namespace module {
class Module {
  int m_result;

 public:
  int ProcessSequence(std::string sequence);
  int GetStoredResult();
};
}  // namespace module
