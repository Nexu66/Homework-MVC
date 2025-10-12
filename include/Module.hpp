#pragma once
#include <sstream>
#include <string>

namespace module {
class Module {
  int result;

 public:
  int ProcessSequence(std::string sequence) {
    result = 0;
    std::istringstream parser{sequence};
    int element = 0;
    while (parser >> element) {
      result += element;
    }
    return result;
  }
};
}  // namespace module
