#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <thread>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void handleClient(int clientSocket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesRead == -1) {
        std::cerr << "Ошибка при получении данных: " << strerror(errno) << std::endl;
        close(clientSocket);
        return;
    }

    std::cout << "Получено сообщение от клиента: " << buffer << std::endl;

    const char* response = "Привет, клиент!";
    if (send(clientSocket, response, strlen(response), 0) == -1) {
        std::cerr << "Ошибка при отправке данных: " << strerror(errno) << std::endl;
        close(clientSocket);
        return;
    }
    while (true)
    {
    }
    

    close(clientSocket);
}

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Ошибка при создании сокета: " << strerror(errno) << std::endl;
        return 1;
    }

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(SERVER_PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Ошибка при привязке сокета к порту: " << strerror(errno) << std::endl;
        close(serverSocket);
        return 1;
    }

    if (listen(serverSocket, 10) == -1) {
        std::cerr << "Ошибка при ожидании подключений: " << strerror(errno) << std::endl;
        close(serverSocket);
        return 1;
    }

    while (true) {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressSize = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressSize);
        if (clientSocket == -1) {
            std::cerr << "Ошибка при принятии подключения: " << strerror(errno) << std::endl;
            close(serverSocket);
            return 1;
        }

        std::thread clientThread{handleClient, clientSocket};
        clientThread.detach();
    }

    close(serverSocket);

    return 0;
}