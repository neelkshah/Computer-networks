#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#define MAX_PENDING 5
#define BUFFER_SIZE 32

int main(){

  //Creating a TCP server socket
  
	int server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(server_socket < 0){
		printf("An error occurred while opening a server socket.\n");
		exit(0);
	}
	printf("Server socket successfully created.\n");


  //Initializing the socket address structure for server socket
  
	struct sockaddr_in serverAddress;
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(12345);  //unsigned short integer from host byte order to network byte order, ie. big-endian
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);  //unsigned long integer from host byte order to network byte order, ie. big-endian
	printf("Server Address assigned.\n");


  //Binding the (address-less) socket with the address structure
  
	int temp = bind(server_socket, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
	if(temp < 0){
		printf("An error occurred while binding server socket with socket address.\n");
		exit(0);
	}
	printf("Server socket was successfully bound to socket address.\n");


  //Listening for client sockets wishing to communicate
  
	int temp1 = listen(server_socket, MAX_PENDING);
	if(temp1 < 0){
		printf("An error occurred while exwcuting listen.\n");
		exit(0);
	}
	printf("The server socket is now listening.\n");


  //Initializing data structure to store the message and the required data structures to handle the client socket
  
	char message[BUFFER_SIZE];
	struct sockaddr_in clientAddress;
	int client_length = sizeof(clientAddress);
  
  
  //Accepting connection request from client
  
	int client_socket = accept(server_socket, (struct sockaddr*) &clientAddress, &client_length);
	if(client_socket < 0){
		printf("An error occurred in the client socket.\n");
		exit(0);
	}
	printf("Handling client socket %s\n", inet_ntoa(clientAddress.sin_addr));


  //Receiving a message from the client socket
  
	int temp2 = recv(client_socket, message, BUFFER_SIZE, 0);
	if(temp2 < 0){
		printf("An error occurred while receiving the message.\n");
		exit(0);
	}
	message[temp2] = '\0';                                      //Terminating character for string
	printf("%s\n", message);                                    //Prnting the received message


  //Message to be sent to the client
  
	printf("Enter a message for the client...\n");
	fgets(message, BUFFER_SIZE, stdin);


  //Sending the message to the client
  
	int bytes_sent = send(client_socket, message, strlen(message), 0);
	if(bytes_sent != strlen(message)){
		printf("An error occurred while sending the message to the client.\n");
		exit(0);
	}
  
  
  //Closing the server socket
	close(server_socket);
}
