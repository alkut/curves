#include "../utils.h"
#include "curves/Circle.h"

#include <gtest/gtest.h>

TEST(circle, validation) {
  ASSERT_ANY_THROW(curves::Circle::construct({0, 0}, -1.f));
}

TEST(circle, position) {
  auto circle                     = curves::Circle::construct({0, 0}, 1.f);
  curves::point3D<float> expected = {1.f, 0.f};
  VerifyEqual(circle->Position(0.f), expected);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
