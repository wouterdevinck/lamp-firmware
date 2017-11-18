#include "HttpServer.h"

#include "esp_log.h"

static char tag[] = "HttpServer";

using namespace lamp;

// TODO Use Task/FreeRTOS C++ wrappers?

void HttpServer::start(int port, IHttpHandler* handler) {
  // TODO pass parameters to task
  ::xTaskCreatePinnedToCore(&mongooseTask, "mongooseTask", 20000, NULL, 5, NULL, 0);
}

void HttpServer::stop() {
  // TODO
}

void HttpServer::mongooseTask(void* parameters) {
	ESP_LOGD(tag, "Mongoose: Starting task");
	struct mg_mgr mgr;
	mg_mgr_init(&mgr, NULL);
	ESP_LOGD(tag, "Mongoose: Succesfully inited");
	struct mg_connection *c = mg_bind(&mgr, ":80", HttpServer::mongooseEventHandler); 
	if (c == NULL) {
		ESP_LOGE(tag, "Mongoose: Failed to bind");
		::vTaskDelete(NULL); 
		return;
  }
  ESP_LOGD(tag, "Mongoose: Successfully bound");
	mg_set_protocol_http_websocket(c);
	while (1) {
		mg_mgr_poll(&mgr, 1000);
	}
}

// TODO use std string
char* HttpServer::mongooseStringToCString(struct mg_str mgStr) {
	char *retStr = (char *) malloc(mgStr.len + 1);
	memcpy(retStr, mgStr.p, mgStr.len);
	retStr[mgStr.len] = 0;
	return retStr;
} 

void HttpServer::mongooseEventHandler(struct mg_connection* nc, int ev, void* evData) {
	switch (ev) {
	  case MG_EV_HTTP_REQUEST: {
			struct http_message* message = (struct http_message*) evData;
			char *uri = mongooseStringToCString(message->uri);
			if (strcmp(uri, "/") == 0) { // TODO call handler
				char payload[256];
				sprintf(payload, "Hello");
				int length = strlen(payload);
				mg_send_head(nc, 200, length, "Content-Type: text/plain");
				mg_printf(nc, "%s", payload);
			}
			nc->flags |= MG_F_SEND_AND_CLOSE;
			free(uri);
			break;
		}
	}
}