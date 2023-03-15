#include <stdio.h>
#include "polynome.h"
#include <stdlib.h>

/*
//Pour Compiler le programme C sur la ligne de commande
gcc polynome.c main.c -o polynome -Wall
*/
int main(int argc, char *argv[])
{
    Polycreux p = Polycreux_vide();
    p = inserer(p, 1, 1);
    p = inserer(p, 2, 2);
    p = inserer(p, 3, 3);
    p = inserer(p, 4, 4);
    affichage_croissant(p);
    affichage_decroissant(p);
    p = supprimer(p, 2);
    affichage_croissant(p);
    affichage_decroissant(p);
    return 0;
}
