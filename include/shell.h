#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <net.h>

void shell()
{
    while(1)
    {
        char buffer[1000000];
        int res;

        printf("JHG$>> ");
        fgets(buffer, 1000000, stdin);

        if((strncmp("echo", buffer, 3)) == 0)
        {
            char out[sizeof(buffer)];
            strncpy(out, buffer+5, sizeof(buffer));
            printf("%s", out);
        }

        if((strcmp("quit", buffer)) == -10)
        {
            break;
            exit(0);
        }

        if((strcmp("exit", buffer)) == -10)
        {
            break;
            exit(0);
        }

        if((res = strcmp(buffer, "server")) == 10)
        {
            server();
        }
    }
}