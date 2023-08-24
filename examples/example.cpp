#include "curves/Circle.h"
#include "curves/Ellipse.h"
#include "curves/Helix.h"
#include "point/Point.h"
#include "random_generator/generator.h"
#include "summator/threads/theads_summator.h"
#include "summator/openMP/openMP_summator.h"
#include "summator/naive/naive_summator.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <numbers>
#include <cassert>
#include <stdexcept>
#include <ranges>

inline bool isActuallyCircle(const std::shared_ptr<curves::ICurve>& ptr) {
  return dynamic_cast<curves::Circle*>(ptr.get()) != nullptr;
}

inline float getRadius(const std::shared_ptr<curves::ICurve>& ptr) {
  return dynamic_cast<curves::Circle*>(ptr.get())->GetRadius();
}

int main() {
  constexpr std::size_t size = 10;
  std::vector<std::shared_ptr<curves::ICurve>> container1(size);
  for (auto& curve : container1) {
    curve = curves::generator::generate();
  }
  constexpr float time = std::numbers::pi_v<float> / 4.f;
  for (const auto& curve : container1) {
    std::cout << "position in time t = pi / 4: \n"
              << curve->Position(time) << "\nderivative in time t = pi / 4: \n"
              << curve->Derivative(time) << "\n\n";
  }
  std::vector<std::shared_ptr<curves::ICurve>> container2;
  for (const auto& curve :
       container1 | std::ranges::views::filter(isActuallyCircle)) {
    container2.push_back(curve);
  }

  std::sort(container2.begin(), container2.end(),
            [](const auto& lhs, const auto& rhs) -> bool {
              return getRadius(lhs) < getRadius(rhs);
            });

  std::cout << "\n\nRadii of circles:\n";
  for (const auto& circle : container2) {
    std::cout << getRadius(circle) << " ";
  }
  std::cout << "\n";

  std::cout << "\nTotal sum of radii: " << sumOpenMP(container2) << "\n";

  return 0;
}