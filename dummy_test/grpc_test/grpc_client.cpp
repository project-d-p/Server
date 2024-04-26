#include <iostream>
#include <memory>
#include <string>

// #include "absl/flags/flag.h"
// #include "absl/flags/parse.h"

#include <grpcpp/grpcpp.h>

#include "grpc_match.grpc.pb.h"

// ABSL_FLAG(std::string, target, "localhost:50051", "Server address");

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using matching::MatchingService;
using matching::Empty;
using matching::RequestLaunch;
using matching::ResponseLaunch;
using matching::ChannelResponse;

class GreeterClient {
 public:
  GreeterClient(std::shared_ptr<Channel> channel)
      : stub_(MatchingService::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string CreateChannel(const std::string& user) {
    // Data we are sending to the server.
    Empty request;

    // Container for the data we expect from the server.
    ChannelResponse reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->CreateChannel(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
		std::cout << reply.channel_id() << std::endl;
		std::cout << reply.udp_ip() << std::endl;
		std::cout << reply.udp_port() << std::endl;
		std::cout << reply.tcp_ip() << std::endl;
		std::cout << reply.tcp_port() << std::endl;
      return reply.channel_id();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

  int AttachPlayer(const std::string& channel_id) {
    // Data we are sending to the server.
    RequestLaunch request;

	request.add_player_token("player1");
	request.add_player_token("player2");
	request.add_player_token("player3");
	request.set_channel_id(channel_id);

    // Container for the data we expect from the server.
    ResponseLaunch reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->AttachPlayer(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
		std::cout << reply.status() << std::endl;
      return reply.status();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return -1;
    }
  }
 private:
  std::unique_ptr<MatchingService::Stub> stub_;
};



int main(int argc, char** argv) {
//   absl::ParseCommandLine(argc, argv);
//   Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint specified by
  // the argument "--target=" which is the only expected argument.
  std::string target_str = "localhost:50051";
  // We indicate that the channel isn't authenticated (use of
  // InsecureChannelCredentials()).
  GreeterClient greeter(
      grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
  std::string user("world");
  std::string reply = greeter.CreateChannel(user);
  std::cout << "Greeter received CreateChannel: " << reply << std::endl;
  int status = greeter.AttachPlayer(reply);
  std::cout << "Greeter received AttachPlayer: " << status << std::endl;

  return 0;
}
