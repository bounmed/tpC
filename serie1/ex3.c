#include <stdio.h>
#include <stdlib.h>

int puissance(int a, int i) {
  if(i==0)
    return 1;
  else
    return (a*puissance(a,i-1));
}
int sommePuissamce(int a, int n) {
     if(n==0)
        return 1;
     else
        return (puissance(a, n) + sommePuissamce(a, n-1));
}
void affiche_rec(int tab[], int taille) {
	if (taille == 1)
		printf("tab[0]=%d\n", tab[0]);
	else {
        affiche_rec(tab, taille - 1);
		printf("tab[%d]=%d\n", taille-1, tab[taille - 1]);
    }
}

int main () {
    printf("5 puissance 3 egale a : %d", puissance(5, 3));
    printf("\n");
    printf("Some de 0 a n de a puissance i egale a : %d", sommePuissamce(5, 3));
    printf("\n");
    int tab[5] = {1, 5, 25, 125, 625};
    affiche_rec(tab, 5);
}
