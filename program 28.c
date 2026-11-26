
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[100];
    char pattern[100];
    char line[500];
    int found = 0;
    int line_no = 0;

    // Get filename
    printf("Enter file name: ");
    scanf("%99s", filename);

    // Get search pattern
    printf("Enter word to search: ");
    scanf("%99s", pattern);

    // Open file
    fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        exit(1);
    }

    printf("\nMatching lines:\n");

    // Read file line by line
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        line_no++;

        if(strstr(line, pattern) != NULL)
        {
            printf("%d: %s", line_no, line);
            found = 1;
        }
    }

    if(found == 0)
    {
        printf("Pattern not found.\n");
    }

    fclose(fp);

    return 0;
}

