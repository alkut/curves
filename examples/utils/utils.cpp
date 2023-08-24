#include "utils.hpp"

#include <stdexcept>

namespace curves::utils {

bool isCircle(const std::shared_ptr<curves::ICurve>& ptr) noexcept {
  return dynamic_cast<curves::Circle*>(ptr.get()) != nullptr;
}

float getRadius(const std::shared_ptr<curves::ICurve>& ptr) {
  auto circle = dynamic_cast<curves::Circle*>(ptr.get());
  if (circle == nullptr) {
    throw std::invalid_argument("not a circle under ICurve pointer");
  }
  return circle->GetRadius();
}

}  // namespace curves::utils