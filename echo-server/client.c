
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 80
#define REQUEST_SIZE 1000
#define RESPONSE_SIZE 10000

void send_request(char *request) {
  int socket_fd = 0;
  struct sockaddr_in address;
  char response[RESPONSE_SIZE];

  // PF_INET: protocol family for IPv4
  // SOCK_STREAM: TCP
  if ((socket_fd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // AF_INET: address family for IPv4
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = htons(PORT);

  if (connect(socket_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }
  // send for TCP
  // sendto for UDP
  send(socket_fd, request, strlen(request), 0);

  int size = recv(socket_fd, response, RESPONSE_SIZE, 0);
  if (size == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }
  response[size] = '\0';
  printf("response: %s\n", response);

  close(socket_fd);
}

int main() {
  char request[REQUEST_SIZE] = {0};

  printf("type something to send: \n");

  read(STDIN_FILENO, request, REQUEST_SIZE - 1);

  send_request(request);

  return EXIT_SUCCESS;
}