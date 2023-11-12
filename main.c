#include <stdio.h>
#include <string.h>
#include <unistd.h>

const int ligne = 10;
const int colonne = 20;
const int TEMPS_JEU = 120;

struct profil {
    char identifiant[100];
    char MDP[100];
    char pseudo[100];
};

// Function Prototypes
int INFOPARTIE(struct profil);
void reglesDuJeu(void);
void nouveauJeu(struct profil);
void chargerPartie(void);
struct profil motDePasse(void);
int scores(void);
int connexion(struct profil);
int Menu(void);
void affichage(char matrice[ligne][colonne]);
int JEU(char matrice[ligne][colonne]);

int main() {
    // Appel de la fonction Menu pour démarrer le programme
    Menu();

    return 0;
}

// Fonction pour afficher le menu et gérer les choix
int Menu(void) {
    int choix;
    int retour;
    char matrice[ligne][colonne];
    struct profil joueur;
    printf("***********************************************\n");
    printf("****************** SNOOPY GAME ****************\n");
    printf("***********************************************\n");
    printf("1. REGLES DU JEU\n");
    printf("2. NOUVEAU JEU\n");
    printf("3. CHARGER UNE PARTIE\n");
    printf("4. CONFIGURATION IDENTIFIANT ET MOT DE PASSE\n");
    printf("5. SCORES\n");
    printf("6. QUITTER\n");
    printf("***********************************************\n");
    printf("***********************************************\n");

    scanf("%d", &choix);

    switch (choix) {
        case 1:
            reglesDuJeu();
            printf("retour : 1");
            scanf("%d", &retour);
            if (retour == 1) {
                Menu();
            }
            break;
        case 2:
            nouveauJeu(joueur);
            printf("NIVEAU 1\n");
            printf("%s", joueur.pseudo);
            affichage(matrice);
            JEU(matrice);
            break;
        case 3:
            chargerPartie();
            break;
        case 4:
            joueur = motDePasse();
            Menu();
            break;
        case 5:
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
        printf("authentification réussie\n");
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

        if (strcmp(identifiantDeCo, joueur.identifiant) == 0 && strcmp(MDPDeCo, joueur.MDP) == 0) {
            authentificationReussie = 0;
        } else {
            authentificationReussie = 1;
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
    printf("Choisir un pseudo : ");
    scanf("%s", joueur.pseudo);
    return joueur;
}

// Fonction pour charger une partie
void chargerPartie(void) {
    // TODO: Implémenter la fonction pour charger une partie
}

// Fonction pour afficher les scores
int scores(void) {
    // TODO: Implementer la fonction pour afficher les scores
    return 0;
}

int INFOPARTIE(struct profil joueur) {
    int Tempsfin;
    int A;
    int score;
    system("cls");

    for (A = 120; A > 0; A = A - 1) {
        system("cls");
        printf("TIMER : %d", A);
        sleep(1);
        // cwait;  // Commented out since it's not a standard function
    }
    Tempsfin = A;
    score = Tempsfin * 100;
    printf("SCORE : %d", Tempsfin);
    return 0;
}

void affichage(char matrice[ligne][colonne]) {
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("%c", matrice[i][j]);
        }
        printf("\n");  // Passer à la ligne suivante
    }
}

