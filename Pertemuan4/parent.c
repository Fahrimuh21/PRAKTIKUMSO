// Parent Program
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h> // <- untuk wait()

int main(void)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0)
    {
        // Jika fork gagal
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        // Child process: menjalankan child program
        execl("/bin/sh", "sh", "-c", "./child", (char *)0);

        // Jika execl gagal
        perror("execl failed");
        exit(1);
    }

    // Parent process
    while (1)
    {
        sleep(1);
        printf("Parent running...\n");

        // Jika child selesai → hentikan parent
        pid_t result = waitpid(pid, &status, WNOHANG);
        if (result == pid)
        {
            printf("Child exited. Status = %d\n", status);
            break;
        }
    }

    printf("End of program\n");
    return 0;
}

