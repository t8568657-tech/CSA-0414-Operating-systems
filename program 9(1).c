
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main()
{
    int shmid;
    char *shm;

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, 1024,
                   IPC_CREAT | 0666);

    if(shmid < 0)
    {
        perror("Shared memory creation failed");
        exit(1);
    }

    // Attach shared memory
    shm = (char *)shmat(shmid, NULL, 0);

    if(shm == (char *)-1)
    {
        perror("Shared memory attachment failed");
        shmctl(shmid, IPC_RMID, NULL);
        exit(1);
    }

    // Create child process
    pid_t pid = fork();

    if(pid < 0)
    {
        perror("Fork failed");
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
        exit(1);
    }

    if(pid == 0)
    {
        // Child process reads data
        sleep(1);

        printf("Child Process:\n");
        printf("Data received: %s\n", shm);

        shmdt(shm);
    }
    else
    {
        // Parent process writes data
        printf("Parent Process:\n");

        strcpy(shm, "Hello! Shared Memory IPC");

        printf("Data written: %s\n", shm);

        wait(NULL);

        // Detach and remove shared memory
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);

        printf("Shared memory removed successfully.\n");
    }

    return 0;
}

