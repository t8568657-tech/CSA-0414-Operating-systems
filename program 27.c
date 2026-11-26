
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *entry;

    // Open the current directory
    dir = opendir(".");

    if(dir == NULL)
    {
        printf("Unable to open directory.\n");
        exit(1);
    }

    printf("Files and Directories:\n\n");

    // Read directory entries
    while((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}

