#include <stdio.h>
#include <string.h>

int main() {
    int i;
    char words[5][21] = {"apple", "banana", "cherry", "mango", "pineapple"};

    char input[21];
    int found = 0;

    printf("Enter a fruit to search: ");
    scanf("%20s", input);

   
    for (i = 0; i < 5; i++) {
        if (strcmp(words[i], input) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}


