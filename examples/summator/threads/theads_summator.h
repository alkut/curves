#ifndef CURVES_THEADS_SUMMATOR_H
#define CURVES_THEADS_SUMMATOR_H

#include <curves/Circle.h>
#include <vector>

namespace curves::summators {

float sumThreads(const std::vector<std::shared_ptr<curves::ICurve>>& container);

}

#endif  // CURVES_THEADS_SUMMATOR_H
