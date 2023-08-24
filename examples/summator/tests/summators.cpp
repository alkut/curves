#include <gtest/gtest.h>

#include <cmath>
#include <limits>

#include "../naive/naive_summator.h"
#include "../openMP/openMP_summator.h"
#include "../threads/theads_summator.h"
#include "../execution_policy/execution_policy_summator.h"

#include "../../random_generator/generator.h"

static constexpr float eps = std::numeric_limits<float>::epsilon();

TEST(openMP, small) {
  for (std::size_t i = 0; i < 1000; ++i) {
    auto sample = curves::generator::generateCircles(10);
    ASSERT_LE(std::fabs(sumNaive(sample) - sumOpenMP(sample)), 10 * eps);
  }
}

TEST(openMP, big) {
  for (std::size_t i = 0; i < 10; ++i) {
    auto sample = curves::generator::generateCircles(1'000);
    ASSERT_LE(std::fabs(sumNaive(sample) - sumOpenMP(sample)), 10'000 * eps);
  }
}

TEST(threads, small) {
  for (std::size_t i = 0; i < 1000; ++i) {
    auto sample = curves::generator::generateCircles(10);
    ASSERT_LE(std::fabs(sumNaive(sample) - sumThreads(sample)), 10 * eps);
  }
}

TEST(threads, big) {
  for (std::size_t i = 0; i < 10; ++i) {
    auto sample = curves::generator::generateCircles(1'000);
    ASSERT_LE(std::fabs(sumNaive(sample) - sumThreads(sample)), 10'000 * eps);
  }
}

TEST(policy, small) {
  for (std::size_t i = 0; i < 1000; ++i) {
    auto sample = curves::generator::generateCircles(10);
    ASSERT_LE(std::fabs(sumNaive(sample) - sumPolicy(sample)), 10 * eps);
  }
}

TEST(policy, big) {
  for (std::size_t i = 0; i < 10; ++i) {
    auto sample = curves::generator::generateCircles(1'000);
    ASSERT_LE(std::fabs(sumNaive(sample) - sumPolicy(sample)), 10'000 * eps);
  }
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
