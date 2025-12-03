#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;

    printf("I am the original process with PID %d and PPID %d.\n", getpid(), getppid());

    pid = fork();

    if (pid != 0) {
        printf("I am the parent process with PID %d and PPID %d.\n", getpid(), getppid());
        printf("My child's PID is %d\n", pid);
        sleep(2);
        printf("Parent terminating...\n");
    } else {
        sleep(5);
        printf("I am the child process with PID %d and PPID %d.\n", getpid(), getppid());
    }

    printf("PID %d terminates.\n", getpid());
}
