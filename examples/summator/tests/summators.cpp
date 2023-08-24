#include <gtest/gtest.h>

#include <cmath>
#include <limits>

#include "../naive/naive_summator.hpp"
#include "../openMP/openMP_summator.hpp"
#include "../threads/theads_summator.hpp"
#include "../execution_policy/execution_policy_summator.hpp"

#include "../../random_generator/generator.hpp"

static constexpr float eps = std::numeric_limits<float>::epsilon();

TEST(openMP, small) {
  for (std::size_t i = 0; i < 1000; ++i) {
    auto sample = curves::generator::generateCircles(10);
    ASSERT_LE(std::fabs(curves::summators::sumNaive(sample) -
                        curves::summators::sumOpenMP(sample)),
              10 * eps);
  }
}

TEST(openMP, big) {
  for (std::size_t i = 0; i < 10; ++i) {
    auto sample = curves::generator::generateCircles(1'000);
    ASSERT_LE(std::fabs(curves::summators::sumNaive(sample) -
                        curves::summators::sumOpenMP(sample)),
              10'000 * eps);
  }
}

TEST(threads, small) {
  for (std::size_t i = 0; i < 1000; ++i) {
    auto sample = curves::generator::generateCircles(10);
    ASSERT_LE(std::fabs(curves::summators::sumNaive(sample) -
                        curves::summators::sumThreads(sample)),
              10 * eps);
  }
}

TEST(threads, big) {
  for (std::size_t i = 0; i < 10; ++i) {
    auto sample = curves::generator::generateCircles(1'000);
    ASSERT_LE(std::fabs(curves::summators::sumNaive(sample) -
                        curves::summators::sumThreads(sample)),
              10'000 * eps);
  }
}

TEST(policy, small) {
  for (std::size_t i = 0; i < 1000; ++i) {
    auto sample = curves::generator::generateCircles(10);
    ASSERT_LE(std::fabs(curves::summators::sumNaive(sample) -
                        curves::summators::sumPolicy(sample)),
              10 * eps);
  }
}

TEST(policy, big) {
  for (std::size_t i = 0; i < 10; ++i) {
    auto sample = curves::generator::generateCircles(1'000);
    ASSERT_LE(std::fabs(curves::summators::sumNaive(sample) -
                        curves::summators::sumPolicy(sample)),
              10'000 * eps);
  }
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
