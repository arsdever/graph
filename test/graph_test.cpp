#include <stdafx.hpp>

#include <gtest/gtest.h>

TEST(SampleTest, Success) { }

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}