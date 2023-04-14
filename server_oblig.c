#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


#define PORT 2021
#define BUFSIZE 300


void sjekk_error(int res, char *msg){
  if(res == -1){
    perror(msg);
    exit(EXIT_FAILURE);
  }
}

typedef struct{

}

int main(int argc, char **argv){

  if(argc != 3){
    printf("where is the port and ip??? \n" );
    return EXIT_FAILURE;
  }

  set_loss_probability(0);

  char *array = (char*) malloc(array_length * sizeof(char));

  int fd;
  struct sockaddr_in my_addr;

  fd = socket(AF_INET, SOCK_DGRAM, 0);
  sjekk_error(fd, "socket");

  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(argv[1]);
  my_addr.sin_addr.s_addr = INDADDR_ANY; //pga denne konstanten kan vi lytte på alt

  rc = bind(fd, &my_addr, (struct sockaddr*)sizeof(struct sockaddr_in));
  sjekk_error(rc, "bind");
  close(fd);
  EXIT_SUCCESS;




}
