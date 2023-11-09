#include <stdio.h>
#define ligne 10
#define colonne 20

char matrice[ligne][colonne];
int x = 2 , y = 2;
char direction;
char noopy = 'S';
int j
void affichage()
{
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("%c", matrice[i][j]);
        }
        printf("\n");  // Passer à la ligne suivante
    }
}
int main() {


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
                matrice[i][j] = 47;  // Remplit uniquement les bords du rectangle
            }
        }
        matrice[i][j] = noopy;
    }
    affichage();

printf("quelle est la direction desiree ?\n");
scanf("%d", direction);
    switch (direction) {
        case 'Q':
            x = (x - 1);
            affichage();
            break;
        case 'D':
            x = (x + 1);
            affichage();
            break;
        case 'S':
            y = (y - 1);
            affichage();
            break;
        case 'Z':
            y = (y + 1);
            affichage();
            break;
    }
    return 0;
}

