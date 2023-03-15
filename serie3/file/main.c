
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
/*
//pour Compiler le programme C sur la ligne de commande
gcc file.c main.c -o file -Wall
*/
int main() {
    file f = file_vide();
    f = enfiler(f, 1);
    f = enfiler(f, 2);
    f = enfiler(f, 2);
    f = enfiler(f, 3);
    f = enfiler(f, 4);
    afficher(f);
    printf("\nDefiler");
    f = defiler(f);
    afficher(f);
    printf("\nDefiler");
    f = defiler(f);
    afficher(f);
    printf("\nDefiler");
    f = defiler(f);
    afficher(f);
    printf("\nDefiler");
    f = defiler(f);
    afficher(f);
}