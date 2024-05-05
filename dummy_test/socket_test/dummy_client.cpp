#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "message.pb.h" // Proto 파일에서 생성된 헤더 파일

using boost::asio::ip::tcp;
using boost::asio::ip::udp;
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

void send_message(asio::ip::udp::socket& socket, udp::endpoint& result_type, const Message& msg) {
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
    socket.send_to(asio::buffer(buffer), result_type);
}

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: client <host>" << std::endl;
            return 1;
        }
        asio::io_context io_context;

        // 서버 연결 설정
        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "4242");

        // 소켓 생성 및 연결
        tcp::socket tcp_socket(io_context);
        asio::connect(tcp_socket, endpoints);
        if (argv[1][0] == 't') {
            std::string ip = tcp_socket.local_endpoint().address().to_string();
            std::string port = std::to_string(tcp_socket.local_endpoint().port());
            std::cout << ip << ":" << port << std::endl;

            for (int i = 0; i < 1; i++) {
                // Movement 메시지 생성
                Vec3 orientation;
                orientation.set_x(1.0 * i);
                orientation.set_y(1.0 * i);
                orientation.set_z(1.0 * i);

                Vec3 progress_vector;
                progress_vector.set_x(0.5 * i);
                progress_vector.set_y(0.5 * i);
                progress_vector.set_z(2.0 * i);

                Movement move;
                move.set_player_id("player1");
                *move.mutable_orientation() = orientation;
                *move.mutable_progess_vector() = progress_vector;
                move.set_state(State::STATE_RUN);
                move.set_timestamp("2021-01-01T12:00:00Z");

                Message message;
                *message.mutable_movement() = move;

                // 메시지 전송
                send_message(tcp_socket, message);
                char buffer[1024];
                memset(buffer, 0, 1024);
                tcp_socket.read_some(asio::buffer(buffer, 1024));

                // 수신한 데이터 출력
                Message received_message;
                uint32_t message_size;
                memcpy(&message_size, buffer, sizeof(message_size));
                std::cout << "message_size: " << message_size << std::endl;
                received_message.ParseFromArray(buffer + 4, message_size);
                std::cout << "Received message: " << received_message.DebugString() << std::endl;
                memset(buffer, 0, 1024);
            }

            // 연결 종료
            tcp_socket.close();
        }
        else if (argv[1][0] == 'u') {
            asio::io_context io_context;

            std::string ip = tcp_socket.local_endpoint().address().to_string();
            std::string port = std::to_string(tcp_socket.local_endpoint().port());
            std::cout << ip << ":" << port << std::endl;
            udp::endpoint udp_endpoint(boost::asio::ip::address::from_string(ip), std::stoi(port));
            udp::socket udp_socket(io_context, udp_endpoint);

            udp::resolver resolver(io_context);
            udp::resolver::query query(udp::v4(), "127.0.0.1", "5000");
            udp::endpoint endpoints = *resolver.resolve(query);

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
            send_message(udp_socket, endpoints, message);

            // 수신한 데이터 출력
            udp::endpoint result_type;
            size_t length = udp_socket.receive_from(asio::buffer(buffer), result_type);
            Message received_message;
            uint32_t message_size;
            memcpy(&message_size, buffer, sizeof(message_size));
            std::cout << "message_size: " << message_size << std::endl;
            received_message.ParseFromArray(buffer + 4, message_size);
            std::cout << "Received message: " << received_message.DebugString() << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
