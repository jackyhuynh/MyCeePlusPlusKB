#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char* hello = "Hello from Server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket creation error!" << std::endl;
        return -1;
    }

    // Assigning address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the network address and port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Binding error!" << std::endl;
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listening error!" << std::endl;
        return -1;
    }

    std::cout << "Server listening on port: " << PORT << std::endl;

    // Accept the connection
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        std::cerr << "Accepting connection failed!" << std::endl;
        return -1;
    }

    // Read message from client
    read(new_socket, buffer, 1024);
    std::cout << "Server received: " << buffer << std::endl;

    // Send response to the client
    send(new_socket, hello, strlen(hello), 0);
    std::cout << "Hello message sent from data-service" << std::endl;

    close(new_socket);
    close(server_fd);
    return 0;
}
