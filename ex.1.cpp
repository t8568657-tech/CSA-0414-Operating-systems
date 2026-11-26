#include <stdio.h>
#include <string.h>
#include <ctype.h>
void findFirst(char c, char *result);
void findFirst(char c, char *result) {
    if (!isupper(c)) {
      
        strncat(result, &c, 1);
    } else {
        
        if (c == 'F') {
            strcat(result, "(id");
        }
       
    }
}
int main() {
    char nt;
    char firstResult[20] = "";
    printf("Enter Non-terminal: ");
    scanf("%c", &nt);
    findFirst(nt, firstResult);
    printf("FIRST(%c) = {%s}\n", nt, firstResult);
    return 0;
}
