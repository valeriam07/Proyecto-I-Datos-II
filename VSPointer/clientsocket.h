#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

void readJson(){
    /*ifstream ifs("camaras.json");
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);
    const Json::Value& characters = obj["camaras"]; // array of characters

    for (int i = 0; i < characters.size(); i++){
        cout << "\nNombre: " << characters[i]["nombre"].asString();
        cout << "\nIP: " << characters[i]["ip"].asString();
        cout << endl;
    }*/
}


int getPort(){
    int port = 2001;           //Obtener del .json
    return port;

}

char* getSName(){
    char sName[] = "1";  //Obtener ddel .json
    return sName;

}

string getPassword(){
    string pass = "pass";
    return pass;
}


int main()
{
    
    int sockfd, portno, n;
    struct sockaddr_in serv_addr{};
    struct hostent *server;

    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(getPort() == 2001){                  //Verifica el puerto
        portno = 2001;
    }else{
        cout << "ERROR: PUERTO INVALIDO";
        close(sockfd);
        return 0;
    }

    if (sockfd < 0)
        error("ERROR opening socket");

    if(getSName() == "1"){                  //Verifica el nombre del host
        server = gethostbyname(getSName());
    }else {
        cout << "ERROR: NOMBRE INVALIDO";
        close(sockfd);
        return 0;
    }

    if(getPassword() == "pass"){
        cout << "*** contraseña verificada *** " << endl;
    }else{
        cout << "ERROR: CONSTRASEÑA INVALIDA";
        close(sockfd);
        return 0;
    }
    
    if (server == nullptr) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
        
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){ 
        error("ERROR connecting");
    }

    while(true) {
        cout << "Please enter the message: " << endl;
        cin >> buffer;

        n = write(sockfd, buffer, 5);


        if (n < 0)
            error("ERROR writing to socket");
        bzero(buffer, 256);


        n = read(sockfd, buffer, 255);
        if (n < 0)
            error("ERROR reading from socket");

        printf("Here is the response: %s\n", buffer);
    }


}

