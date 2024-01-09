#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    fork();
    fork();
    printf("Hello from process %d\n", getpid());
    exit(0);
}