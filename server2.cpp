#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <vector>
#include "Virtual.h"
#include <stdexcept>
using namespace std;

typedef struct sockaddr Socket;
typedef struct sockaddr_in Socket_in;

class Server {
	private:
		// Set the deafult connection port to '8080' if user do not set one
	    int opt{1}, port{2220}, master_socket{0}, addrlen{0}, new_socket{0}, sd{0};
		int max_clients{12}, max_sd{0}, activity{0}, valread{0}, client_socket[12];
		Socket_in address;
		char buffer[1025]{};
		char const *handshake{"Server message: Connection accpeted\n"};
		fd_set readfds;

		vector <Virtual *> sensors{};

		void setError(const char *);

		void createConnection(void);

		void initializeClients(void);
		void createMaster(void);
		void bindConnection(void);
		void maxPending(int);

		void addChild(void);
		void addSocket(void);
		void setSocket(void);
		void handleSocket(void);
		void closeSocket(int);
		void handleSocketMessage(int);
		void handleObjects(string);
		void createObjects(string,string);
		void updateSensors(string sensorName,int n);
		void displaySensors();
	public:
		Server() {
			createConnection();
			cout << "Get in here \n\n\n\n";
			for(int i=0;i<4;i++){
				Virtual *aux = new Virtual();
				this->sensors.push_back(aux);
				for(int j=0;j<3;j++){
					this->sensors[i]->addSensor(new Sensor());
					//this->sensors[i]->addSensor(NULL);
				}
			}
		}
		Server(int);

		void run(void);
};

Server::Server(int port) {
	this->port = port;
	this->createConnection();
}

void Server::createConnection(void) {
	this->initializeClients();
	this->createMaster();

	this->address.sin_family = AF_INET;
	this->address.sin_addr.s_addr = INADDR_ANY;
	this->address.sin_port = htons(this->port);

	this->bindConnection();
	this->maxPending(12);
}

void Server::initializeClients(void) {
	for(int i = 0; i < this->max_clients; i++)
		this->client_socket[i] = 0;
}

void Server::createMaster(void) {
	if(0 == (this->master_socket = socket(AF_INET, SOCK_STREAM, 0)))
		this->setError("Server failed to initialize.");

	if(0 > setsockopt(this->master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&this->opt, sizeof(this->opt)))
		this->setError("setsockopt");
}

void Server::bindConnection(void) {
	if(0 > bind(this->master_socket, (Socket*)&this->address, sizeof(this->address)))
		this->setError("bind failed");

	cout << "Listener on port: " << this->port << endl;
}

void Server::maxPending(int max) {
	if(0 > listen(this->master_socket, max))
		this->setError("listen");

	this->addrlen = sizeof(this->address);
}

void Server::run(void) {
	cout << "Waiting for connections..." << endl;
	int full = 11;
	string messageFromSensor;
	while(true) {
		//clear the socket set
				int flag=0;
        FD_ZERO(&this->readfds);
        //add master socket to set
        FD_SET(this->master_socket, &this->readfds);
        this->max_sd = this->master_socket;

      	//add child sockets to set
        this->addChild();

        //wait for an activity on one of the sockets, timeout is NULL, so wait indefinitely
        this->activity = select(this->max_sd+1, &this->readfds, NULL, NULL, NULL);

        if(0 > this->activity && errno != EINTR)
            cout << "select error" << endl;

        //If something happened on the master socket, then its an incoming connection
        if(FD_ISSET(this->master_socket, &this->readfds))
					this->addSocket();

        //else its some IO operation on some other socket
        else{
					//this->handleSocket();
					for(int i=0;i<this->max_clients;i++){
					 handleSocketMessage(i) ;
				 	}
					//displaySensors();
				}

    }

}

void Server::displaySensors(){
	cout << "\n\n DISPLAY \n\n";
}

void Server::addChild(void) {
	for(int i = 0; i < this->max_clients; i++) {
		//socket descriptor
		this->sd = this->client_socket[i];

		//if valid socket descriptor then add to read list
		if(0 < this->sd)
			FD_SET(this->sd , &this->readfds);

		//highest file descriptor number, need it for the select function
		if(this->sd > this->max_sd)
			this->max_sd = this->sd;
	}
}

void Server::addSocket(void) {
	if(0 > (new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)))
		this->setError("accept");

	//inform user of socket number - used in send and receive commands
	cout << "--- New connection ---" << endl;
	cout << "\t> socket fd is: " << this->new_socket << endl;
	cout << "\t> ip is: " << inet_ntoa(this->address.sin_addr) << endl;
	cout << "\t> port: " << ntohs(this->address.sin_port) << endl;

	//send new connection greeting handshake
	if(send(this->new_socket, this->handshake, strlen(this->handshake), 0) != (unsigned int)strlen(this->handshake))
		perror("send");

	cout << "Welcome handshake sent successfully" << endl;

	this->setSocket();
}

