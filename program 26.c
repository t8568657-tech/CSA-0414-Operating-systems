
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char data[100];
    char ch;

    // 1. Create a file
    fp = fopen("sample.txt", "w");

    if(fp == NULL)
    {
        printf("File creation failed.\n");
        return 1;
    }

    printf("File created successfully.\n");

    // 2. Write data into the file
    printf("Enter data to write into file: ");
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    printf("Data written successfully.\n");

    fclose(fp);

    // 3. Append data to the file
    fp = fopen("sample.txt", "a");

    if(fp == NULL)
    {
        printf("File opening failed.\n");
        return 1;
    }

    fputs("File management operations in C.\n", fp);
    printf("Data appended successfully.\n");

    fclose(fp);

    // 4. Read data from the file
    fp = fopen("sample.txt", "r");

    if(fp == NULL)
    {
        printf("File reading failed.\n");
        return 1;
    }

    printf("\nFile contents:\n");

    while((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    fclose(fp);

    // 5. Rename the file
    if(rename("sample.txt", "newfile.txt") == 0)
        printf("\nFile renamed successfully.\n");
    else
        printf("\nFile renaming failed.\n");

    // 6. Delete the file
    if(remove("newfile.txt") == 0)
        printf("File deleted successfully.\n");
    else
        printf("File deletion failed.\n");

    return 0;
}

