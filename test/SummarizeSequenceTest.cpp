#include"gtest/gtest.h"
#include"gmock/gmock.h"
#include"impl/SummarizeSequenceImpl.hpp"
using namespace testing;
using namespace module::impl;

TEST(SummarizeSequenceImpl, ProcessSequence){
   SummarizeSequenceImpl object; 
   object.ProcessSequence("1 2 3 4 5");
   EXPECT_EQ(15, object.m_result);
   object.ProcessSequence("1 -2 3 -4 5");
   EXPECT_EQ(3, object.m_result);
}
TEST(SummarizeSequenceImpl, GetStoredResult){
   SummarizeSequenceImpl object;

    object.ProcessSequence("100 200 -100");
    EXPECT_EQ(object.GetStoredResult(), 200);
}
