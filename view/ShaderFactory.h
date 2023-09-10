#ifndef CPP4_3DVIEWER_V2_0_VIEW_SHADERFACTORY_H_
#define CPP4_3DVIEWER_V2_0_VIEW_SHADERFACTORY_H_

#include "ShaderStates/ShaderCustomizableLines.h"
#include "ShaderStates/ShaderEverythingButSlow.h"
#include "ShaderStates/ShaderNoGeometry.h"
#include "ShaderStates/ShaderPointsOnly.h"
#include "ShaderStates/ShaderState.h"

namespace s21 {
class ShaderFactory {
 public:
  enum ShaderVersion {
    kLinesOnly,
    kCustomizableLines,
    kPointsOnly,
    kEverything
  };
  /**
   * @brief Creates and returns const object of shader class
   */
  [[nodiscard]] const ShaderState* create(enum ShaderVersion sv) const {
    switch (sv) {
      case kLinesOnly:
        return new const ShaderNoGeometry();
      case kCustomizableLines:
        return new const ShaderCustomizableLines();
      case kPointsOnly:
        return new const ShaderPointsOnly();
      case kEverything:
        return new const ShaderEverythingButSlow();
    }
  }
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_VIEW_VIEW_SHADERFACTORY_H_
