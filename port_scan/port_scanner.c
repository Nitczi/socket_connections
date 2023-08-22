// A simple portscanner made by me, Nitczi.

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]){

   if(argc<2){
      printf("Use mode incorret\n");
      printf("./port_scanner target\n");
      return 1;
   }

   int mysock;
   int connection;
   int port_in = 1;
   int port_fin = 65535;
   char *targ;
   targ = argv[1];
   
   struct sockaddr_in address;

   for(int port=port_in; port<port_fin; port++){
      mysock = socket(AF_INET, SOCK_STREAM, 0);
      address.sin_family = AF_INET;
      address.sin_port = htons(port);
      address.sin_addr.s_addr = inet_addr(targ); 

      connection = connect(mysock, (struct sockaddr *)&address, sizeof(address));
   
      if( connection == 0 ){
         printf("PORT OPEN: %i\n", port);
         close(mysock);
         close(connection);  
      } else {
         close(mysock);
         close(connection);
      }

   }

   close(mysock);
   close(connection);

   return 0;
}
