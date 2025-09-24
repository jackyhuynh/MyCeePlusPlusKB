#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h> // For gethostbyname
#include <unistd.h>
#include <cstring>
#include <vector>
#include <sstream>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    struct hostent* server;
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

    // Send sets of numbers to server
    std::vector<std::vector<int>> numberSets = {
        {1, 2, 3, 4, 5},
        {10, 20, 30},
        {100, 200, 300, 400},
        {7, 14, 21},
        {99, 1}
    };
    
    for (const auto& numbers : numberSets) {
        // Create message with numbers
        std::stringstream ss;
        for (size_t i = 0; i < numbers.size(); i++) {
            ss << numbers[i];
            if (i < numbers.size() - 1) ss << ",";
        }
        std::string message = ss.str();
        
        std::cout << "Sending numbers: " << message << std::endl;
        send(sock, message.c_str(), message.length(), 0);
        
        // Receive sum from server
        memset(buffer, 0, sizeof(buffer));
        read(sock, buffer, 1024);
        std::cout << "Server calculated sum: " << buffer << std::endl;
        std::cout << "---" << std::endl;
        
        sleep(1);
    }

    close(sock);
    return 0;
}
