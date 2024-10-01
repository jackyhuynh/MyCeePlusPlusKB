#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h> // For gethostbyname
#include <unistd.h>
#include <cstring>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    struct hostent* server;
    const char* hello = "Hello from Client";
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error!" << std::endl;
        return -1;
    }

    // Get the server (data-service) details by name
    server = gethostbyname("data-service");
    if (server == NULL) {
        std::cerr << "Host not found!" << std::endl;
        return -1;
    }

    // Set server address details
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);

    // Connect to the server (data-service)
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection to data-service failed!" << std::endl;
        return -1;
    }

    // Send message to server
    send(sock, hello, strlen(hello), 0);
    std::cout << "Hello message sent from client-service" << std::endl;

    // Receive response from server
    read(sock, buffer, 1024);
    std::cout << "Client received: " << buffer << std::endl;

    close(sock);
    return 0;
}
