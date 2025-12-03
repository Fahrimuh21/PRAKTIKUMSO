#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid;

    pid = fork();

    if (pid != 0) {
        while (1)
            sleep(30);   // Parent hidup tapi tidak wait()
    } 
    else {
        exit(0);        // Child langsung selesai
    }
}
