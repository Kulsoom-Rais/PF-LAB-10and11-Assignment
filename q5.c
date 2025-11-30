#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 50


struct Player {
    char name[50];
    int age;
    char position[30];
};


struct Team {
    char name[50];
    char sport[30];
    struct Player players[MAX_PLAYERS];
    int playerCount;
};


void addPlayer(struct Team *team);
void searchByPosition(struct Team team);
void displayTeamDetails(struct Team team);

int main() {
    struct Team team;
    team.playerCount = 0;


    printf("Enter team name: ");
    fgets(team.name, 50, stdin);
    team.name[strcspn(team.name, "\n")] = '\0';

    printf("Enter sport: ");
    fgets(team.sport, 30, stdin);
    team.sport[strcspn(team.sport, "\n")] = '\0';

    int choice;

    do {
        printf("\n===== Team Management System =====\n");
        printf("1. Add Player\n");
        printf("2. Search Player by Position\n");
        printf("3. Display Team Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addPlayer(&team);
                break;
            case 2:
                searchByPosition(team);
                break;
            case 3:
                displayTeamDetails(team);
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


void addPlayer(struct Team *team) {
    if (team->playerCount >= MAX_PLAYERS) {
        printf("Cannot add more players. Team is full.\n");
        return;
    }
else{
	

    printf("\nEnter player name: ");
    fgets(team->players[team->playerCount].name, 50, stdin);
    team->players[team->playerCount].name[strcspn(team->players[team->playerCount].name, "\n")] = '\0';

    printf("Enter player age: ");
    scanf("%d", &team->players[team->playerCount].age);
    getchar(); 

    printf("Enter player position: ");
    fgets(team->players[team->playerCount].position, 30, stdin);
    team->players[team->playerCount].position[strcspn(team->players[team->playerCount].position, "\n")] = '\0';

    team->playerCount++;
    printf("Player added successfully!\n");}
}


void searchByPosition(struct Team team) {
    if (team.playerCount == 0) {
        printf("No players in the team.\n");
        return;
    }

    char position[30];
    printf("\nEnter position to search: ");
    fgets(position, 30, stdin);
    position[strcspn(position, "\n")] = '\0';

    int found = 0;
    printf("\nPlayers in position '%s':\n", position);
    int i;
    for (i = 0; i < team.playerCount; i++) {
        if (strcmp(team.players[i].position, position) == 0) {
            printf("Name: %s, Age: %d\n", team.players[i].name, team.players[i].age);
            found = 1;
        }
    }

    if (!found) {
        printf("No players found in this position.\n");
    }
}


void displayTeamDetails(struct Team team) {
    printf("\n===== Team Details =====\n");
    printf("Team Name: %s\n", team.name);
    printf("Sport    : %s\n", team.sport);
    printf("Players (%d):\n", team.playerCount);
    int i;
    for (i = 0; i < team.playerCount; i++) {
        printf("  Name: %s, Age: %d, Position: %s\n",
               team.players[i].name,
               team.players[i].age,
               team.players[i].position);
    }
    printf("-------------------------\n");
}

