#ifndef __Liste
#define __Liste
typedef struct cellule
{
    int element;
    struct cellule *suivant; // adresse cellule suivante
} Cellule;

typedef Cellule *Place; // Adresse cellule optionnel vous pouvz utiliser (Cellule *) ou (Liste)
typedef Cellule *Liste; // Un pointeur cellule

Liste liste_vide();
int longueur(Liste l);
Liste inserer(Liste l, int i, int e);
Place acces(Liste l, int k);
int contenu(Liste l, Place p);
Place succ(Liste l, Place p);
int keme(Liste l, int k);
Liste supprimer(Liste l, int i);
void afficher(Liste l);
Liste purger(Liste l);
Liste inverse(Liste l);
#endif
