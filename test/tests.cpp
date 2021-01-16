// Copyright 2020 GHA Test Team
#include <gtest/gtest.h>
#include <string>
#include "postfix.h"

TEST(PostfixTest, test1) {
  std::string inf = "2 + 2";
  std::string postf = infix2postfix(inf);
  std::string expected = "2 2 +";
  EXPECT_EQ(expected, postf);
}
