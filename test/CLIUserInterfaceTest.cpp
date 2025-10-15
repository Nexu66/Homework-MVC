#include"gtest/gtest.h"
#include"gmock/gmock.h"
#include"impl/CLIUserInterfaceImpl.hpp"
#include<sstream>
using namespace view::impl;
using namespace testing;

TEST(CLIUserInterfaceImpl, PrintPromptTest){
    CLIUserInterfaceImpl object;

    testing::internal::CaptureStdout();

    object.PrintPrompt();

    EXPECT_EQ(internal::GetCapturedStdout(),"1. Enter sequence of int's to add up\n2. Quit\n");

}
TEST(CLIUserInterfaceImpl, PrintResult){
    CLIUserInterfaceImpl object;

    testing::internal::CaptureStdout();

    object.PrintResult(10);

    EXPECT_EQ(internal::GetCapturedStdout(),"Our result is: 10\n");
}
TEST(CLIUserInterfaceImpl, AskForChoise){
    CLIUserInterfaceImpl object;

    std::stringstream buff;
    std::streambuf* origiral_buff = std::cin.rdbuf(buff.rdbuf());

    buff<<"3\n2\n1\n";
    EXPECT_EQ(object.AskForChoise(), view::impl::Option::INVALID);
    EXPECT_EQ(object.AskForChoise(), view::impl::Option::QUIT);
    EXPECT_EQ(object.AskForChoise(), view::impl::Option::ENTER_SEQUENCE);

    std::cin.rdbuf(origiral_buff);
}
TEST(CLIUserInterfaceImpl, AskForSequence){
    CLIUserInterfaceImpl object;

    std::stringstream buff;
    std::streambuf* origiral_buff = std::cin.rdbuf(buff.rdbuf());
    buff<<"\n1 2 3 -4 5\n"; 
    EXPECT_EQ(object.AskForSequence(), "1 2 3 -4 5");

    std::cin.rdbuf(origiral_buff);
}