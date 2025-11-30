#include <stdio.h>
#include <string.h>

int isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

int countVowelsRec(const char str[], int index) {
    if (index == strlen(str)) {  
        return 0;
    }

    int count = isVowel(str[index]) ? 1 : 0;
    return count + countVowelsRec(str, index + 1);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 

    int vowels = countVowelsRec(str, 0);
    printf("Number of vowels: %d\n", vowels);

    return 0;
}

