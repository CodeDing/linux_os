#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 4444

int main(int argc, char *argv[]) {
    int sock_fd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char buffer[1024];

    if (argc < 2) {
        perror("Need hostname");
        exit(1);
    }

    if ((host = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family  = AF_INET;
    server_addr.sin_port    = htons(PORT);
    server_addr.sin_addr    = *((struct in_addr *)host->h_addr);

    if (connect(sock_fd, (struct sockaddr *)(&server_addr), sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Please input something:\n");
    fgets(buffer, 1024, stdin);
    write(sock_fd, buffer, strlen(buffer));
    close(sock_fd);

    return 0;
}
