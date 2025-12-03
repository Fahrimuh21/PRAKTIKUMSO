#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int pid;
    int status;

    printf("Hello World!\n");

    pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("I am the child process.\n");
        sleep(2);
    } else {
        wait(&status);
        printf("I am the parent process.\n");
    }
}
