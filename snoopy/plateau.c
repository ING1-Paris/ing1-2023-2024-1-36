//
// Created by thoma on 08/11/2023.
//
#include <stdio.h>

void saisirTab(int lignes, int colonnes,char matrice[lignes][colonnes]) {

    // Créer la matrice et remplir chaque élément avec un espace
    int i, j;

    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            matrice[i][j] = ' ';
        }
    }

    // Remplissage du rectangle avec des contours visibles
    int hauteurRectangle1 = 10;
    int largeurRectangle1 = 20;
    int ligneDebut1= 0;
    int colonneDebut1 = 0;

    for (int i = ligneDebut1; i < ligneDebut1 + hauteurRectangle1; i++) {
        for (int j = colonneDebut1; j < colonneDebut1 + largeurRectangle1; j++) {
            if (i == ligneDebut1 || i == ligneDebut1 + hauteurRectangle1 - 1 || j == colonneDebut1 || j == colonneDebut1 + largeurRectangle1 - 1) {
                matrice[i][j] = 47;  // Remplit uniquement les bords du rectangle
            }
        }
    }
    // Afficher la matrice
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            printf("%c", matrice[i][j]);
        }
        printf("\n");  // Passer à la ligne suivante
    }
}