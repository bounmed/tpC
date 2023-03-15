#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
#include "arbre.h"

/*
//Pour Compiler le programme C sur la ligne de commande
gcc arbre.c main.c -o arbre -Wall
*/
int main()
{
    printf("test \n");
    Arbre_Rech R = arbre_vide();
    R = insertion(R, 8);
    R = insertion(R, 3);
    R = insertion(R, 10);
    R = insertion(R, 1);
    R = insertion(R, 6);
    R = insertion(R, 14);
    R = insertion(R, 4);
    R = insertion(R, 7);
    R = insertion(R, 13);
    affich_inf(R);
    printf("\n");
    affich_pre(R);
    printf("\n");
    affich_post(R);
    printf("\n");
    /*system("PAUSE");*/
    return 0;
}
