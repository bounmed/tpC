#define __FIle_H
typedef struct cellule
{
    int individu;
    int occurance;
    struct cellule *suivant;
} Cellule;
typedef Cellule *file;

int est_vide(file f);
file file_vide();
file defiler(file f);
file enfiler(file f, int individu);
void afficher(file f);
