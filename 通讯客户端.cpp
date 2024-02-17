#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#include <pthread.h>
#include<stdlib.h>
#pragma comment(lib, "pthreadVC2.lib")
#pragma comment(lib, "ws2_32.lib")


#define MAX_BUFFER_SIZE 1024

// ���ݽṹ���ڴ��ݲ������߳�
struct ThreadData {
    SOCKET socket;
};

// �̺߳������ڽ�����Ϣ
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
            buffer[received_bytes] = '\0'; // ����ַ���������
            printf("%s\n", buffer);
        }
    }

    closesocket(client_socket);
    return NULL;
}

int main() {
    // ��ʼ�� Winsock
    char name[20];
    printf_s("����������ǳƣ�\n");
    fgets(name, MAX_BUFFER_SIZE, stdin);
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize Winsock\n");
        return 1;
    }

    // 1. �����׽���
    SOCKET client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == INVALID_SOCKET) {
        printf("Error creating socket: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // 2. ָ����������ַ�Ͷ˿�
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8888); // �������˿�
    server_address.sin_addr.s_addr = inet_addr("121.48.197.147"); // ������IP��ַ

    // 3. ���ӵ�������
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        printf("Error connecting to server: %ld\n", WSAGetLastError());
        closesocket(client_socket);
        WSACleanup();
        system("pause");
        return 1;
    }
    else
    {
        printf("�����ӷ�����\n");
    }
    // ���������߳�
    struct ThreadData threadData;
    threadData.socket = client_socket;
    pthread_t receiveThreadId;
    if (pthread_create(&receiveThreadId, NULL, receiveThread, (void*)&threadData) != 0) {
        printf("Error creating receive thread\n");
        closesocket(client_socket);
        WSACleanup();
        return 1;
    }

    // ���߳����ڷ�����Ϣ
    char message[MAX_BUFFER_SIZE];
    char outmessage[2048];
    
    while (1) {
        fgets(message, MAX_BUFFER_SIZE, stdin);
        sprintf_s(outmessage, "IdName_%s:%s", name, message);
        send(client_socket, outmessage, strlen(outmessage), 0);
    }

    // �ȴ������߳̽���
    pthread_join(receiveThreadId, NULL);

    // �ر��׽��ֺ�������Դ
    closesocket(client_socket);
    WSACleanup();

    return 0;
}
