#include <iostream>
#include "serversocket.h"

//#define PORT 8080

using namespace std;

int main(int argc, char *argv[]){

     char name[] = {"VSPtrServer"};
     sethostname(name, strlen(name));

     cout<< "HOST " << gethostname << endl;

     int sockfd, newsockfd;
     int portno = 2001;
     socklen_t clilen;
     char buffer[256];
     int* arr[10];
     struct sockaddr_in serv_addr, cli_addr;
     int n;

     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");

     bzero((char *) &serv_addr, sizeof(serv_addr));
     
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);

     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0){ 
              error("ERROR on binding");
    }

     listen(sockfd,1);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);

     if (newsockfd < 0) 
          error("ERROR on accept");

     bzero(buffer,256);


    while (true) {
        n = read(newsockfd, buffer, 256);


        if (n < 0) {
            error("ERROR reading from socket");
        }

        printf("Here is the message: %s\n", buffer);

        cout << "enter response" << endl;
        cin >> buffer;

        n = write(newsockfd, buffer, strlen(buffer));

        if (n < 0) error("ERROR writing to socket");
    }

     close(newsockfd);
     close(sockfd);

     return 0; 
}