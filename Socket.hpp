
#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <iostream>

#include <arpa/inet.h>
#include <fcntl.h>

class Socket {
	private:
		int port;
		std::string password;
		int fd;
		struct sockaddr_in address;
		socklen_t address_size;

		void reusePort();
		void bindSock();
		void listenSock(int listen_size);
		void setNonBlock(int fd);

	public:
		Socket(std::string &_port, std::string &_password);
		~Socket();

		int acceptSock();

		int getFd();
};


#endif