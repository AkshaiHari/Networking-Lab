#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

#define buffsize 256
#define port 12340

int main()
{
    char buff[buffsize];
    char filename[20];
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    int newsockfd;
    struct sockaddr_in server_address,client_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if(bind(sockfd,(struct socketaddr*)&server_address,sizeof(server_address)))
    {
        perror("BIND");
    }
    if(listen(sockfd,5)==-1)
    {
        perror("LISTEN");
    }
    socklen_t addr_size = sizeof(server_address);
    newsockfd = accept(sockfd,(struct sockaddr*)&server_address,&addr_size);

    printf("ENTER THE FILE NAME : ");
    scanf("%s",filename);
    send(newsockfd,filename,sizeof(filename),0);

    while(1)
    {
        int recvcheck = recv(newsockfd,buff,sizeof(buff),0)
        if(recvcheck==-1)
        {
            perror("recv");
        }
        if(recvcheck==0)
        {
            break;
        }
        printf("%s",filename);
    }
    close(sockfd);
    close(newsockfd);
}