#include "LedBoardChain.h"

using namespace lamp;

LedBoardChain::LedBoardChain(spi_host_device_t spiHost, int pinMosi, int pinMiso, int pinClk, int pinCs, int pinInt) {
  _spi = new SPI(spiHost, pinMosi, pinMiso, pinClk, pinCs);
}

void LedBoardChain::addKeyframe(milliseconds duration, vector<LedValue> keyframe) {
  // TODO
}