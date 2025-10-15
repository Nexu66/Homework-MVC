
#pragma once
#include <string>

namespace module::impl {
class SummarizeSequenceImpl {
 public:
  int m_result;
  int ProcessSequence(std::string sequence);
  int GetStoredResult() const noexcept;
};
}  // namespace module::impl