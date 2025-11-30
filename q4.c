#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100


struct Movie {
    char title[50];
    char genre[30];
    char director[40];
    int releaseYear;
    float rating;
};


void addMovie(struct Movie movies[], int *count);
void searchByGenre(struct Movie movies[], int count);
void displayAllMovies(struct Movie movies[], int count);

int main() {
    struct Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    do {
        printf("\n===== Movie Management System =====\n");
        printf("1. Add New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;

            case 2:
                searchByGenre(movies, count);
                break;

            case 3:
                displayAllMovies(movies, count);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}


void addMovie(struct Movie movies[], int *count) {
    if (*count >= MAX_MOVIES) {
        printf("Movie list is full!\n");
        return;
    }

    printf("\nEnter movie title: ");
    fgets(movies[*count].title, 50, stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = '\0';

    printf("Enter genre: ");
    fgets(movies[*count].genre, 30, stdin);
    movies[*count].genre[strcspn(movies[*count].genre, "\n")] = '\0';

    printf("Enter director: ");
    fgets(movies[*count].director, 40, stdin);
    movies[*count].director[strcspn(movies[*count].director, "\n")] = '\0';

    printf("Enter release year: ");
    scanf("%d", &movies[*count].releaseYear);

    printf("Enter rating (0-10): ");
    scanf("%f", &movies[*count].rating);
    getchar(); // Clear newline

    (*count)++;
    printf("Movie added successfully!\n");
}


void searchByGenre(struct Movie movies[], int count) {
    if (count == 0) {
        printf("No movies available.\n");
        return;
    }

    char searchGenre[30];
    printf("\nEnter genre to search: ");
    
    fgets(searchGenre, 30, stdin);
    searchGenre[strcspn(searchGenre, "\n")] = '\0';

    printf("\nMovies in genre '%s':\n", searchGenre);

    int found = 0;
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, searchGenre) == 0) {
            printf("---------------------------------\n");
            printf("Title       : %s\n", movies[i].title);
            printf("Director    : %s\n", movies[i].director);
            printf("Year        : %d\n", movies[i].releaseYear);
            printf("Rating      : %.1f\n", movies[i].rating);
            found = 1;
        }
    }

    if (!found) {
        printf("No movies found in this genre.\n");
    }
}


void displayAllMovies(struct Movie movies[], int count) {
    if (count == 0) {
        printf("No movies available.\n");
        return;
    }

    printf("\n===== All Movies =====\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("---------------------------------\n");
        printf("Title       : %s\n", movies[i].title);
        printf("Genre       : %s\n", movies[i].genre);
        printf("Director    : %s\n", movies[i].director);
        printf("Release Year: %d\n", movies[i].releaseYear);
        printf("Rating      : %.1f\n", movies[i].rating);
    }
    printf("---------------------------------\n");
}

