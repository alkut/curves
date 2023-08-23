#include "../utils.h"
#include "curves/Circle.h"

#include <gtest/gtest.h>

TEST(circle, validation) {
  ASSERT_ANY_THROW(curves::Circle::construct({0, 0}, -1.f));
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
