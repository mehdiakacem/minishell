#include <stdio.h>
#include <stdlib.h>
int main()
{
    int pid;
    int exit_status = 0;
    pid = fork();
    if (pid == 0)
        exit(10);
    wait(&exit_status);
    printf("%d", exit_status);
}