#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 32

int main(){

  //Creating client socket
  
	int client_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(client_socket < 0){
		printf("An error occurred while creating the client socket\n");
		exit(0);
	}
	printf("The client socket was successfully created.\n");


  //Creating data structures for server address
  
	struct sockaddr_in serverAddress;
	memset(&serverAddress, 0, sizeof(serverAddress));


  //Initializing server address
  
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(12345);
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	printf("Address assigned.\n");


  /*Connecting client socket to a server address.
  Note the difference from the binding action performed for the server socket.*/
  
	int connection = connect(client_socket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
	if(connection < 0){
		printf("An error occurred while connecting client to server.\n");
		exit(0);
	}
	printf("Connection established successfully.\n");


  //Message to be sent to server
  
	char message[BUFFER_SIZE];
	printf("Enter message... (max length = %d characters)\n", BUFFER_SIZE);
	fgets(message, BUFFER_SIZE, stdin);


  //Sending message to server
  
	int bytes_sent = send(client_socket, message, strlen(message), 0);
	if(bytes_sent != strlen(message)){
		printf("An error occurred while sending the message to the server.\n");
		exit(0);
	}
	printf("Message sent successfully.\n");


  //Receving message from server
  
	char receive_buffer[BUFFER_SIZE];
	int bytes_recd = recv(client_socket, receive_buffer, BUFFER_SIZE - 1, 0);
	if(bytes_recd < 0){
		printf("An error occurred while receiving the message from the server.\n");
		exit(0);
	}
	receive_buffer[bytes_recd] = '\0';
	printf("%s", receive_buffer);


  // Closing client socket
  
	close(client_socket);
}
