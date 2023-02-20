#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"

//gcc vecteur.c main.c -o program -Wall
int main()
{
  int t, p, val;

  Vecteur v;
  printf("donner la taille: \n");
  scanf("%d",&t);
  v= vect(t);
  v=lire_vect(v);
  afficher_vecteur(v);//

  return 0;
}
