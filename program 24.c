
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char write_buffer[] = "Welcome to UNIX System Calls";
    char read_buffer[100];

    // Create a file
    fd = creat("sample.txt", 0644);

    if(fd < 0)
    {
        perror("File creation failed");
        exit(1);
    }

    printf("File created successfully.\n");

    close(fd);

    // Open the file for writing
    fd = open("sample.txt", O_WRONLY);

    if(fd < 0)
    {
        perror("File opening failed");
        exit(1);
    }

    // Write data into the file
    write(fd, write_buffer, strlen(write_buffer));

    printf("Data written successfully.\n");

    close(fd);

    // Open the file for reading
    fd = open("sample.txt", O_RDONLY);

    if(fd < 0)
    {
        perror("File opening failed");
        exit(1);
    }

    // Read data from the file
    int n = read(fd, read_buffer, sizeof(read_buffer) - 1);

    if(n < 0)
    {
        perror("File reading failed");
        close(fd);
        exit(1);
    }

    read_buffer[n] = '\0';

    printf("Data read from file: %s\n", read_buffer);

    // Close the file
    close(fd);

    printf("File closed successfully.\n");

    return 0;
}

