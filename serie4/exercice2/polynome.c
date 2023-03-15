#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"

Polycreux Polycreux_vide()
{
    return NULL;
}

int est_vide(Polycreux p)
{
    return p == NULL;
}
void affichage_croissant(Polycreux l)
{
    printf("\n affichage croissant:");
    if (est_vide(l))
    {
        printf("polynome vide");
        exit(-1);
    }

    Place p = l;

    while (p->suivant)

        p = p->suivant;

    while (p)
    {
        printf(" %fx%d\t", p->coeff, p->deg);
        p = p->precedent;
    }
}

void affichage_decroissant(Polycreux l)
{
    printf("\n affichage decroissant:");
    if (est_vide(l))
    {
        printf("polynome vide");
        exit(-1);
    }

    Place p = l;

    while (p)
    {
        printf(" %fx%d\t", p->coeff, p->deg);
        p = p->suivant;
    }
}

Place exist(Polycreux l, int d)
{

    Place p = l;

    while (p)
    {
        if (p->deg == d)
            return p;
        p = p->suivant;
    }

    return p;
}

Polycreux inserer(Polycreux l, int deg, float c)
{
    Place p = exist(l, deg);

    if (p)
        p->coeff = p->coeff + c;

    else
    {
        Place pp;
        p = l;
        Place pm = (Place)malloc(sizeof(Monome));
        pm->deg = deg;
        pm->coeff = c;
        pm->suivant = NULL;
        pm->precedent = NULL;

        if (!l)
            l = pm;

        else if (deg > l->deg)
        {
            pm->suivant = l;
            l->precedent = pm;
            l = pm;
        }

        else
        {
            while (p->deg > deg && p)
            {
                pp = p;
                p = p->suivant;
            }

            if (!p)
            {
                pp->suivant = pm;
                pm->precedent = pp;
            }
            else
            {
                pp->suivant = pm;
                pm->precedent = pp;
                pm->suivant = p;
                p->precedent = pm;
            }
        }
    }

    return l;
}

Polycreux supprimer(Polycreux l, int deg)
{

    Place p = exist(l, deg);

    if (!p)
    {
        printf("Degré non existant ou polynome vide");
        exit(-1);
    }
    else if (p == l)
    {
        l = l->suivant;
        l->precedent = NULL;
    }

    else
    {
        Place pp = p->precedent;
        Place ps = p->suivant;
        pp->suivant = ps;
        ps->precedent = pp;
    }
    free(p);
    return l;
}