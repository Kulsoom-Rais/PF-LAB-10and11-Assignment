
#include <stdio.h>
#include <string.h>

void reverse(char *str, int start, int end) {
    if (start >= end) {
        return;  // Base case: indices have met or crossed
    }

    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call inward
    reverse(str, start + 1, end - 1);
}

int main() {
char s[]="hello";


    reverse(s, 0, strlen(s) - 1);

    printf("Reversed: %s\n", s);
    return 0;
}
