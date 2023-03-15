#ifndef __polynome_h
#define __polynome_h

typedef struct Monome
{
    int deg;
    float coeff;
    struct Monome *suivant;
    struct Monome *precedent;
} Monome;

typedef Monome *Place;
typedef Monome *Polycreux;

Polycreux Polycreux_vide();
int est_vide(Polycreux p);
Polycreux inserer(Polycreux l, int deg, float c);
Polycreux supprimer(Polycreux l, int deg);
void affichage_croissant(Polycreux l);
void affichage_decroissant(Polycreux l);

Place exist(Polycreux l, int d);

#endif