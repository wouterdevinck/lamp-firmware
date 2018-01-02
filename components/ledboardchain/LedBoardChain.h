#pragma once

#include "ILedBoardChain.h"
#include "SPI.h"

#define FRAMERATE (120)

namespace lamp {

  class LedBoardChain : public ILedBoardChain {

    public:
      explicit LedBoardChain(SPI* spi, int pinInt);

      void addKeyframe(milliseconds duration, vector<LedValue> keyframe) override;

    private:
      SPI* _spi;

  };

}