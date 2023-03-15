#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

/*
//pour Compiler le programme C sur la ligne de commande
gcc pile.c main.c -o pile -Wall
*/

int main()
{
    Pile p = pile_vide();
    p = empiler(p, 'a');
    p = empiler(p, 'b');
    p = empiler(p, 'c');
    p = empiler(p, 'd');
    printf("%c au sommet après empilement de a, b, c et d\n", sommet(p));
    p = depiler(p);
    p = depiler(p);
    printf("%c au sommet après dépilement de d et c\n", sommet(p));
    Pile q = pile_vide();
    q = permuter(p);
    printf("%c au sommet après permutation\n", sommet(q));

    char expr1[] = "((a+b)";
    if (expression_correct(expr1))
        printf("%s est bien parenthésée\n", expr1);
    else
        printf("%s est mal parenthésée\n", expr1);
    char expr2[] = "((a+b) * (c-d))";
    if (expression_correct(expr2))
        printf("%s est bien parenthésée\n", expr2);
    else
        printf("%s est mal parenthésée\n", expr2);

    // Attendre avant de fermer le programme
    char ch;
    ch = getchar(); // clear the input
    printf("Appuyer sur la touche pour quitter le programme %c", ch);
    scanf("%c", &ch);
    return 0;
}