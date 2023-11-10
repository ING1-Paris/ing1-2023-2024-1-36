#include <stdio.h>
#include <string.h>

struct profil {
    char identifiant[100];
    char MDP[100];
    char pseudo[100];
};

// La fonction Configuration doit retourner un struct profil
struct profil Configuration(void) {
    struct profil profil1;
    printf("Choisir votre identifiant : ");
    scanf("%s", profil1.identifiant);
    printf("Choisir votre mot de passe : ");
    scanf("%s", profil1.MDP);

    // Retourne la structure profil1
    return profil1;
}

// La fonction connexion doit prendre un argument de type struct profil
int connexion(struct profil profil) {
    char identifiantDeCo[100];
    char MDPDeCo[100];
    printf("Identifiant : ");
    scanf("%s", identifiantDeCo);
    printf("Mot de passe : ");
    scanf("%s", MDPDeCo);

    if (strcmp(identifiantDeCo, profil.identifiant) == 0 && strcmp(MDPDeCo, profil.MDP) == 0) {
        printf("Authentification réussie\n");
    } else {
        printf("Identifiant ou mot de passe incorrect\n");
    }
}

int main() {
    struct profil profil1;
    profil1 = Configuration(); // Utilise la fonction Configuration pour obtenir les informations de profil
    connexion(profil1);

    return 0;
}

