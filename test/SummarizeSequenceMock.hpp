#include"gmock/gmock.h"
#include"gtest/gtest.h"
#include"impl/ControllerImpl.hpp"
using namespace testing;

class SummarizeSequenceMock : public module::Module {
    public:
    MOCK_METHOD(void , ProcessSequence, (std::string sequence));
    MOCK_METHOD(int, GetStoredResult, (), (const, noexcept));
};