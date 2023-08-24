#include "tests/utils.hpp"
#include "curves/Ellipse.hpp"

#include <gtest/gtest.h>

TEST(ellipse, validation) {
  ASSERT_ANY_THROW(curves::Ellipse::construct(2.f, -1.f));
  ASSERT_ANY_THROW(curves::Ellipse::construct(-2.f, 1.f));
}

TEST(ellipse, position) {
  auto ellipse                    = curves::Ellipse::construct(1.f, 2.f);
  curves::point3D<float> expected = {1.f, 0.f, 0.f};
  VerifyEqual(ellipse->Position(0.f), expected);
}

TEST(ellipse, derivative) {
  auto ellipse                     = curves::Ellipse::construct(1.f, 2.f);
  curves::vector3D<float> expected = {0.f, 2.f, 0.f};
  VerifyEqual(ellipse->Derivative(0.f), expected);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
