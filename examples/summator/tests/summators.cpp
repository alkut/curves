#include <gtest/gtest.h>

#include <cmath>
#include <limits>

#include "../naive/naive_summator.h"
#include "../openMP/openMP_summator.h"
#include "../threads/theads_summator.h"

#include "../../random_generator/generator.h"

static constexpr float eps = std::numeric_limits<float>::epsilon();

TEST(openMP, small) {
  auto sample = curves::generator::generateCircles(10);
  ASSERT_LE(std::fabs(sumNaive(sample) - sumOpenMP(sample)), 10 * eps);
}

TEST(openMP, big) {
  auto sample = curves::generator::generateCircles(1'000'000);
  ASSERT_LE(std::fabs(sumNaive(sample) - sumOpenMP(sample)), 1'000 * eps);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
