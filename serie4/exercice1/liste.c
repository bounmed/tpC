#include <stdlib.h>
#include <stdio.h>
#include "liste.h"
// Liste vide
Liste liste_vide()
{
    return NULL;
}

int longueur(Liste l)
{
    int taille = 0;
    Liste p = l;
    while (p != NULL)
    {
        taille++;
        p = p->suivant;
    }
    return taille;
}
int longueur2(Liste l)
{
    int taille = 0;
    if (l == NULL)
    {
        return 0;
    }
    else
    {
        Liste p = l;
        while (p != NULL)
        {
            taille++;
            p = p->suivant;
        }
        printf("taille %d", taille);
    }
    return taille;
}

Place succ(Liste l, Place p)
{
    if (p->suivant == NULL)
    {
        printf("Erreur : suivant derni�re place \n");
        exit(-1);
    }
    return p->suivant;
}

Place acces(Liste l, int k)
{
    int i;
    Place p;
    if (k <= 0)
    {
        printf("\n k <= 0");
        return l;
    }
    else
    {
        int taille = longueur(l);
        p = l;
        for (i = 0; i < k && i < taille; i++)
            p = p->suivant;
        printf("\n found it %d", p->element);
        return p;
    }
}

int contenu(Liste l, Place p)
{
    if (longueur(l) == 0)
    {
        printf("Erreur : liste vide \n");
        exit(-1);
    }
    return p->element;
}
int keme(Liste l, int k)
{
    if (k < 0 || k >= longueur(l))
    {
        printf("Erreur : rang invalide \n");
        exit(-1);
    }
    Place position = acces(l, k);
    // return position->element;
    return contenu(l, position);
}

Liste inserer(Liste l, int i, int e)
{
    if (i < 0 || i > longueur(l))
    {
        printf("Erreur : rang non valide \n");
        // exit(-1);
        return l;
    }
    Liste pc = (Liste)malloc(sizeof(Cellule));
    // Place pc = (Place)malloc(sizeof(Cellule));
    // Cellule * pc = (Cellule *)malloc(sizeof(Cellule));
    pc->element = e;
    if (i == 0)
    {
        pc->suivant = l;
        l = pc;
    }
    else
    {
        int j;
        Liste place = l;
        for (j = 0; j < i - 1; j++)
            place = place->suivant;
        pc->suivant = place->suivant;
        place->suivant = pc;
    }
    return l;
}

Liste supprimer(Liste l, int i)
{
    Liste p;
    if (i < 0 || i >= longueur(l))
    {
        printf("Erreur : rang invalide \n");
        exit(-1);
    }
    if (i == 0)
    {
        p = l;
        l = l->suivant;
    }
    else
    {
        Place q;
        q = acces(l, i - 1);
        // p = succ(l, q);
        p = q->suivant;
        q->suivant = p->suivant;
    }
    free(p);
    return p;
}

void afficher(Liste l)
{
    if (longueur(l) == 0)
    {
        printf("liste vide \n");
    }
    else
    {
        printf("\n Votre liste est : \n");
        Liste p = l;
        while (p != NULL)
        {
            printf("%d -> ", p->element);
            p = p->suivant;
        }
        printf(" Fin");
    }
}

Liste inverse(Liste l)
{
    Liste c = l, p = NULL, s;
    while (c != NULL)
    {
        // Garder l'adresse de la cellule suivante
        s = c->suivant;
        // Redirige le pointeur suivant sur la pr�c�dente
        c->suivant = p;
        // Garde la cellule courante comme pr�c�dente
        p = c;
        // Passe � la suivante.
        c = s;
    }
    return p;
}

Liste purger(Liste l)
{
    Liste p = l;
    while (p != NULL)
    {
        l = p;
        p = p->suivant;
        free(l);
    }
    return p;
}
