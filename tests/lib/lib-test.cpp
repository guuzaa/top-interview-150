#include "lib/lib.h"

#include <gtest/gtest.h>

TEST(AdditionTest, HandlesPositiveInput) {
  EXPECT_EQ(add(1, 2), 3);
  EXPECT_EQ(add(10, 20), 30);
}

TEST(AdditionTest, HandlesNegativeInput) {
  EXPECT_EQ(add(-1, -2), -3);
  EXPECT_EQ(add(-10, -20), -30);
}
