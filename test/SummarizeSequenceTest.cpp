#include"gtest/gtest.h"
#include"gmock/gmock.h"
#include"impl/SummarizeSequenceImpl.hpp"
using namespace testing;
using namespace module::impl;

TEST(SummarizeSequenceImpl, ProcessSequence){
   SummarizeSequenceImpl object; 

   EXPECT_EQ(object.ProcessSequence("1 2 3 4 5"), 15);
   EXPECT_EQ(object.ProcessSequence("1 -2 3 -4 5"), 3);
}
TEST(SummarizeSequenceImpl, GetStoredResult){
   SummarizeSequenceImpl object;

    object.ProcessSequence("100 200 -100");
    EXPECT_EQ(object.GetStoredResult(), 200);
}
