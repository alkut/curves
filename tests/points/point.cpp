#include "point/Point.h"
#include "../utils.h"

#include <gtest/gtest.h>

TEST(vector, multiply) {
  curves::vector2D<float> vector = {1, 2}, expected = {-3, -6};
  VerifyEqual(vector * -3, expected);
}

TEST(vector, add) {
  curves::vector2D<float> l = {1, 2}, r = {6, -9}, expected = {7, -7};
  VerifyEqual(l + r, expected);
}

TEST(vector, minus) {
  curves::vector2D<float> l = {1, 2}, r = {6, -9}, expected = {-5, 11};
  VerifyEqual(l - r, expected);
}

TEST(vector, add_equal) {
  curves::vector2D<float> l = {1, 2}, r = {6, -9}, expected = {7, -7};
  VerifyEqual(l += r, expected);
}

TEST(vector, minus_equal) {
  curves::vector2D<float> l = {1, 2}, r = {6, -9}, expected = {-5, 11};
  VerifyEqual(l -= r, expected);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
