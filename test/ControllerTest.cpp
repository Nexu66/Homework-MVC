#include"CLIUserInterfaceMock.hpp"
#include"SummarizeSequenceMock.hpp"
#include"impl/ControllerImpl.hpp"
using namespace controller::impl;

class ControllerTest : public Test{
    protected:
    CLIUserInterfaceMock* ui;
    SummarizeSequenceMock* processor;
    ControllerTest() : ui{new CLIUserInterfaceMock},
    processor{new SummarizeSequenceMock} {}
};

TEST_F(ControllerTest, PromptUserInvalidQuit){
    InSequence sequence;
    EXPECT_CALL(*ui, PrintPrompt());
    EXPECT_CALL(*ui, AskForChoise())
    .WillOnce(Return('3'))
    .WillOnce(Return('g'))
    .WillOnce(Return('2'));

    ControllerImpl object{ui, processor};
    object.PromptUser();
}
TEST_F(ControllerTest, PromptUserQuit){
    InSequence sequence;
    EXPECT_CALL(*ui, PrintPrompt());
    EXPECT_CALL(*ui, AskForChoise())
    .WillOnce(Return('2'));

    ControllerImpl object{ui, processor};
    object.PromptUser();
}
TEST_F(ControllerTest, PromptUserEnterSequence){
    InSequence sequence;
    EXPECT_CALL(*ui, PrintPrompt());
    EXPECT_CALL(*ui, AskForChoise())
    .WillOnce(Return('1'));
    std::string numbers{"30 -15 100 -4 0"};
    EXPECT_CALL(*ui, AskForSequence())
    .WillOnce(Return(numbers));
    EXPECT_CALL(*processor, ProcessSequence(numbers));

    ControllerImpl object{ui, processor};
    object.PromptUser();
}