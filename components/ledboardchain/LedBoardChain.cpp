#include "LedBoardChain.h"

using namespace lamp;

LedBoardChain::LedBoardChain(SPI* spi, int pinInt) {
  _spi = spi;
  _ready = true;

  // TODO
  // addISRHandler
  // setInterruptType PIO_INTR_NEGEDGE
  // interruptEnable
}

void LedBoardChain::addKeyframe(KeyFrame keyframe) {
  _frames.push(keyframe);
  if(_ready && !_frames.empty()) transferNextKeyframe();
}

void LedBoardChain::transferNextKeyframe() {
  // TODO
}