int JEU(char matrice[ligne][colonne]) {
    int x = 5, y = 10, X1 = 1, Y1 = 1, X2 = 1, Y2 = 18, X3 = 8, Y3 = 18, X4 = 8, Y4 = 1, X5 = 4, Y5 = 12;
    char noopy = 'S';
    char oiseau1 = 'O', oiseau2 = 'O', oiseau3 = 'O', oiseau4 = 'O', blocpiege = 'P', blocfixe = 'F';

    // Créer la matrice et remplir chaque élément avec un espace
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colonne; j++) {
            matrice[i][j] = ' ';
        }
    }
    int hauteurRectangle = 10;
    int largeurRectangle = 20;
    int ligneDebut = 0;
    int colonneDebut = 0;

    for (int i = ligneDebut; i < ligneDebut + hauteurRectangle; i++) {
        for (int j = colonneDebut; j < colonneDebut + largeurRectangle; j++) {
            if (i == ligneDebut || i == ligneDebut + hauteurRectangle - 1 || j == colonneDebut ||
                j == colonneDebut + largeurRectangle - 1) {
                matrice[i][j] = 44;  // Remplit uniquement les bords du rectangle
            }
        }
    }

    matrice[x][y] = noopy;
    matrice[X1][Y1] = oiseau1;
    matrice[X2][Y2] = oiseau2;
    matrice[X3][Y3] = oiseau3;
    matrice[X4][Y4] = oiseau4;
    matrice[X5][Y5] = blocpiege;
    affichage(matrice);
    int touche;
    do {
        printf("Quel est votre direction ?\n"
               "z:Haut q:Gauche s:Bas d:Droite e:Fin\n");
        do {
            scanf(" %c", &touche);
        } while (!(touche == 'q' || touche == 'z' || touche == 'd' || touche == 's' || touche == 'e'));
        system("cls");
        //séléction de la direction
        switch (touche) {
            //Mouv HAUT
            case 'q': {
                //vérifiaction de la possibilité d'execution du mouvement en cas de bordure ou de bloc fixe
                if (matrice[x][y - 1] == blocfixe || matrice[x][y - 1] == matrice[ligneDebut][colonneDebut]) {
                    printf("Le mouvement n'est pas possible\n");
                    affichage(matrice);
                }
                    //déplacement permis si aucune autre condition n'est validé
                else {
                    printf("le mouvement est vers le haut\n");
                    //effacement de la position antèrieur
                    matrice[x][y] = ' ';
                    //déplacement vers le haut
                    matrice[x][y - 1] = noopy;
                    //incrémentation pour la valeur initale suivante
                    y--;
                    //affichage de la modification
                    affichage(matrice);
                }
                break;
            }
                //Mouv GAUCHE
            case 'z': {
                //vérifiaction de la possibilité d'execution du mouvement
                if (matrice[x - 1][y] == blocfixe || matrice[x - 1][y] == matrice[ligneDebut][colonneDebut]) {
                    printf("Le mouvement n'est pas possible\n");
                    affichage(matrice);
                } else {
                    printf("le mouvement est vers la gauche\n");
                    //effacement de la position antèrieur
                    matrice[x][y] = ' ';
                    //déplacement vers la gauche
                    matrice[x - 1][y] = noopy;
                    //incrémentation pour la valeur initale suivante
                    x--;
                    //affichage de la modification
                    affichage(matrice);
                }
                break;
            }
                //Mouv BAS
            case 'd': {
                //vérifiaction de la possibilité d'execution du mouvement
                if (matrice[x][y + 1] == blocfixe || matrice[x][y + 1] == matrice[ligneDebut][colonneDebut]) {
                    printf("Le mouvement n'est pas possible\n");
                    affichage(matrice);
                } else {
                    printf("le mouvement est vers le bas\n");
                    //effacement de la position antèrieur
                    matrice[x][y] = ' ';
                    //déplacement vers le bas
                    matrice[x][y + 1] = noopy;
                    //incrémentation pour la valeur initale suivante
                    y++;
                    //affichage de la modification
                    affichage(matrice);
                }
                break;
            }
                //Mouv DROITE
            case 's': {
                //vérifiaction de la possibilité d'execution du mouvement
                if (matrice[x + 1][y] == blocfixe || matrice[x + 1][y] == matrice[ligneDebut][colonneDebut]) {
                    printf("Le mouvement n'est pas possible\n");
                    affichage(matrice);
                }
                else
                {
                    printf("le mouvement est vers la droite\n");
                    //effacement de la position antèrieur
                    matrice[x][y] = ' ';
                    //déplacement vers le haut
                    matrice[x+1][y] = noopy;
                    //incrémentation pour la valeur initale suivante
                    x++;
                    //affichage de la modification
                    affichage(matrice);
                }
                break;
            }
        }
    }while(touche != 'e');
    return 0;
}