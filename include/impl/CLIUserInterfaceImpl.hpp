#include <string>
namespace view::impl {

enum Option { ENTER_SEQUENCE = '1', QUIT = '2' };
class CLIUserInterfaceImpl {
 public:
  char AskForChoise() const noexcept;
  std::string AskForSequence() const noexcept;
  void PrintPrompt() const noexcept;
  void PrintResult(int result) const noexcept;
};
}  // namespace view::impl