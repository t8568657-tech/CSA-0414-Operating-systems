
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd1, fd2, n;
    char buffer[1024];

    // Open source file
    fd1 = open("source.txt", O_RDONLY);

    if(fd1 < 0)
    {
        perror("Source file opening failed");
        exit(1);
    }

    // Create destination file
    fd2 = open("destination.txt",
               O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if(fd2 < 0)
    {
        perror("Destination file opening failed");
        close(fd1);
        exit(1);
    }

    // Copy contents from source to destination
    while((n = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        int written = 0;

        while(written < n)
        {
            int w = write(fd2, buffer + written, n - written);

            if(w <= 0)
            {
                perror("File writing failed");
                close(fd1);
                close(fd2);
                exit(1);
            }

            written += w;
        }
    }

    if(n < 0)
    {
        perror("File reading failed");
        close(fd1);
        close(fd2);
        exit(1);
    }

    printf("File copied successfully.\n");

    // Close both files
    close(fd1);
    close(fd2);

    return 0;
}

