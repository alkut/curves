#include "Point.h"
#include "utils.h"
#include <gtest/gtest.h>

TEST(vector, multiply) {
    curves::vector2D<float> vector = {1, 2};
    float scalar = -3;
    curves::vector2D<float> expected = {-3, -6};
    VerifyEqual(vector * scalar, expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



