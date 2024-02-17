#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#include <pthread.h>
#include<stdlib.h>
#pragma comment(lib, "pthreadVC2.lib")
#pragma comment(lib, "ws2_32.lib")


#define MAX_BUFFER_SIZE 1024

// 数据结构用于传递参数给线程
struct ThreadData {
    SOCKET socket;
};

// 线程函数用于接收消息
void* receiveThread(void* data) {
    struct ThreadData* threadData = (struct ThreadData*)data;
    SOCKET client_socket = threadData->socket;

    char buffer[MAX_BUFFER_SIZE];
    while (1) {
        int received_bytes = recv(client_socket, buffer, sizeof(buffer), 0);
        if (received_bytes == SOCKET_ERROR) {
            printf("Error receiving data from server: %ld\n", WSAGetLastError());
            break;
        }
        else if (received_bytes == 0) {
            printf("Server closed the connection\n");
            break;
        }
        else {
            buffer[received_bytes] = '\0'; // 添加字符串结束符
            printf("%s\n", buffer);
        }
    }

    closesocket(client_socket);
    return NULL;
}

int main() {
    // 初始化 Winsock
    char name[20];
    printf_s("请输入你的昵称：\n");
    fgets(name, MAX_BUFFER_SIZE, stdin);
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize Winsock\n");
        return 1;
    }

    // 1. 创建套接字
    SOCKET client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == INVALID_SOCKET) {
        printf("Error creating socket: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // 2. 指定服务器地址和端口
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8888); // 服务器端口
    server_address.sin_addr.s_addr = inet_addr("121.48.197.147"); // 服务器IP地址

    // 3. 连接到服务器
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        printf("Error connecting to server: %ld\n", WSAGetLastError());
        closesocket(client_socket);
        WSACleanup();
        system("pause");
        return 1;
    }
    else
    {
        printf("已连接服务器\n");
    }
    // 创建接收线程
    struct ThreadData threadData;
    threadData.socket = client_socket;
    pthread_t receiveThreadId;
    if (pthread_create(&receiveThreadId, NULL, receiveThread, (void*)&threadData) != 0) {
        printf("Error creating receive thread\n");
        closesocket(client_socket);
        WSACleanup();
        return 1;
    }

    // 主线程用于发送消息
    char message[MAX_BUFFER_SIZE];
    char outmessage[2048];
    
    while (1) {
        fgets(message, MAX_BUFFER_SIZE, stdin);
        sprintf_s(outmessage, "IdName_%s:%s", name, message);
        send(client_socket, outmessage, strlen(outmessage), 0);
    }

    // 等待接收线程结束
    pthread_join(receiveThreadId, NULL);

    // 关闭套接字和清理资源
    closesocket(client_socket);
    WSACleanup();

    return 0;
}
