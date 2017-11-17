#pragma once

#include "IHttpServer.h"

namespace lamp {

  class HttpServer : public IHttpServer {

    public:
      explicit HttpServer() {}

      void start(int port, IHttpHandler* handler) override;
      void stop() override;

  };

}