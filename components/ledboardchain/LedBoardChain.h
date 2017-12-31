#pragma once

#include "ILedBoardChain.h"

namespace lamp {

  class LedBoardChain : public ILedBoardChain {

    public:
      explicit LedBoardChain();

      void addKeyframe(milliseconds duration, vector<LedValue> keyframe) override;

  };

}