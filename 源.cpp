#include <stdio.h>
#include <winsock2.h>
#include <pthread.h>
#include <easyx.h>

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
            outtextxy(10, 10, buffer);  // �ڴ�������ʾ���յ�����Ϣ
        }
    }

    closesocket(client_socket);
    return NULL;
}

int main() {
    // ��ʼ�� Winsock
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
    server_address.sin_port = htons(8080); // �������˿�
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // ������IP��ַ

    // 3. ���ӵ�������
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        printf("Error connecting to server: %ld\n", WSAGetLastError());
        closesocket(client_socket);
        WSACleanup();
        return 1;
    }

    // ��ʼ��ͼ�δ���
    initgraph(800, 600);

    // ���������߳�
    struct ThreadData threadData;
    threadData.socket = client_socket;
    pthread_t receiveThreadId;
    if (pthread_create(&receiveThreadId, NULL, receiveThread, (void*)&threadData) != 0) {
        printf("Error creating receive thread\n");
        closesocket(client_socket);
        WSACleanup();
        closegraph();
        return 1;
    }

    // ���߳����ڷ�����Ϣ
    char message[MAX_BUFFER_SIZE];
    while (1) {
        printf("Enter message to send to server (type 'exit' to quit): ");
        fgets(message, MAX_BUFFER_SIZE, stdin);

        if (strcmp(message, "exit\n") == 0) {
            break;
        }

        send(client_socket, message, strlen(message), 0);
    }

    // �ȴ������߳̽���
    pthread_join(receiveThreadId, NULL);

    // �ر��׽��ֺ�������Դ
    closesocket(client_socket);
    WSACleanup();

    // �ر�ͼ�δ���
    closegraph();

    return 0;
}
