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

    testing::internal::CaptureStderr();

    std::stringstream buff;
    buff<<'3';
    std::streambuf* origiral_buff = std::cin.rdbuf(buff.rdbuf());

    EXPECT_EQ(object.AskForChoise(), view::impl::Option::INVALID);
    
    buff<<'2';
    EXPECT_EQ(object.AskForChoise(), view::impl::Option::QUIT);
    
    buff<<'1';
    EXPECT_EQ(object.AskForChoise(), view::impl::Option::ENTER_SEQUENCE);

    EXPECT_EQ(testing::internal::GetCapturedStderr(),"Enter your option: Enter your option: Enter your option: ");

    std::cin.rdbuf(origiral_buff);
}