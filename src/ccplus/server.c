#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

int main(int argc, char* argv[]) {
    printf("Chat server is running.\n");
    int sock, port = 9001;
    struct sockaddr my_addr, in_addr;

    if ((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Can not create socket.\n");
        return -1;
    }
    memset(&my_addr, 0, sizeof(struct sockaddr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    my_addr.sin_port = htons(port);
    if (bind(sock, &my_addr, sizeof(my_addr)) {
        printf("Error on bind.\n");
        return -1;
    }
    if (listen(sock, 5)) {
        printf("Errorn on listen.\n");
        return -1;
    }
    while (accept(sock, &in_addr, sizeof(in_addr)) > 0) {
    }
    return 0;
}