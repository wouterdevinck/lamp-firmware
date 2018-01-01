#pragma once

#include "ILedBoardChain.h"
#include "SPI.h"

namespace lamp {

  class LedBoardChain : public ILedBoardChain {

    public:
      explicit LedBoardChain(spi_host_device_t spiHost, int pinMosi, int pinMiso, int pinClk, int pinCs, int pinInt);

      void addKeyframe(milliseconds duration, vector<LedValue> keyframe) override;

    private:
      SPI* _spi;

  };

}