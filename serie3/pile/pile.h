#ifndef _PILE_CHAINEE
#define _PILE_CHAINEE

// Définition du type Pile (implémentée par pointeurs)
typedef char Element;
typedef struct cellule
{
    Element valeur;
    struct cellule *suivant;
} Cellule;
typedef Cellule *Pile;

// Déclaration des fonctions gérant la pile
Pile pile_vide();
int est_vide(Pile p);
Element sommet(Pile p);
Pile empiler(Pile p, Element e);
Pile depiler(Pile p);
Pile permuter(Pile p);
int expression_correct(char *exp);
#endif