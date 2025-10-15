#include"gmock/gmock.h"
#include"gtest/gtest.h"
#include"impl/ControllerImpl.hpp"
using namespace testing;

class CLIUserInterfaceMock : public view::View {
    public:
    MOCK_METHOD(char, AskForChoise, (), (const, noexcept));
    MOCK_METHOD(std::string, AskForSequence, (), (const, noexcept));
    MOCK_METHOD(void, PrintPrompt, (), (const, noexcept));
    MOCK_METHOD(void, PrintResult, (int result), (const, noexcept));
};
