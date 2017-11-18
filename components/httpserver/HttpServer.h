#pragma once

#include "IHttpServer.h"
#include "mongoose.h"

namespace lamp {

  class HttpServer : public IHttpServer {

    public:
      explicit HttpServer() {}

      void start(int port, IHttpHandler* handler) override;
      void stop() override;

    private:
      static void mongooseTask(void* parameters);
      static void mongooseEventHandler(struct mg_connection* nc, int ev, void* evData);
      static char* mongooseStringToCString(struct mg_str mgStr);

  };

}