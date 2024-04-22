#include <boost/asio.hpp>
#include "./srcs/server.hpp"
#include "./srcs/prototype_factory.hpp"

#define PORT 8080

int main() {
	deulee::PrototypeFactory prototype_factory;
	boost::asio::io_context io_context;
	deulee::Server server(io_context, PORT);
	io_context.run();
	return 0;
}
