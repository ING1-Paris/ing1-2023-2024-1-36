#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 10

// Structure pour stocker les informations du joueur
struct Player {
    char name[50];
    int score;
};

// Fonction pour afficher le classement des joueurs
void displayRanking(struct Player players[], int numPlayers) {
    printf("\nClassement des joueurs :\n");
    printf("------------------------\n");
    printf("| %-20s | %-6s |\n", "Nom", "Points");
    printf("------------------------\n");

    for (int i = 0; i < numPlayers; ++i) {
        printf("| %-20s | %-6d |\n", players[i].name, players[i].score);
    }

    printf("------------------------\n\n");
}

// Fonction pour modifier le score d'un joueur
void modifyScore(struct Player players[], int numPlayers) {
    char playerName[50];
    int newScore;

    printf("Entrez le nom du joueur dont vous voulez modifier le score : ");
    scanf("%s", playerName);

    int playerIndex = -1;

    // Recherche du joueur dans la liste
    for (int i = 0; i < numPlayers; ++i) {
        if (strcmp(players[i].name, playerName) == 0) {
            playerIndex = i;
            break;
        }
    }

    if (playerIndex != -1) {
        // Joueur trouvé, modification du score
        printf("Nouveau score pour le joueur %s : ", playerName);
        scanf("%d", &newScore);

        players[playerIndex].score = newScore;
        printf("Score mis à jour avec succès.\n\n");
    } else {
        // Joueur non trouvé
        printf("Erreur : Joueur non trouvé.\n\n");
    }
}

int main() {
    struct Player players[MAX_PLAYERS];
    int numPlayers = 0;

    while (1) {
        char input[50];
        printf("Entrez un nom de joueur (ou tapez 'SCORE' pour afficher le classement, 'MODIFY' pour modifier le score d'un joueur) : ");
        scanf("%s", input);

        if (strcmp(input, "SCORE") == 0) {
            displayRanking(players, numPlayers);
            continue;
        } else if (strcmp(input, "MODIFY") == 0) {
            modifyScore(players, numPlayers);
            continue;
        }

        // Vérifier si le nom existe déjà
        int found = 0;
        for (int i = 0; i < numPlayers; ++i) {
            if (strcmp(players[i].name, input) == 0) {
                found = 1;
                printf("Erreur : Ce nom de joueur existe déjà.\n\n");
                break;
            }
        }

        if (found) {
            continue;
        }

        // Ajouter un nouveau joueur
        strcpy(players[numPlayers].name, input);
        players[numPlayers].score = 0;
        numPlayers++;

        printf("Le joueur %s a été ajouté avec succès.\n\n", input);
    }

    return 0;
}
