
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main()
{
    int fd, flags;
    char buffer[100];
    struct stat file_info;
    DIR *dir;
    struct dirent *entry;

    // Create and open a file
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if(fd < 0)
    {
        perror("File opening failed");
        exit(1);
    }

    printf("File opened successfully.\n");

    // Write data into file
    write(fd, "UNIX System Calls", 17);

    // Demonstrate fcntl()
    flags = fcntl(fd, F_GETFL);
    printf("\nFile access mode: %d\n", flags & O_ACCMODE);

    // Demonstrate lseek()
    lseek(fd, 0, SEEK_SET);

    printf("\nFile contents: ");
    int n = read(fd, buffer, sizeof(buffer) - 1);

    if(n < 0)
    {
        perror("Read failed");
        close(fd);
        exit(1);
    }

    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Demonstrate stat()
    if(stat("sample.txt", &file_info) == 0)
    {
        printf("\nFile Information:\n");
        printf("File size: %ld bytes\n",
               (long)file_info.st_size);
        printf("Inode number: %ld\n",
               (long)file_info.st_ino);
        printf("Number of links: %ld\n",
               (long)file_info.st_nlink);
    }
    else
    {
        perror("Stat failed");
    }

    close(fd);

    // Demonstrate opendir()
    dir = opendir(".");

    if(dir == NULL)
    {
        perror("Directory opening failed");
        exit(1);
    }

    printf("\nDirectory contents:\n");

    // Demonstrate readdir()
    while((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}

