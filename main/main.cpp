#include "Lamp.h"

extern "C" {
	void app_main(void);
}

using namespace lamp;

void app_main(void) {
	auto lamp = new Lamp(NULL, NULL);
}
