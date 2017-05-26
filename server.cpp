#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
using namespace std;

class Server {
	private:		
		int server_fd{0}, new_socket{0}, valread{0}, port{0}, addrlen = sizeof(address), opt{1};
		struct sockaddr_in address;
		char buffer[1024] = {};
		char const *handshake{"Connection accpeted"};
		
		void createConnection();
	public:
		Server(): port{8080} {
			createConnection();
		}

		Server(int port);	
};

Server::Server(int port) {
	this->port = port;
	createConnection();
}

void Server::createConnection() {
	// Creating socket file descriptor
	if(0 == (this->server_fd = socket(AF_INET, SOCK_STREAM, 0))) {
		perror("Socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
    if(setsockopt(this->server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

 	this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(this->port);
      
    // Forcefully attaching socket to the port 8080
    if(0>bind(this->server_fd, (struct sockaddr *)&this->address, sizeof(address))) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

	if(0>listen(this->server_fd, 3)){
	    perror("listen");
	    exit(EXIT_FAILURE);
	}

	if(0>(this->new_socket = accept(this->server_fd, (struct sockaddr *)&this->address, (socklen_t*)&addrlen))) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

	this->valread = read(this->new_socket , this->buffer, 1024);
    printf("%s\n",buffer);
    send(this->new_socket, this->handshake, strlen(this->handshake), 0 );
    printf("Hello message sent\n");
}
