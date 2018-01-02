#include "constants.h"

#include "esp_log.h"

#include "WiFi.h"
#include "WiFiEventHandler.h"
#include "SPI.h"
#include "HttpServer.h"
#include "RgbLed.h"
#include "LedBoardChain.h"
#include "Lamp.h"

#define WIFI_SSID CONFIG_WIFI_SSID
#define WIFI_PASS CONFIG_WIFI_PASSWORD

static char tag[] = "LampMain";

using namespace lamp;

extern "C" {
  void app_main(void);
}

class LampWiFiEventHandler: public WiFiEventHandler {

  esp_err_t staGotIp(system_event_sta_got_ip_t event_sta_got_ip) {
    ESP_LOGD(tag, "LampWiFiEventHandler: Got IP address");

    auto spi = new SPI(SPI1_HOST, SPI1_DMA_CH, SPI1_MOSI_PIN, SPI1_MISO_PIN, SPI1_CLK_PIN, SPI1_CS_PIN);

    auto http = new HttpServer();
    auto led = new RgbLed(PIN_RGB_RED, PIN_RGB_GREEN, PIN_RGB_BLUE);
    auto leds = new LedBoardChain(spi, PIN_LED_INT);
    auto lamp = new Lamp(http, led, leds); 
    lamp->start(HTTP_PORT);

    return ESP_OK;
  }

};

void app_main(void) {

  WiFi wifi;
  auto *eventHandler = new LampWiFiEventHandler();
  wifi.setWifiEventHandler(eventHandler);
  wifi.connectAP(WIFI_SSID, WIFI_PASS);

}