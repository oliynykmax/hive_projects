#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct s_client {
  int id;
  int fd;
  char *buf;
} t_client;

t_client *g_clients = NULL;
int g_nb = 0;
char msgbuf[100000];

int extract_message(char **buf, char **msg) {
  char *newbuf;
  int i;

  *msg = 0;
  if (*buf == 0)
    return (0);
  i = 0;
  while ((*buf)[i]) {
    if ((*buf)[i] == '\n') {
      newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
      if (newbuf == 0)
        return (-1);
      strcpy(newbuf, *buf + i + 1);
      *msg = *buf;
      (*msg)[i + 1] = 0;
      *buf = newbuf;
      return (1);
    }
    i++;
  }
  return (0);
}

char *str_join(char *buf, char *add) {
  char *newbuf;
  int len;

  if (buf == 0)
    len = 0;
  else
    len = strlen(buf);
  newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
  if (newbuf == 0)
    return (0);
  newbuf[0] = 0;
  if (buf != 0)
    strcat(newbuf, buf);
  free(buf);
  strcat(newbuf, add);
  return (newbuf);
}

void fatal(void) {
  write(2, "Fatal error\n", 12);
  exit(1);
}

void broadcast(int exclude, char *msg) {
  for (int i = 0; i < g_nb; i++) {
    if (g_clients[i].id != exclude)
      send(g_clients[i].fd, msg, strlen(msg), 0);
  }
}

void remove_client(int idx) {
  close(g_clients[idx].fd);
  free(g_clients[idx].buf);
  g_nb--;
  for (int i = idx; i < g_nb; i++)
    g_clients[i] = g_clients[i + 1];
  if (g_nb == 0) {
    free(g_clients);
    g_clients = NULL;
  } else
    g_clients = realloc(g_clients, sizeof(t_client) * g_nb);
}

void add_client(int fd, int id) {
  g_clients = realloc(g_clients, sizeof(t_client) * (g_nb + 1));
  g_clients[g_nb].fd = fd;
  g_clients[g_nb].id = id;
  g_clients[g_nb].buf = NULL;
  g_nb++;
}

int main(int argc, char **argv) {
  int sockfd, connfd, len;
  struct sockaddr_in servaddr, cli;
  int last_id = 0;

  if (argc != 2) {
    write(2, "Wrong number of arguments\n", 26);
    exit(1);
  }
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
    fatal();
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(2130706433);
  servaddr.sin_port = htons(atoi(argv[1]));
  if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    fatal();
  if (listen(sockfd, 128) != 0)
    fatal();
  len = sizeof(cli);
  int maxfd;
  fd_set readfds;
  while (1) {
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    maxfd = sockfd;
    for (int i = 0; i < g_nb; i++) {
      FD_SET(g_clients[i].fd, &readfds);
      if (g_clients[i].fd > maxfd)
        maxfd = g_clients[i].fd;
    }
    if (select(maxfd + 1, &readfds, NULL, NULL, NULL) == -1)
      continue;
    if (FD_ISSET(sockfd, &readfds)) {
      connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t *)&len);
      if (connfd >= 0) {
        add_client(connfd, last_id);
        sprintf(msgbuf, "server: client %d just arrived\n", last_id);
        broadcast(last_id, msgbuf);
        last_id++;
      }
    }
    for (int i = 0; i < g_nb; i++) {
      if (FD_ISSET(g_clients[i].fd, &readfds)) {
        char buf[100001];
        int ret = recv(g_clients[i].fd, buf, 100000, 0);
        if (ret <= 0) {
          int cid = g_clients[i].id;
          remove_client(i);
          sprintf(msgbuf, "server: client %d just left\n", cid);
          broadcast(cid, msgbuf);
          i--;
        } else {
          buf[ret] = 0;
          g_clients[i].buf = str_join(g_clients[i].buf, buf);
          char *line;
          while (extract_message(&g_clients[i].buf, &line) == 1) {
            sprintf(msgbuf, "client %d: %s", g_clients[i].id, line);
            broadcast(g_clients[i].id, msgbuf);
            free(line);
          }
        }
      }
    }
  }
}
