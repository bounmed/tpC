#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
// #include <conio.h>
Arbre_Rech arbre_vide()
{
    return NULL;
}
int Maximum(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
Element contenu(Noeud n)
{
    return n.val;
}
Arbre_Rech cons(Pnoeud r, Arbre_Rech G, Arbre_Rech D)
{
    r->fg = G;
    r->fd = D;
    return r;
}
Noeud racine(Arbre_Rech A)
{
    return (*A);
}
Arbre_Rech gauche(Arbre_Rech A)
{
    return A->fg;
}
Arbre_Rech droite(Arbre_Rech A)
{
    return A->fd;
}

Arbre_Rech insertion(Arbre_Rech A, Element e)
{
    if (A == NULL)
    {
        Pnoeud r = nouveau_noeud(e);
        return cons(r, arbre_vide(), arbre_vide());
    }
    else if (e > contenu(racine(A)))
        return cons(A, gauche(A), insertion(droite(A), e));
    else
        return cons(A, insertion(gauche(A), e), droite(A));
}

Pnoeud nouveau_noeud(Element e)
{
    Pnoeud p = (Pnoeud)malloc(sizeof(Noeud));
    p->val = e;
    p->fg = NULL;
    p->fd = NULL;
    return p;
}

// affichage du pere puis du fils gauche puis du fils droit
void affich_pre(Arbre_Rech A)
{
    if (A == NULL)
        return;
    printf("%d ", A->val);
    affich_pre(A->fg);
    affich_pre(A->fd);
}

// affichage du fils gauche puis du pere puis du fils droit
void affich_inf(Arbre_Rech A)
{
    if (A == NULL)
        return;
    affich_inf(A->fg);
    printf("%d ", A->val);
    affich_inf(A->fd);
}

// affichage du fils gauche puis du fils droit puis du pere
void affich_post(Arbre_Rech A)
{
    if (A == NULL)
        return;
    affich_post(A->fg);
    affich_post(A->fd);
    printf("%d ", A->val);
}