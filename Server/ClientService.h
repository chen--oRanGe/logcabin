/* Copyright (c) 2012 Stanford University
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR(S) DISCLAIM ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL AUTHORS BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "RPC/Service.h"

#ifndef LOGCABIN_SERVER_CLIENTSERVICE_H
#define LOGCABIN_SERVER_CLIENTSERVICE_H

namespace LogCabin {
namespace Server {

/**
 * This is LogCabin's application-facing RPC service. As some of these RPCs may
 * be long-running, this is intended to run under a RPC::ThreadDispatchService.
 */
class ClientService : public RPC::Service {
  public:
    /// Constructor.
    ClientService();

    /// Destructor.
    ~ClientService();

    void handleRPC(RPC::ServerRPC rpc);

  private:

    ////////// RPC handlers //////////

    void getSupportedRPCVersions(RPC::ServerRPC rpc, uint32_t skipBytes);


    // ClientService is non-copyable.
    ClientService(const ClientService&) = delete;
    ClientService& operator=(const ClientService&) = delete;
}; // class ClientService

} // namespace LogCabin::Server
} // namespace LogCabin

#endif /* LOGCABIN_SERVER_CLIENTSERVICE_H */