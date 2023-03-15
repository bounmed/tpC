
#define __VECTEUR_H
typedef struct vecteur
{
        int taille;
        int *elements;
} Vecteur;

Vecteur vect(int taille); //
Vecteur changer_ieme(Vecteur v, int position, int valeur);
int ieme(Vecteur v, int position);
int taille(Vecteur v);            // retourne la taille
Vecteur lire_vect(Vecteur v);     // pour la saisie de vecteur qui est d�j� cr�er par vect
void afficher_vecteur(Vecteur v); //
int sum(Vecteur v);
int max(Vecteur v);
