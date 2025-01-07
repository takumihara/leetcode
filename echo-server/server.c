#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 80
#define REQUEST_SIZE 1000

int main() {
  struct sockaddr_in addr;
  int socket_fd;
  if ((socket_fd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(PORT);

  if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // listenのqueueのsizeを0にしても2個目のクライアントがconnectできたのなぜ？
  // -> 同時に接続リクエストが来た時。connectが完了したら、queueからは消える。
  if (listen(socket_fd, 0) < 0) {
    perror("listen");
    return EXIT_FAILURE;
  }

  while (1) {
    printf("waiting for new connection\n");

    int accept_fd;
    struct sockaddr_storage client_addr;
    socklen_t addr_size = sizeof(client_addr);

    if ((accept_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &addr_size)) == -1) {
      perror("accept");
      return EXIT_FAILURE;
    }

    char request[REQUEST_SIZE] = {0};
    ssize_t size;
    if ((size = read(accept_fd, request, REQUEST_SIZE)) == -1) {
      perror("read");
      return EXIT_FAILURE;
    }

    request[size] = '\0';

    printf("request: %s\n", request);

    if (write(accept_fd, request, size) == -1) {
      perror("write");
      return EXIT_FAILURE;
    }

    printf("sent response: %s\n", request);
    close(accept_fd);
  }

  close(socket_fd);
}