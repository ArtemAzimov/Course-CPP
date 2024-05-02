#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cerr << "Ошибка при создании сокета: " << strerror(errno) << std::endl;
        return 1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

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

        // Обработка подключения...

        close(clientSock);
    }

    close(sockfd);
    return 0;
}
