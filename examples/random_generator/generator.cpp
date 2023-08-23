#include "generator.h"

#include <stdexcept>

namespace curves::generator {

constexpr float maxValue  = 100.f;
constexpr std::size_t max = std::numeric_limits<std::size_t>::max();

std::random_device randomDevice;
std::default_random_engine randomEngine(randomDevice());

inline std::size_t random(std::size_t limit = max) {
  return std::uniform_int_distribution<std::size_t>(0, limit)(randomEngine);
}

std::shared_ptr<curves::ICurve> generate() {
  auto type = random(2);
  switch (type) {
    case 0:
      return generateCircle();
    case 1:
      return generateEllipse();
    case 2:
      return generateHelix();
  }
  throw std::runtime_error("something strange happened");
}

std::shared_ptr<curves::ICurve> generateCircle() {
  return curves::Circle::construct(
      {0, 0},
      maxValue * static_cast<float>(random()) / static_cast<float>(max));
}

std::shared_ptr<curves::ICurve> generateEllipse() {
  return curves::Ellipse::construct(
      {0, 0}, maxValue * static_cast<float>(random()) / static_cast<float>(max),
      maxValue * static_cast<float>(random()) / static_cast<float>(max));
}

std::shared_ptr<curves::ICurve> generateHelix() {
  return curves::Helix::construct(
      {0, 0}, maxValue * static_cast<float>(random()) / static_cast<float>(max),
      maxValue * static_cast<float>(random()) / static_cast<float>(max));
}

}  // namespace curves::generator