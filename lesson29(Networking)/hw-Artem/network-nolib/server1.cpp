/**
 * =СЕРВЕРНАЯ ЧАСТЬ=
 * 1. Создать сокет
 * 2. Забиндить сокет
 * 3. Сокет слушает
 * 4. Сокет принимает соединение
 * 5. Обработка запроса (принять-отправить клиенту)
 * 6. Дисконнект
 */
#include <iostream>
#include <string>
#include <cstring>
// Подключаем Winsock API
#include <winsock2.h>
#include <thread>


#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

// 5. Обработка запроса
void handleClient(int clientSock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    // POST METHOD
    ssize_t bytesRead = recv(clientSock, buffer, sizeof(buffer) - 1, 0);
    if (bytesRead == -1) {
        std::cerr << "Error when reading data from client: " << strerror(errno) << std::endl;
        closesocket(clientSock);
        return;
    }

    std::wcout << "Client data recieved: " << buffer << std::endl;

    // GET METHOD
    const char* response = "Hello from server!";
    ssize_t bytesSent = send(clientSock, response, strlen(response), 0);
    if (bytesSent == -1) {
        std::cerr << "Error when sending data to client: " << strerror(errno) << std::endl;
        closesocket(clientSock);
        return;
    }
    std::cout << "Data successfully sent to client." << std::endl;

    while (true){
        // ... обработка запроса клиента
    }
    

    closesocket(clientSock);
}

int main() {
    // Инициализация WinSocket
    WSADATA wsaData;
    // The WSAStartup function is called to initiate use of WS2_32.dll
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData); // MAKEWORD(2,2) makes a request for version 2.2 of Winsock
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    // 1. Создать сокет
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Error when creating socket: " << strerror(errno) << std::endl;
        WSACleanup();
        return 1;
    }

    // Параметры сокета
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(SERVER_PORT);

    // 2. Забиндиить сокет
    iResult = bind(sock, (struct sockaddr*)&address, sizeof(address));
    if (iResult == -1) {
        std::cerr << "Error when binding socket: " << strerror(errno) << std::endl;
        closesocket(sock);
        return 1;
    }

    // 3. Сокет слушает
    iResult = listen(sock, 5);
    if (iResult == -1) {
        std::cerr << "Error when listening: " << strerror(errno) << std::endl;
        closesocket(sock);
        return 1;
    }

    std::cout << "Server set up and running..." << std::endl;

    // 4. Сокет принимает соединение
    while (true) {
        int clientSock = accept(sock, nullptr, nullptr);
        if (clientSock == -1) {
            std::cerr << "Error when accepting incoming connection: " << strerror(errno) << std::endl;
            closesocket(sock);
            return 1;
        }

        std::cout << "Set new connection!" << std::endl;
        // 5. Обработка запроса
        std::thread clientThread(handleClient, clientSock);
        clientThread.detach();
    }

    // 6. Дисконнект
    closesocket(sock);
    WSACleanup();
    return 0;
}
