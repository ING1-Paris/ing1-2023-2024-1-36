#include <stdio.h>
#include <string.h>
#include <unistd.h>

const int TEMPS_JEU = 120;

struct profil {
    char identifiant[100];
    char MDP[100];
    char pseudo[100];
};

// Déclaration des fonctions
void reglesDuJeu(void);
void nouveauJeu(struct profil);
void chargerPartie(void);
struct profil motDePasse(void);
void scores(void);
int connexion(struct profil);
int Menu(void);

int main() {
    // Appel de la fonction Menu pour démarrer le programme
    Menu();

    return 0;
}

// Fonction pour afficher le menu et gérer les choix
int Menu(void) {
    int choix;
    struct profil joueur;

    printf("***********************************************\n");
    printf("****************** SNOOPY GAME ****************\n");
    printf("***********************************************\n");
    printf("1. REGLES DU JEU\n");
    printf("2. NOUVEAU JEU\n");
    printf("3. CHARGER UNE PARTIE\n");
    printf("4. MOT DE PASSE\n");
    printf("5. SCORES\n");
    printf("6. QUITTER\n");
    printf("***********************************************\n");
    printf("***********************************************\n");

    scanf("%d", &choix);

    switch (choix) {
        case 1:
            reglesDuJeu();
            break;
        case 2:
            nouveauJeu(joueur);
            break;
        case 3:
            chargerPartie();
            break;
        case 4:
            joueur = motDePasse();
            break;
        case 5:
            scores();
            break;
        case 6:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix non valide\n");
            break;
    }

    return 0;
}

// Fonction pour afficher les règles du jeu
void reglesDuJeu(void) {
    printf("Le but de Snoopy est de récupérer 4 oiseaux aux 4 coins du niveau en un temps imparti. Le problème\n"
           "est que ces 4 oiseaux ne sont pas si faciles à récupérer. Une balle rebondit constamment dans le niveau\n"
           "afin de freiner Snoopy dans sa quête. Mais ce n'est pas tout, d'autres pièges sont présents comme des\n"
           "téléporteurs que la balle peut emprunter ou des cases piégées, voir même des blocs à pousser ou à\n"
           "casser...\n");
}

// Fonction pour commencer un nouveau jeu
void nouveauJeu(struct profil joueur) {
    // Appel de la fonction de connexion avec le profil du joueur
    int authentification = connexion(joueur);

    if (authentification) {
        printf("Authentification réussie\n");
        printf("Niveau 1\n");

        for (int i = TEMPS_JEU; i > 0; i--) {
            printf("TIMER: %d\n", i);
            sleep(1);
        }
    } else {
        printf("Identifiant ou mot de passe incorrect\n");
    }
}

// Fonction pour gérer la connexion
int connexion(struct profil joueur) {
    char identifiantDeCo[100];
    char MDPDeCo[100];
    int authentificationReussie = 0;

    do {
        printf("Identifiant : ");
        scanf("%s", identifiantDeCo);
        printf("Mot de passe : ");
        scanf("%s", MDPDeCo);

        if (strcmp(identifiantDeCo, joueur.identifiant) != 0 && strcmp(MDPDeCo, joueur.MDP) != 0) {
            printf("Identifiant ou mot de passe incorrect\n");
        } else {
          authentificationReussie=1;
        }
    } while (!authentificationReussie);

    return authentificationReussie;
}

// Fonction pour gérer le mot de passe
struct profil motDePasse(void) {
    struct profil joueur = {"", "", ""};
    printf("Choisir votre identifiant : ");
    scanf("%s", joueur.identifiant);
    printf("Choisir votre mot de passe : ");
    scanf("%s", joueur.MDP);
    Menu();
    return joueur;

}

// Fonction pour charger une partie
void chargerPartie(void) {
    // TODO: Implémenter la fonction pour charger une partie
}

// Fonction pour afficher les scores
void scores(void) {
    // TODO: Implémenter la fonction pour afficher les scores
}