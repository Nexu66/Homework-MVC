#pragma once
#include <memory>

#include "interfaces/Module.hpp"

namespace module {
namespace impl {
class SummarizeSequenceImpl;
}  // namespace impl

class SummarizeSequence : public Module {
 private:
  std::unique_ptr<impl::SummarizeSequenceImpl> m_impl;
  void ProcessSequence(std::string sequence);
  int GetStoredResult() const noexcept override;

 public:
  SummarizeSequence();
  ~SummarizeSequence();
  SummarizeSequence(const SummarizeSequence& other) = delete;
  SummarizeSequence(SummarizeSequence&& other) = delete;
  SummarizeSequence& operator=(const SummarizeSequence& other) = delete;
  SummarizeSequence& operator=(SummarizeSequence&& other) = delete;

  friend class Controller;
};
}  // namespace module