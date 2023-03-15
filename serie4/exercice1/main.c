#include <stdio.h>
#include "liste.h"
#include <stdlib.h>
/*
//pour Compiler le programme C sur la ligne de commande
gcc liste.c main.c -o liste -Wall
*/
int main(int argc, char *argv[])
{
    Liste l = liste_vide();
    int choix;
    int e, i;
    l = inserer(l, 0, 1);
    l = inserer(l, 1, 2);
    l = inserer(l, 2, 3);
    l = inserer(l, 3, 4);
    afficher(l);

    do
    {
        printf("\n-------------------- Menu -------------------------\n\
        1 : inserer un entier dans la liste\n\
        2 : supprimer un entier dans la liste\n\
        3 : taille de la liste\n\
        4 : consulter un elemnt de la liste\n\
        5 : inverser la liste\n\
        6 : purger la liste\n\
        7 : afficher le contenu de la liste\n\
        0 : Quitter\n\n\
        Donnez le choix :  ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
        {
            printf("\n ===> Donnez le rang et l'element a inserer : ");
            getchar();
            scanf("%d%d", &i, &e);
            l = inserer(l, i, e);
            printf("\n ------------ OK ----------- \n");
            break;
        }

        case 2:
        {
            printf("\n ===> Donnez le rang d'element a supprimer : ");
            getchar();
            scanf("%d", &i);
            l = supprimer(l, i);
            printf("\n ------------ OK ----------- \n");
            break;
        }
        case 3:
        {
            printf("\n La taille de la liste est: %d", longueur(l));
            break;
        }
        case 4:
        {
            printf("\n ===> Donnez le rang d'element a consulter : ");
            getchar();
            scanf("%d", &i);
            printf("\n :::::::> L'elemnt est  : %d", keme(l, i));
            break;
        }
        case 5:
        {
            l = inverse(l);
            printf("\n ------------ OK ----------- \n");
            break;
        }
        case 6:
        {
            l = purger(l);
            printf("\n ------------ OK ----------- \n");
            break;
        }
        case 7:
        {
            afficher(l);
            break;
        }
        case 0:
        {
            printf("\n quitter \n\n");
            break;
        }
        default:
        {
            printf("entrer valeur valide");
        }
        }
    } while (choix != 0);
    return 0;
}
