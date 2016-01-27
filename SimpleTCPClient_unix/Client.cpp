#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#define DEFAULT_PORT 27015

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    //if (argc < 3) {
    //   fprintf(stderr,"usage %s hostname\n", argv[0]);
    //   exit(0);
    //}
    //portno = atoi(argv[2]);
    portno = DEFAULT_PORT;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

	std::string stringToSend;
    do {
	    printf("Please enter the message or enter 'quit' to end: ");
	    //bzero(buffer,256);
	    //fgets(buffer,255,stdin);
	    std::cin >> stringToSend;
	    n = write(sockfd,stringToSend.c_str(),strlen(stringToSend.c_str()));
	    if (n < 0) 
	         error("ERROR writing to socket");
 	} while(stringToSend.compare("quit") != 0);
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);
    std::cout << "Exiting Program" << std::endl;
    close(sockfd);
    return 0;
}