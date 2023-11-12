# ing1-2023-2024-1-36
#include <stdio.h>
#include <unistd.h>  
#define TABLEAU_LONGUEUR 20
#define TABLEAU_LARGEUR 10

    int main() {

        int ballX = TABLEAU_LONGUEUR / 1;
        int ballY = TABLEAU_LARGEUR / 1;

        int ballVelocityX = 1;
        int ballVelocityY = 1;

    while (1) {

        ballX += ballVelocityX;
        ballY += ballVelocityY;

        if (ballX < 0 || ballX >= TABLEAU_LONGUEUR)
        {
            ballVelocityX = -ballVelocityX;
        }
        if (ballY < 0 || ballY >= TABLEAU_LARGEUR)
        {
            ballVelocityY = -ballVelocityY;
        }

        for (int y = 0; y < TABLEAU_LARGEUR; ++y) {
            for (int x = 0; x < TABLEAU_LONGUEUR; ++x) {
                if (x == ballX && y == ballY) {
                    printf("O");  
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
        usleep(100000);

        printf("\033[H\033[J");
    }

    return 0;
}
