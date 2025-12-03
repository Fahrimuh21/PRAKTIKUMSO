#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int pid;

    printf("Hello World!\n");
    printf("I am the parent process and pid is : %d .\n", getpid());

    pid = fork();

    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("Here I am just after forking\n");

    if (pid == 0)
        printf("I am the child process and pid is : %d.\n", getpid());
    else
        printf("I am the parent process and pid is: %d .\n", getpid());

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}
