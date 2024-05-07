FROM ubuntu:22.04

WORKDIR /app

COPY . /app/Server/

RUN apt-get update && apt-get install -y \
	sudo \
	libboost-all-dev \
	zlib1g \
	build-essential \
	git \
	cmake \
	openssl \
	libssl-dev

RUN chmod +x /app/Server/install_dependency.sh
RUN chmod +x /app/Server/generate_code.sh

RUN sed -i 's/\r$//' /app/Server/generate_code.sh
RUN sed -i 's/\r$//' /app/Server/install_dependency.sh
RUN /app/Server/install_dependency.sh
# CMD /app/Server/generate_code.sh

EXPOSE 50051
EXPOSE 4242
EXPOSE 5000/udp
# docker run -it -p 127.0.0.1:50051:50051 -p 127.0.0.1:4242:4242 -p 127.0.0.1:5000:5000/udp server
