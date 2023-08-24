#include "utils.hpp"

namespace curves::utils {

bool isActuallyCircle(const std::shared_ptr<curves::ICurve>& ptr) {
  return dynamic_cast<curves::Circle*>(ptr.get()) != nullptr;
}

float getRadius(const std::shared_ptr<curves::ICurve>& ptr) {
  return dynamic_cast<curves::Circle*>(ptr.get())->GetRadius();
}

}  // namespace curves::utils