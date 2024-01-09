#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    if (fork() == 0)
    {
        printf("This is the parent process");
    }
    fork();
    printf("Hello from process %d\n", getpid());
    exit(0);
}