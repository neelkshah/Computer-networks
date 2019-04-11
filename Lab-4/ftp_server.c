#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 5001
#define BUFFER_SIZE 1025

void die(char* error_message){
	perror(error_message);
	exit(1);
}

int main(){
	int sock;
	int connected_fd;
	struct sockaddr_in server_address;
	char send_buffer[BUFFER_SIZE];

	memset(&server_address, 0, sizeof(server_address));
	memset(&send_buffer, '\0', BUFFER_SIZE);

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		die("socket()");
	}

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(sock, (struct sockaddr*) &server_address, sizeof(server_address));

	if(listen(sock, 10) == -1){
		die("listen()");
	}

	while(1){
		int command;
		unsigned char offset_buffer[10] = {'0'};
		unsigned char command_buffer[2] = {'0'};
		connected_fd = accept(sock, (struct sockaddr*)NULL, NULL);
		printf("Waiting for file command from client\n");
		while(read(connected_fd, command, 2));
		sscanf(command_buffer, "%d", command);
	}

	return 0;
}