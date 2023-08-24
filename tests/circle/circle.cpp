#include "tests/utils.hpp"
#include "curves/Circle.hpp"

#include <gtest/gtest.h>

TEST(circle, validation) {
  ASSERT_ANY_THROW(curves::Circle::construct(-1.f));
}

TEST(circle, position) {
  auto circle                     = curves::Circle::construct(1.f);
  curves::point3D<float> expected = {1.f, 0.f, 0.f};
  VerifyEqual(circle->Position(0.f), expected);
}

TEST(circle, derivative) {
  auto circle                      = curves::Circle::construct(1.f);
  curves::vector3D<float> expected = {0.f, 1.f, 0.f};
  VerifyEqual(circle->Derivative(0.f), expected);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
