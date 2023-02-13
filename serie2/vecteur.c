#include<stdio.h>
#include <stdlib.h>
#include "vecteur.h"

Vecteur vect(int t)
{
     if(t<0) {
          printf("erreur de taille");
          exit(-1); //sortir du programme avec erreur
     }
     Vecteur v;
     v.taille=t;
     v.elements=(int *)malloc(t * sizeof(int));
     return v;
}
int taille(Vecteur v)
{
    return v.taille;
}
int ieme(Vecteur v,int i)
{
     if(i<0 || i > taille(v)) {
          printf("indice invalide");
          exit(-1);
     }
     return v.elements[i];
}
Vecteur changer_ieme(Vecteur v, int i, int val)
{
     if(i<0 || i>taille(v)) {
          printf("indice invalide");
          exit(-1);
     }
     v.elements[i] = val;
     return v;
}

Vecteur lire_vect(Vecteur v)
{
     int val,i;
     for(i=0; i<taille(v); i++) {
          printf("entrer valeur %d: ",i+1);
          scanf("%d",&val);
          v=changer_ieme(v,i,val);
     }
     return v;
}

void afficher_vecteur(Vecteur v)
{
     int i;
     printf("\n------Affichage Vecteur-------\n");
     for(i=0;i<taille(v);i++)
     {
       printf("element %d: %d\n", i+1, ieme(v,i));
     }
     printf("\n--------------------------\n");
}
