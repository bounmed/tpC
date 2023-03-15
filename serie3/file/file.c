#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int est_vide(file f)
{
    return (f == NULL);
}
file file_vide()
{
    return NULL;
}
void afficher(file f)
{
    printf("\n=====affichage de la file");
    file iter = f;
    while (iter != NULL)
    {
        printf("\nInduvidu: %D, Occurance:%d", iter->individu, iter->occurance);
        iter = iter->suivant;
    }
}
file enfiler(file f, int individu)
{
    printf("\nEnfiler %d", individu);
    Cellule *cell = (Cellule *)malloc(sizeof(Cellule));
    cell->individu = individu;
    cell->occurance = 1;
    cell->suivant = NULL;
    file iter = f;
    if (f == NULL)
        return cell;
    while (iter->suivant != NULL)
    {
        if (iter->individu == individu)
        {
            iter->occurance++;
            return f;
        }
        iter = iter->suivant;
    }
    if (iter->individu == individu)
    {
        iter->occurance++;
        return f;
    }
    iter->suivant = cell;
    return f;
}

file defiler(file f)
{
    if (f == NULL)
    {
        printf("file vide");
        return NULL;
    }
    if (f->occurance > 1)
    {
        f->occurance--;
        return f;
    }
    else
    {
        return f->suivant;
    }
}
