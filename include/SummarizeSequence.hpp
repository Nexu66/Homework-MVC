#pragma once
#include "interfaces/Module.hpp"

namespace module {
class SummarizeSuquence : public Module {
 private:
  int m_result;
  int ProcessSequence(std::string sequence);
  int GetStoredResult() const noexcept override;

 public:
  SummarizeSuquence() = default;
  ~SummarizeSuquence() = default;
  SummarizeSuquence(const SummarizeSuquence& other) = delete;
  SummarizeSuquence(SummarizeSuquence&& other) = delete;
  SummarizeSuquence& operator=(const SummarizeSuquence& other) = delete;
  SummarizeSuquence& operator=(SummarizeSuquence&& other) = delete;

  friend class Controller;
};
}  // namespace module