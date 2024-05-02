#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

// #define SERVER_IP "127.0.0.1"
#define SERVER_IP "1.1.1.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Ошибка при создании сокета: " << strerror(errno) << std::endl;
        return 1;
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &(serverAddress.sin_addr));

    if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Ошибка при подключении к серверу: " << strerror(errno) << std::endl;
        close(sockfd);
        return 1;
    }

    const char* message = "Привет, сервер!";
    ssize_t bytesSent = send(sockfd, message, strlen(message), 0);
    if (bytesSent == -1) {
        std::cerr << "Ошибка при отправке данных серверу: " << strerror(errno) << std::endl;
        close(sockfd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    ssize_t bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytesRead == -1) {
        std::cerr << "Ошибка при чтении данных от сервера: " << strerror(errno) << std::endl;
        close(sockfd);
        return 1;
    }

    std::cout << "Получен ответ от сервера: " << buffer << std::endl;

    close(sockfd);
    return 0;
}
