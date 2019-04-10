#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 512
#define PORT 8882

void die(char* error_message){
	perror(error_message);
	exit(1);
}

struct data_packet{
	int sequence_number;
	char data[BUFFER_SIZE];
} Data_packet;

struct ack_packet{
	int sequence_number;
} Ack_packet;

int main(){
	struct sockaddr_in self, other;
	int sock;
	int s_len;

	return 0;
}