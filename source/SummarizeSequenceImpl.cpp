#include "impl/SummarizeSequenceImpl.hpp"

#include "SummarizeSequence.hpp"
namespace module::impl {

int SummarizeSequenceImpl::ProcessSequence(std::string sequence) {
  m_result = 0;
  std::istringstream parser{sequence};
  int element = 0;
  while (parser >> element) {
    m_result += element;
  }
  return m_result;
}
int SummarizeSequenceImpl::GetStoredResult() const noexcept { return m_result; }
}  // namespace module::impl

namespace module {
SummarizeSequence::SummarizeSequence()
    : m_impl{std::make_unique<impl::SummarizeSequenceImpl>()} {}
SummarizeSequence::~SummarizeSequence() {}
int SummarizeSequence::ProcessSequence(std::string sequence) {
  return this->m_impl->ProcessSequence(std::move(sequence));
}
int SummarizeSequence::GetStoredResult() const noexcept {
  return this->m_impl->GetStoredResult();
}
}  // namespace module
