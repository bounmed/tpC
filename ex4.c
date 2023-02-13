#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int jour ;
    char mois [15];
    int annee;
} Date;
//dp->annee is the same as (*dp).annee.
void affichedate(Date *dp){
    printf("%d/%s/%d ",dp->jour, dp->mois,(*dp).annee) ;
}

void demandedate(Date *dp){
    //printf("Donnez le jour: ") ;
    scanf("Donnez le jour %d", &dp->jour) ;
    printf("donnez le mois: ") ;
    scanf("%s", dp->mois) ;
    printf("donnez l'annee: ") ;
    scanf("%d", &dp->annee) ;
}

int NumeroMois(char *nommois) {
    if  (strcmp(nommois, "Janvier")==0) return 1;
    if  (strcmp(nommois, "Février")==0) return 2;
    if  (strcmp(nommois, "Mars")==0) return 3;
    if  (strcmp(nommois, "Avril")==0) return 4;
    if  (strcmp(nommois, "Mai")==0) return 5;
    if  (strcmp(nommois, "Juin")==0) return 6;
    if  (strcmp(nommois, "Juillet")==0) return 7;
    if  (strcmp(nommois, "Aout")==0) return 8;
    if  (strcmp(nommois, "Septembre")==0) return 9;
    if  (strcmp(nommois, "Octobre")==0) return 10;
    if  (strcmp(nommois, "Novembre")==0) return 11;
    if  (strcmp(nommois, "Décembre")==0) return 12;
    return -1 ;
}

int Compare_dates(Date d1, Date d2) {

    return 0;
}


int main () {

    return 0;
}
