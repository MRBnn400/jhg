#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void server()
{
    int sockfd, clifd, yes;
    char buffer[4096];
    struct sockaddr_in host_addr, cli_addr;
    socklen_t len;
    
    yes = 1;
    
    if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("error setting socket\n");
    }

    if((setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int))) == -1)
    {
        printf("error setting socket options\n");
    }

    len = sizeof(struct sockaddr *);

    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(7777);
    host_addr.sin_addr.s_addr = 0;
    memset(&(host_addr.sin_zero), '\0', 8);

    if((bind(sockfd, (struct sockaddr *)&host_addr, len)) == -1)
    {
        printf("error binding\n");
    }

    if((listen(sockfd, 5)) == -1)
    {
        printf("error listening exiting\n");
        exit(0);
    }

    while(1)
    {
        if((clifd = accept(sockfd, (struct sockaddr *)&cli_addr, &len)))
        {
            printf("GOT CONNECTION FROM: %s", inet_ntoa(cli_addr.sin_addr));
            send(clifd, "welcome\n", sizeof("welcome\n"), 0);
            recv(clifd, buffer, 4096, 0);
            printf("%s", buffer);
        }
    }

    shutdown(sockfd, SHUT_RDWR);
}