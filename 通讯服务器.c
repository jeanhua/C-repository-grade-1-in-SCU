#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 5
#define BUFFER_SZ 2048

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Cannot create socket");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return EXIT_FAILURE;
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        return EXIT_FAILURE;
    }

    printf("Server is listening on port %d\n", port);

    while (1) {
        socklen_t client_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);

        if (client_socket < 0) {
            perror("Accept failed");
            return EXIT_FAILURE;
        }

        printf("Accepted a client connection\n");

        char buffer[BUFFER_SZ];
        memset(buffer, 0, BUFFER_SZ);
        if (recv(client_socket, buffer, BUFFER_SZ, 0) < 0) {
            perror("Recv failed");
            return EXIT_FAILURE;
        }

        printf("Client: %s\n", buffer);

        memset(buffer, 0, BUFFER_SZ);
        fgets(buffer, BUFFER_SZ, stdin);
        if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
            perror("Send failed");
            return EXIT_FAILURE;
        }

        close(client_socket);
    }

    close(server_socket);

    return EXIT_SUCCESS;
}
