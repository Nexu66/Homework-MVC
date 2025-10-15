#include"gtest/gtest.h"
#include"gmock/gmock.h"
#include"impl/CLIUserInterfaceImpl.hpp"
#include<sstream>
#include<future>
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
TEST(CLIUserInterfaceImpl, AskForChoise_InvalidChoise){
    CLIUserInterfaceImpl object;

    testing::internal::CaptureStderr();

    std::stringstream buff;
    buff<<'3';

    std::streambuf* origiral_buff = std::cin.rdbuf();
    std::cin.rdbuf(buff.rdbuf());
    std::string error_message;
    auto future = std::async([&]{return object.AskForChoise();});
    while(true){
        if(std::cin.gcount() == 0)
        {
            error_message = internal::GetCapturedStderr();
            buff << '2';
            break;
        }
    }
    EXPECT_EQ(future.get(), '2');
    EXPECT_EQ(error_message ,"Enter your option:  \nInvalid option, please try again\n");

}