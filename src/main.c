#include <stdio.h>
#include <string.h>
#include <shell.h>

int main(int argc, char argv[])
{
    int res;
    if(argc > 1)
    {
        if((res = strcmp("--help", argv)) == 27)
        {
            printf("./build/main\n");
        }

        else
        {
            printf("try --help\n");
        }
    }

    else
    {
        shell();
    }

    return 0;
}