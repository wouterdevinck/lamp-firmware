#pragma once

#define HTTP_PORT     (80)

#define PIN_RGB_BLUE  (18) // TODO: change
#define PIN_RGB_GREEN (19) // TODO: change
#define PIN_RGB_RED   (21)

#define SPI_HOST_LED  HSPI_HOST
#define PIN_LED_MOSI  (13)
#define PIN_LED_MISO  (12)
#define PIN_LED_CLK   (14)
#define PIN_LED_CS    (15)
#define PIN_LED_INT   (-1) // TODO

#define SPI_HOST_BIT  VSPI_HOST
#define PIN_BIT_MOSI  (23)
#define PIN_BIT_MISO  (19)
#define PIN_BIT_CLK   (18)
#define PIN_BIT_CS    (5)