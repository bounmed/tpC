#define ARBRE_H

typedef int Element;
typedef struct noeud {
        Element val;
        struct noeud *fg;
        struct noeud *fd;
} Noeud;
typedef Noeud *Pnoeud;
typedef Noeud *Arbre_Rech;

Arbre_Rech arbre_vide();
Arbre_Rech insertion(Arbre_Rech A, Element e);
Pnoeud nouveau_noeud(Element e);
void affich_inf(Arbre_Rech A);
void affich_pre(Arbre_Rech A);
void affich_post(Arbre_Rech A);