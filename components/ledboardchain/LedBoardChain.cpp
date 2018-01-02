#include "LedBoardChain.h"

using namespace lamp;

LedBoardChain::LedBoardChain(SPI* spi, int pinInt) {
  _spi = spi;

  // TODO
  // addISRHandler
  // setInterruptType PIO_INTR_NEGEDGE
  // interruptEnable
}

void LedBoardChain::addKeyframe(milliseconds duration, vector<LedValue> keyframe) {
  // TODO
}