#include <stdio.h>

int main() {
    FILE *file;
    int count = 0;
    char line[100];


    file = fopen("log.txt", "r");
    if (file != NULL) {
        while (fgets(line, sizeof(line), file)) {
            count++;
        }
        fclose(file);
    }

  
    file = fopen("log.txt", "a");
    if (file == NULL) {
        printf("Unable to open log.txt\n");
        return 1;
    }

    fprintf(file, "Program executed: #%d\n", count + 1);
    fclose(file);

    printf("Execution logged as #%d\n", count + 1);
    return 0;
}

