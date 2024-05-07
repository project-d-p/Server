// #include <boost/asio.hpp>
#include "./srcs/server.hpp"
#include "./srcs/prototype_factory.hpp"

#include <iostream>
#include <vector>
#include <thread>

#define PORT 4242

int main() {
	deulee::PrototypeFactory prototype_factory;
	boost::asio::io_context io_context;
	// boost::asio::io_context logic_context;
	deulee::Server server;
	while (1);
	return 0;
}
