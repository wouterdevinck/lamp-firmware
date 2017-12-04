#include "esp_log.h"

#include "WiFi.h"
#include "WiFiEventHandler.h"

#include "HttpServer.h"
#include "RgbLed.h"
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

    auto http = new HttpServer();
    auto led = new RgbLed();
    auto lamp = new Lamp(http, led, NULL); // TODO
    lamp->start(80);

    return ESP_OK;
  }

};

void app_main(void) {

  WiFi wifi;
  auto *eventHandler = new LampWiFiEventHandler();
  wifi.setWifiEventHandler(eventHandler);
  wifi.connectAP(WIFI_SSID, WIFI_PASS);

}