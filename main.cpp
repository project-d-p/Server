// #include <boost/asio.hpp>
#include "./srcs/server.hpp"
#include "./srcs/prototype_factory.hpp"

#include <iostream>
#include <vector>
#include <thread>

#define PORT 4242

int main() {
	deulee::PrototypeFactory prototype_factory;
	// boost::asio::io_context io_context;
	deulee::Server server(io_context, PORT);
	std::vector<std::thread> threads;
	// for (int i = 0; i < 3; i++) {
	// 	threads.push_back(std::thread([](){
	// 		io_context.run();
	// 	}));
	// }
	// for (auto& thread : threads) {
	// 	thread.detach();
	// }
	io_context.run();
	return 0;
}
