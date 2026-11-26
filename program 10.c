
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

struct message
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    int msgid;
    struct message msg;

    // Create message queue
    msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);

    if(msgid == -1)
    {
        perror("Message queue creation failed");
        exit(1);
    }

    // Create child process
    pid_t pid = fork();

    if(pid < 0)
    {
        perror("Fork failed");
        msgctl(msgid, IPC_RMID, NULL);
        exit(1);
    }

    if(pid == 0)
    {
        // Child process receives message
        if(msgrcv(msgid, &msg, sizeof(msg.msg_text),
                  1, 0) == -1)
        {
            perror("Message receiving failed");
            exit(1);
        }

        printf("\nChild Process:\n");
        printf("Message received: %s\n", msg.msg_text);
    }
    else
    {
        // Parent process sends message
        msg.msg_type = 1;
        strcpy(msg.msg_text, "Hello! Message Queue IPC");

        printf("Parent Process:\n");
        printf("Message sent: %s\n", msg.msg_text);

        if(msgsnd(msgid, &msg, sizeof(msg.msg_text), 0) == -1)
        {
            perror("Message sending failed");
            wait(NULL);
            msgctl(msgid, IPC_RMID, NULL);
            exit(1);
        }

        wait(NULL);

        // Delete message queue
        msgctl(msgid, IPC_RMID, NULL);

        printf("\nMessage queue removed successfully.\n");
    }

    return 0;
}

