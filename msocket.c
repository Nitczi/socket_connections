#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>

int main(void){
  int msocket;
  int conn;

  msocket = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in ip;

  ip.sin_family = AF_INET;
  ip.sin_port = htons(80);
  ip.sin_addr.s_addr = (inet_addr)("192.168.0.1");

  conn = connect(msocket, (struct sockaddr *)&ip, sizeof(ip));

  if(conn == 0){
    printf("Port Open\n");
    close(msocket);
    close(conn);
    return 0;
  } else {
    printf("Port Closed\n");
    close(msocket);
    close(conn);
    return 1;
  }
}
