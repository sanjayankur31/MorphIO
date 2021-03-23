#pragma once

#include <cmath>  // M_PI
#include <memory>  // std::shared_ptr
#include <string>  // std::string
#include <utility>  // std::pair, std::tuple

#include <gsl/gsl>
#include <morphio/enums.h>


/** @namespace morphio Blue Brain File IO classes */
namespace morphio {
#ifdef MORPHIO_USE_DOUBLE
using floatType = double;
constexpr floatType epsilon = 1e-6;
constexpr floatType PI = M_PI;
#else
using floatType = float;
constexpr floatType epsilon = 1e-6f;
constexpr floatType PI = static_cast<floatType>(M_PI);
#endif


using namespace enums;

class EndoplasmicReticulum;
class MitoSection;
class Mitochondria;
class Morphology;
class Section;
class Soma;

namespace Property {
struct Properties;
}

namespace vasculature {
class Section;
class Vasculature;
}  // namespace vasculature

namespace readers {
struct DebugInfo;
class ErrorMessages;
}  // namespace readers

namespace mut {
class EndoplasmicReticulum;
class MitoSection;
class Mitochondria;
class Morphology;
class Section;
class Soma;
}  // namespace mut

using SectionRange = std::pair<size_t, size_t>;

/**
 * A tuple (file format (std::string), major version, minor version)
 */
using MorphologyVersion = std::tuple<std::string, uint32_t, uint32_t>;

template <typename T>
using range = gsl::span<T>;

}  // namespace morphio