void Server::setSocket(void) {
	//add new socket to array of sockets
	for(int i = 0; i < this->max_clients; i++) {
		//if position is empty
		if(this->client_socket[i] == 0) {
			this->client_socket[i] = this->new_socket;
			cout << "Adding to list of sockets as: " << i << endl;

			break;
		}
	}
}

void Server::handleSocket(void) {
	for (int i = 0; i < this->max_clients; i++) {
		this->sd = this->client_socket[i];

		//read(this->sd, this->buffer, 1024);
		//cout << "oooooooooooooooooooo" << this->buffer << endl ;
		if(FD_ISSET(this->sd , &this->readfds)) {
			//Check if it was for closing , and also read the
			//incoming message
			cout << "Entra\n\n";
			if(0 == (this->valread = read(this->sd, this->buffer, 1024))){
				//Somebody disconnected , get his details and print
				this->closeSocket(i);
				cout << "test\n";
			}
			//Echo back the message that came in
			else {
				//set the string terminating NULL byte on the end
				//of the data read
				this->buffer[this->valread] = '\0';
				//cout << "jhonathan test" << this->buffer << endl;
				send(this->sd, this->buffer, strlen(this->buffer), 0);
				// Remove trailing info from client
				this->buffer[strcspn(this->buffer, "\r\n")] = 0;
				cout << "MESSAGE from client #" << i <<": " << this->buffer << endl;
				memset(this->buffer, 0, sizeof(char) * 1025);
			}
		}
	}
}

void Server::handleSocketMessage(int i) {

		this->sd = this->client_socket[i];


		if(FD_ISSET(this->sd , &this->readfds)) {
			if(0 == (this->valread = read(this->sd, this->buffer, 1024))){
				//Somebody disconnected , get his details and print
				this->closeSocket(i);
				cout << "test\n";
			}
			//Echo back the message that came in
			else {
				//set the string terminating NULL byte on the end
				//of the data read
				this->buffer[this->valread] = '\0';
				//cout << "jhonathan test" << this->buffer << endl;
				send(this->sd, this->buffer, strlen(this->buffer), 0);
				// Remove trailing info from client
				this->buffer[strcspn(this->buffer, "\r\n")] = 0;
				cout << "MESSAGE from client #" << i <<": " << this->buffer << endl;
				handleObjects(this->buffer);
				memset(this->buffer, 0, sizeof(char) * 1025);
				//return this->buffer;
			}

		}

}

void Server::handleObjects(string message){


	size_t found;
	if ((found = message.find("|")) != string::npos)
	{
    cout << "left side = " << message.substr(0,found) << endl;
    cout << "right side = " << message.substr(found+1, string::npos) << endl;

	}
	string name = message.substr(0,found);
	string number = message.substr(found+1, string::npos);
	int n=0;
	try{
		n = stoi(number);
		updateSensors(name,n);
	}
	catch(const std::invalid_argument& ia){
		cout << "is not \n";
		createObjects(name,number);

	}
	displaySensors();


}
void Server::updateSensors(string sensorName,int n){
	//cout << this->sensors[0]->getPyshical(0)->getSensorName();
	//cout << "entra\n";
	for(int i=0;i<4;i++){
		for (int j = 0; j < 3; j++) {
			if(this->sensors[i]->getPyshical(j)->getSensorName() == sensorName){
				//cout << "if\n\n";
				Sensor *aux = this->sensors[i]->getPyshical(j);
				aux->setValue(n);
				i=4;j=3;
			}
		}
	}
}

void Server::createObjects(string sensorName,string sensorUnit){
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(this->sensors[i]->getPyshical(j)->getSensorName()=="NULL"){
				cout << "is NULL\n\n\n";
				this->sensors[i]->getPyshical(j)->setSensor(sensorName,sensorUnit);
				cout << "sensor created " << sensorName << " " << sensorUnit << endl;
				cout << this->sensors[i]->getPyshical(j)->getSensorName() << "-----------\n";
				i=4;j=3;
				break;
			}
		}
	}

}

void Server::closeSocket(int pos) {
	getpeername(this->sd, (Socket*)&this->address, (socklen_t*)&this->addrlen);
	// send client info about disconection
	cout << "--- Host disconnected ---" << endl;
	cout << "\t> ip: " << inet_ntoa(this->address.sin_addr) << endl;
	cout << "\t> port: " << ntohs(this->address.sin_port) << endl;

	//Close the socket and mark as 0 in list for reuse
	close(this->sd);
	this->client_socket[pos] = 0;
}


void Server::setError(const char *msg) {
	cerr << "Error: " << msg << endl;
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv){
	Server server{};
	server.run();
	return 0;
}
