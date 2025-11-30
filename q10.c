#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int isPalindrome(char str[]) {
    char reversed[21];
    strcpy(reversed, str);

    reverseString(reversed);

    if (strcmp(str, reversed) == 0) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    char words[5][21];
    int n = 5;
    int i;

    printf("Enter %d words (max 20 characters each):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%20s", words[i]);
    }

    printf("\nPalindrome Check Results:\n");
    for (i = 0; i < n; i++) {
        if (isPalindrome(words[i])) {
            printf("%s: Palindrome\n", words[i]);
        } else {
            printf("%s: Not Palindrome\n", words[i]);
        }
    }

    return 0;
}


