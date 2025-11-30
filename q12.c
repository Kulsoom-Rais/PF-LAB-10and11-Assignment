#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0;
    int inWord = 0;

    
    printf("Enter the filename: ");
    scanf("%s", filename);

   
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        charCount++;

        if (ch == '\n') {
            lineCount++;
        }

   
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            wordCount++;
            inWord = 1;
        }
    }

   
    if (charCount > 0 && ch != '\n') {
        lineCount++;
    }

    fclose(file);

    printf("\nFile Analysis:\n");
    printf("Total Characters: %d\n", charCount);
    printf("Total Words     : %d\n", wordCount);
    printf("Total Lines     : %d\n", lineCount);

    return 0;
}


