#include"gtest/gtest.h"
#include"gmock/gmock.h"
#include"impl/CLIUserInterfaceImpl.hpp"
using namespace view::impl;
using namespace testing;

TEST(CLIUserInterfaceImpl, PrintPromptTest){
    CLIUserInterfaceImpl object;

    testing::internal::CaptureStdout();

    object.PrintPrompt();

    EXPECT_EQ(internal::GetCapturedStdout(),"1. Enter sequence of int's to add up\n2. Quit\n");

}