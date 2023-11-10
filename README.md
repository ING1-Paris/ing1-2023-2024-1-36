# ing1-2023-2024-1-36
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define ligne 10
#define colonne 20



void gotoligcol( int x,int y )
{
// ressources
    COORD mycoord;
    mycoord.X = x;
    mycoord.Y = y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
void affichage(char matrice[ligne][colonne])
{
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("%c", matrice[i][j]);
        }
        printf("\n");  // Passer à la ligne suivante
    }
}
int main() {
    char matrice[ligne][colonne];
    int x = 5 , y = 10, X1=1, Y1=1, X2=1, Y2=18, X3=8, Y3=18, X4=8, Y4=1;
    char direction;
    char noopy = 'S';
    char oiseau1 = 'O',oiseau2 = 'O' ,oiseau3 = 'O', oiseau4 = 'O';
    char car;

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
                matrice[i][j] = 35;  // Remplit uniquement les bords du rectangle
            }
        }
    }

    matrice[x][y] = noopy;
    matrice[X1][Y1] = oiseau1;
    matrice[X2][Y2] = oiseau2;
    matrice[X3][Y3] = oiseau3;
    matrice[X4][Y4] = oiseau4;
    affichage(matrice);

    while (1) {
        int touche;
        touche = getch();
        switch (touche) {
            case 'd' :
                gotoligcol(x, y);
                printf(" ");
                matrice[x][y]=' ';
                x++;
                gotoligcol(x, y);
                printf("%c", noopy);
                matrice[x][y]=noopy;
            case 'q' :
                gotoligcol(x, y);
                printf(" ");
                matrice[x][y]=' ';
                x--;
                gotoligcol(x, y);
                printf("%c", noopy);
                matrice[x][y]=noopy;
            case 'z' :
                gotoligcol(x, y);
                printf(" ");
                matrice[x][y]=' ';
                y--;
                gotoligcol(x, y);
                printf("%c", noopy);
                matrice[x][y]=noopy;
            case 's' :
                gotoligcol(x, y);
                printf(" ");
                matrice[x][y]=' ';
                y++;
                gotoligcol(x, y);
                printf("%c", noopy);
                matrice[x][y]=noopy;
        }
    }
}
