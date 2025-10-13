#include <iostream>
#include <sstream>

namespace view {
enum Option { ENTER_SEQUENCE = '1', QUIT = '2' };

class View {
 public:
  Option AskForChoise();
  std::string AskForSequence();
  void PrintPrompt();
  void PrintResult(int result);
};
}  // namespace view