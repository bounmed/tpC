#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"

/*
//pour Compiler le programme C sur la ligne de commande
gcc vecteur.c main.c -o vecteur -Wall
*/
int main()
{
    int t, p, val;

    Vecteur v;
    printf("Donner la taille: \n");
    scanf("%d", &t);
    v = vect(t);
    v = lire_vect(v);
    afficher_vecteur(v); //

    printf("Donner la valeur: \n");
    scanf("%d", &val);
    printf("Donner la position: \n");
    scanf("%d", &p);
    v = changer_ieme(v, p, val);
    afficher_vecteur(v);
    printf("ieme: %d\n", ieme(v, p));
    printf("taile : %d\n", taille(v)); // retourne la taille
    printf("sum : %d\n", sum(v));
    printf("max : %d\n", max(v));

    // Attendre avant de fermer le programme
    char ch;
    ch = getchar(); // clear the input
    printf("Appuyer sur la touche pour quitter le programme %c", ch);
    scanf("%c", &ch);
    return 0;
}