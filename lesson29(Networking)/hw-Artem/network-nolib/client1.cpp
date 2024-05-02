/**
 * =КЛИЕНТСКАЯ ЧАСТЬ=
 * 1. Создать сокет
 * 2. Подключиться к серверу
 * 3. Отправить и принять запрос от сервера
 * 4. Дисконнект
 */

#include <iostream>
#include <string>
#include <cstring>
// Подключаем Winsock API
#include <winsock2.h>
// Использовать для линковки в MSVS, иначе - в CMakeLists
// #pragma comment(lib, "Ws2_32.lib")

#define SERVER_IP "127.0.0.1"
// #define SERVER_IP "1.1.1.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    // Initialize Winsock
    // The WSADATA structure contains information about the Windows Sockets implementation
    WSADATA wsaData;
    // The WSAStartup function is called to initiate use of WS2_32.dll
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData); // MAKEWORD(2,2) makes a request for version 2.2 of Winsock
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    // 1. Создать сокет
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Could not create socket" << std::endl;
        WSACleanup();
        return 1;
    }

    // Указываем данные сокета для подключения
    sockaddr_in serverAddress{};
    serverAddress.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);

    // 2. Подключиться к серверу
    if (connect(sock, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Connection failed: " << WSAGetLastError() << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }
    std::cout << "Connected successfully" << std::endl;

    // 3. Отправить и принять запрос от сервера
    const char* message = "Hello, server!";
    iResult = send(sock, message, strlen(message), 0);
    if (iResult == -1) {
        std::cerr << "Error when sending data to server: " << strerror(errno) << std::endl;
        closesocket(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    // Выделить память под сообщение от сервера и заполнить нулями
    memset(buffer, 0, sizeof(buffer));

    ssize_t bytesRead = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytesRead == -1) {
        std::cerr << "Error when reading from server: " << strerror(errno) << std::endl;
        closesocket(sock);
        return 1;
    }
    std::cout << "Recieved data from server: " << buffer << std::endl;


    // 4. Дисконнект
    closesocket(sock);
    WSACleanup();
    return 0;
}
