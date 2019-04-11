#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 512
#define PORT 8888

void die(char* error_message){
	perror(error_message);
	exit(1);
}

int main(){
	struct sockaddr_in friend;
	int sockaddr_len = sizeof(friend);
	int s;
	char buffer[BUFFER_SIZE];
	char message[BUFFER_SIZE];

	if((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
		die("socket");
	}

	memset((char*)&friend, 0, sockaddr_len);
	friend.sin_family = AF_INET;
	friend.sin_port = htons(PORT);
	friend.sin_addr.s_addr = inet_addr("127.0.0.1");

	while(1){
		printf("Enter message: ");
		fgets(message, BUFFER_SIZE, stdin);

		if(sendto(s, message, strlen(message), 0, (struct sockaddr*) &friend, sockaddr_len) == -1){
			die("send_to()");
		}

		memset(buffer, '\0', BUFFER_SIZE);
		if(recvfrom(s, buffer, BUFFER_SIZE, 0, (struct sockaddr*) &friend, &sockaddr_len) == -1){
			die("recv_from()");
		}

		puts(buffer);
		
		if((strcmp(buffer, "over") == 0) || (strcmp(buffer, "all over") == 0)){
			break;
		}
	}
	
	close(s);
	return 0;
}
