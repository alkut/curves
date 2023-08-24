#include "curves/Circle.h"
#include "curves/Ellipse.h"
#include "curves/Helix.h"
#include "point/Point.h"
#include "random_generator/generator.h"
#include "summator/threads/theads_summator.h"
#include "summator/openMP/openMP_summator.h"
#include "summator/naive/naive_summator.h"
#include "summator/execution_policy/execution_policy_summator.h"
#include "utils/utils.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <numbers>
#include <ranges>

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
  for (const auto& curve : container1 | std::ranges::views::filter(
                                            curves::utils::isActuallyCircle)) {
    container2.push_back(curve);
  }

  std::sort(container2.begin(), container2.end(),
            [](const auto& lhs, const auto& rhs) -> bool {
              return curves::utils::getRadius(lhs) <
                     curves::utils::getRadius(rhs);
            });

  std::cout << "\n\nRadii of circles:\n";
  for (const auto& circle : container2) {
    std::cout << curves::utils::getRadius(circle) << " ";
  }
  std::cout << "\n";

  std::cout << "\nTotal sum of radii using naive approach: "
            << curves::summators::sumNaive(container2) << "\n";
  std::cout << "\nTotal sum of radii using openMP approach: "
            << curves::summators::sumOpenMP(container2) << "\n";
  std::cout << "\nTotal sum of radii using threads approach: "
            << curves::summators::sumThreads(container2) << "\n";
  std::cout << "\nTotal sum of radii using execution policy approach: "
            << curves::summators::sumPolicy(container2) << "\n";
  return 0;
}