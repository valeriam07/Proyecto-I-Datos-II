#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

/**
 * @brief envia un error en dicho caso de que ocurra un problema con el cliente
 * 
 * @param msg mensaje de aviso de error para el usuario
 */
void error(const char *msg)
{
    perror(msg);
    exit(1);
}


/**
 * @brief inicializa el servidor, lee y guarda los datos enviados por el cliente
 * 
 * @return int, estado del servidor
 */
int main(){

     char name[] = {"VSPtrServer"};
     sethostname(name, strlen(name));

     cout<< "HOST " << gethostname << endl;
     int sockfd, newsockfd;
     int portno = 2000;
     socklen_t clilen;
     char buffer[256];
     char ids[200];
     char ptrs[200];
     char values[200];
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

        n = read(newsockfd, ids, 256);

        if (n < 0) {
            error("ERROR reading from socket");
        }

        n = read(newsockfd, ptrs, 256);

        if (n < 0) {
            error("ERROR reading from socket");
        }

        n = read(newsockfd, values, 256);

        if (n < 0) {
            error("ERROR reading from socket");
        }

        printf("Here is the message: %s\n", ids);
        printf("Here is the message: %s\n", ptrs);
        printf("Here is the message: %s\n", values);

}