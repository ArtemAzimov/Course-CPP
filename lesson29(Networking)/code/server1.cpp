#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void handleClient(int clientSock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    // Пример чтения данных от клиента
    ssize_t bytesRead = recv(clientSock, buffer, sizeof(buffer) - 1, 0);
    if (bytesRead == -1) {
        std::cerr << "Ошибка при чтении данных от клиента: " << strerror(errno) << std::endl;
        close(clientSock);
        return;
    }

    std::cout << "Получены данные от клиента: " << buffer << std::endl;

    // Пример отправки данных обратно клиенту
    const char* response = "Привет от сервера!";
    ssize_t bytesSent = send(clientSock, response, strlen(response), 0);
    if (bytesSent == -1) {
        std::cerr << "Ошибка при отправке данных клиенту: " << strerror(errno) << std::endl;
        close(clientSock);
        return;
    }

    std::cout << "Данные успешно отправлены клиенту." << std::endl;
    while (true)
    {
    }
    

    close(clientSock);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Ошибка при создании сокета: " << strerror(errno) << std::endl;
        return 1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(SERVER_PORT);

    if (bind(sockfd, (struct sockaddr*)&address, sizeof(address)) == -1) {
        std::cerr << "Ошибка при привязке сокета: " << strerror(errno) << std::endl;
        close(sockfd);
        return 1;
    }

    if (listen(sockfd, 5) == -1) {
        std::cerr << "Ошибка при установке сокета в режим прослушивания: " << strerror(errno) << std::endl;
        close(sockfd);
        return 1;
    }

    std::cout << "Сервер запущен и ожидает подключений..." << std::endl;

    while (true) {
        int clientSock = accept(sockfd, nullptr, nullptr);
        if (clientSock == -1) {
            std::cerr << "Ошибка при принятии входящего подключения: " << strerror(errno) << std::endl;
            close(sockfd);
            return 1;
        }

        std::cout << "Установлено новое подключение!" << std::endl;

        handleClient(clientSock);
    }

    close(sockfd);
    return 0;
}
