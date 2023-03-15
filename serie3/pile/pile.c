#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

Pile pile_vide(void)
{
    return NULL;
}
int est_vide(Pile p)
{
    return (p == NULL);
}
Element sommet(Pile p)
{
    /* pré-condition: pile non vide ! */
    if (est_vide(p))
    {
        printf("Erreur: pile vide !\n");
        exit(-1);
    }
    return p->valeur;
}
Pile empiler(Pile p, Element e)
{
    Cellule *pc;
    pc = (Cellule *)malloc(sizeof(Cellule));
    pc->valeur = e;
    pc->suivant = p;
    return pc;
}
Pile depiler(Pile p)
{
    /* pré-condition: pile non vide ! */
    Cellule *pc = p;
    if (est_vide(p))
    {
        printf("Erreur: pile vide !\n");
        exit(-1);
    }
    p = p->suivant;
    free(pc);
    return p;
}

Pile permuter(Pile p)
{
    if (est_vide(p))
    {
        printf("erreur pile vide\n");
        exit(-1);
    }
    // recupere le sommet de p
    char va = sommet(p);
    p = depiler(p);
    if (est_vide(p))
    {
        p = empiler(p, va);
        return p;
    }
    // creer pile q
    Pile q = pile_vide();
    while (!est_vide(p))
    {
        q = empiler(q, sommet(p));
        p = depiler(p);
    }
    p = empiler(p, va);

    char vb = sommet(q);
    q = depiler(q);
    // p = pile_vide ();
    while (!est_vide(q))
    {
        p = empiler(p, sommet(q));
        q = depiler(q);
    }
    p = empiler(p, vb);
    return p;
}

int expression_correct(char *exp)
{
    char *p = exp;
    Pile q = pile_vide();
    while (*p != '\0')
    {
        if (*p == '(')
            q = empiler(q, '(');
        else if (*p == ')')
        {

            q = depiler(q);
        }
        p++;
    }
    return (est_vide(q));
}
