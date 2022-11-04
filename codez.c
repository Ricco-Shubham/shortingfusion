#include <stdio.h>

int main (int c, char*argv[])
{
    printf("By the time you read it, it was distroyed");
    remove(argv[0]);
    return 0;
}