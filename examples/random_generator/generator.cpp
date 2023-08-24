#include "generator.hpp"

#include <stdexcept>
#include <utility>
#include <memory>

namespace curves::generator {

constexpr float maxValue  = 1.f;
constexpr std::size_t max = std::numeric_limits<std::size_t>::max();

std::random_device randomDevice;
std::default_random_engine randomEngine(randomDevice());

inline std::size_t random(std::size_t limit = max) {
  return std::uniform_int_distribution<std::size_t>(0, limit)(randomEngine);
}

std::shared_ptr<curves::ICurve> generate() noexcept {
  auto type = random(2);
  switch (type) {
    case 0:
      return generateCircle();
    case 1:
      return generateEllipse();
    case 2:
      return generateHelix();
  }
  std::unreachable();
}

std::vector<std::shared_ptr<curves::ICurve>> generateCircles(
    std::size_t count) noexcept {
  std::vector<std::shared_ptr<curves::ICurve>> res(count);
  for (auto& curve : res) {
    curve = generateCircle();
  }
  return res;
}

std::shared_ptr<curves::ICurve> generateCircle() noexcept {
  while (true) {
    try {
      return curves::Circle::construct(maxValue * static_cast<float>(random()) /
                                       static_cast<float>(max));
    } catch (const std::invalid_argument& ex) {
      std::cerr << ex.what() << "\n";
    }
  }
}

std::shared_ptr<curves::ICurve> generateEllipse() noexcept {
  while (true) {
    try {
      return curves::Ellipse::construct(
          maxValue * static_cast<float>(random()) / static_cast<float>(max),
          maxValue * static_cast<float>(random()) / static_cast<float>(max));
    } catch (const std::invalid_argument& ex) {
      std::cerr << ex.what() << "\n";
    }
  }
}

std::shared_ptr<curves::ICurve> generateHelix() noexcept {
  while (true) {
    try {
      return curves::Helix::construct(
          maxValue * static_cast<float>(random()) / static_cast<float>(max),
          maxValue * static_cast<float>(random()) / static_cast<float>(max));
    } catch (const std::invalid_argument& ex) {
      std::cerr << ex.what() << "\n";
    }
  }
}

}  // namespace curves::generator
