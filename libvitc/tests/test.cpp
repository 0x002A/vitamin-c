#include <gtest/gtest.h>

extern "C" {
  #include <test.h>
}

TEST(exampleTest, test) {
    EXPECT_EQ(testNumber(),  42);
}
