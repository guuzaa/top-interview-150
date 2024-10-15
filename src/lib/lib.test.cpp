#include "lib/lib.h"

#include <gtest/gtest.h>

TEST(UnitTest, HandlesPositiveInput) {
  EXPECT_EQ(add(1, 2), 3);
  EXPECT_EQ(add(10, 20), 30);
}

TEST(UnitTest, HandlesNegativeInput) {
  EXPECT_EQ(add(-1, -2), -3);
  EXPECT_EQ(add(-10, -20), -30);
}