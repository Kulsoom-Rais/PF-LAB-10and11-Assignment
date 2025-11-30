#include <stdio.h>

int main() {
    FILE *file1, *file2, *file3;
    char ch;

    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        printf("Unable to open file1.txt\n");
        return 1;
    }

    
    file2 = fopen("file2.txt", "r");
    if (file2 == NULL) {
        printf("Unable to open file2.txt\n");
        fclose(file1);
        return 1;
    }

   
    file3 = fopen("merged.txt", "w");
    if (file3 == NULL) {
        printf("Unable to create merged.txt\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, file3);
    }


    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, file3);
    }

    printf("Files merged successfully into merged.txt\n");

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}

