#include <boost/asio.hpp>
#include <./srcs/server.hpp>

#define PORT 8080

int main() {
	boost::asio::io_context io_context;
	Server server(io_context, PORT);
	io_context.run();
	return 0;
}
