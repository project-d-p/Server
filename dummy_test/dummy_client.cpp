#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "../proto_build/message.pb.h" // Proto 파일에서 생성된 헤더 파일

using boost::asio::ip::tcp;
namespace asio = boost::asio;

void send_message(asio::ip::tcp::socket& socket, const Message& msg) {
    // 메시지를 문자열로 직렬화
    std::string serialized_msg;
    msg.SerializeToString(&serialized_msg);

    // 메시지 크기를 계산하고 보낼 데이터 준비
    uint32_t message_size = serialized_msg.size();
    std::vector<uint8_t> buffer;
    buffer.resize(sizeof(message_size) + message_size);
    memcpy(buffer.data(), &message_size, sizeof(message_size));
    memcpy(buffer.data() + sizeof(message_size), serialized_msg.data(), message_size);

    // 메시지 전송
    asio::write(socket, asio::buffer(buffer), asio::transfer_all());
}

int main() {
    try {
        asio::io_context io_context;

        // 서버 연결 설정
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "8080");

        // 소켓 생성 및 연결
        tcp::socket socket(io_context);
        asio::connect(socket, endpoints);

        // Movement 메시지 생성
        Vec3 orientation;
        orientation.set_x(1.0);
        orientation.set_y(1.0);
        orientation.set_z(1.0);

        Vec3 progress_vector;
        progress_vector.set_x(0.5);
        progress_vector.set_y(0.5);
        progress_vector.set_z(2.0);

        Movement move;
        move.set_player_id("player1");
        *move.mutable_orientation() = orientation;
        *move.mutable_progess_vector() = progress_vector;
        move.set_state(State::STATE_RUN);
        move.set_timestamp("2021-01-01T12:00:00Z");

        Message message;
        *message.mutable_movement() = move;

        // 메시지 전송
		char buffer[1024];
		send_message(socket, message);
		socket.read_some(asio::buffer(buffer, 1024));

		// 수신한 데이터 출력
		Message received_message;
		received_message.ParseFromArray(buffer + 4, 1020);
		std::cout << "Received message: " << received_message.DebugString() << std::endl;

        // 연결 종료
        socket.close();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
