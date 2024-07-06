#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

#define port 12340
#define buffsize 256
FILE *fp;
int main()
{
  char buff[buffsize];
  char filename[20];
  int sockfd = socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in server_address,client_address;

  server_address.sin_family = AF_INET;
  server_address.sin_port=htons(port);
  server_address.sin_addr.s_addr = INADDR_ANY;

  int connfd = connect(sockfd,(struct sockaddr*)&server_address,sizeof(server_address));

  recv(sockfd,filename,sizeof(filename),0);
  printf("%s",filename);
  fp = fopen(filename,"r");

  if(fp==NULL)
  {
    perror("fopen");
  }
  else
  {
    while(fgets(buff,sizeof(buff),fp)!=NULL)
      {
        send(sockfd,buff,sizeof(buff),0);
      }
    fclose(fp);
  }
  close(sockfd);
}
