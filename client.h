#ifndef __CLIENT__
#define __CLIENT__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>

#include <string>
#include <iostream>

using namespace std;

typedef struct sockaddr_in Socket;

class Client {
	Socket server{};
	int socket_id{0}, readSize{0}, port{2220};
	char buffer[1025];
	const string host{"127.0.0.1"};

	private:
		void setError(const string);

		void createSocket(void);
		void handshake(void);

		void createConnection(void);
	public:
		Client() {
			createConnection();
		}

		bool upload(const string);
		bool quit(void);
};

void Client::createSocket(void) {
	if(!(this->socket_id = socket(AF_INET, SOCK_STREAM, 0)))
		this->setError("socket");

    this->server.sin_addr.s_addr = inet_addr(this->host.c_str());
    this->server.sin_family = AF_INET;
    this->server.sin_port = htons(this->port);

	if(0 > (connect(this->socket_id, (struct sockaddr *)&this->server, sizeof(this->server))))
		this->setError("connect");
}

void Client::createConnection(void) {
	this->createSocket();
	this->handshake();
}

void Client::handshake(void) {
	if(0 > (this->readSize = recv(this->socket_id, this->buffer, 1025, 0)))
		this->setError("recive");

	this->buffer[this->readSize] = '\0';
	cout << "From server: " << this->buffer << endl;
}

bool Client::upload(const string msg) {
	if(0 > (send(this->socket_id, msg.c_str(), msg.length(), 0))) {
		this->setError("send");
		return false;
	}

	else
		return true;
}

bool Client::quit(void) {
	close(this->socket_id);

	return true;
}

void Client::setError(const string msg) {
	cerr << "Error: " << msg << endl;
	exit(EXIT_FAILURE);
}

/*int main(int argc, char **argv) {
	Client client_1{}, client_2{}, client_3{};

	for(int i = 0; i < 80; i++) {
		client_1.upload("C1\n");
		client_2.upload("C2\n");
		client_3.upload("C3\n");
	}
	cout << "test" << '\n';

	//client_1.quit();
	//client_2.quit();
	//client_3.quit();
}*/
#endif
