#include "../utils.h"
#include "curves/Helix.h"

#include <numbers>

#include <gtest/gtest.h>

TEST(helix, validation) {
  ASSERT_ANY_THROW(curves::Helix::construct({0, 0}, -2.f, -1.f));
  ASSERT_ANY_THROW(curves::Helix::construct({0, 0}, -2.f, 1.f));
  ASSERT_NO_THROW(curves::Helix::construct({0, 0}, 2.f, -1.f));
}

TEST(helix, position) {
  auto helix                      = curves::Helix::construct({0, 0}, 1.f, 2.f);
  curves::point3D<float> expected = {1.f, 0.f, 0.f};
  VerifyEqual(helix->Position(0.f), expected);
}

TEST(helix, derivative) {
  auto helix                       = curves::Helix::construct({0, 0}, 1.f, 2.f);
  curves::vector3D<float> expected = {0.f, 1.f,
                                      2.f / (2 * std::numbers::pi_v<float>)};
  VerifyEqual(helix->Derivative(0.f), expected);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
