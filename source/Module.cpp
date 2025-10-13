#include "Module.hpp"
namespace module {

int Module::ProcessSequence(std::string sequence) {
  m_result = 0;
  std::istringstream parser{sequence};
  int element = 0;
  while (parser >> element) {
    m_result += element;
  }
  return m_result;
}
int Module::GetStoredResult() { return m_result; }
}  // namespace module
