#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int jour ;
    char mois [15];
    int annee;
} Date;

void affichedate(Date *dp){
    //dp->annee is the same as (*dp).annee.
    printf("%d/%s/%d ",dp->jour, dp->mois,(*dp).annee);
}

void demandedate(Date *dp){
    printf("Donnez la date: ") ;
    scanf("%d %s %d", &dp->jour, dp->mois, &dp->annee) ;
    /*//Ou recuperer la date element par element
    printf("Donnez le jour: ");
    scanf("%d", &dp->jour);
    printf("Donnez le mois: ");
    scanf("%s", dp->mois);
    printf("Donnez l'annee: ");
    scanf("%d", &dp->annee);
    */
}

int NumeroMois(char *nommois) {
    if  (strcmp(nommois, "Janvier")==0) return 1;
    if  (strcmp(nommois, "Fevrier")==0) return 2;
    if  (strcmp(nommois, "Mars")==0) return 3;
    if  (strcmp(nommois, "Avril")==0) return 4;
    if  (strcmp(nommois, "Mai")==0) return 5;
    if  (strcmp(nommois, "Juin")==0) return 6;
    if  (strcmp(nommois, "Juillet")==0) return 7;
    if  (strcmp(nommois, "Aout")==0) return 8;
    if  (strcmp(nommois, "Septembre")==0) return 9;
    if  (strcmp(nommois, "Octobre")==0) return 10;
    if  (strcmp(nommois, "Novembre")==0) return 11;
    if  (strcmp(nommois, "Decembre")==0) return 12;
    return -1 ;
}

int comparedate(Date d1, Date d2) {
    if (d1.annee < d2.annee)
        return -1 ;
    else if (d1.annee > d2.annee)
        return 1;
    else {
        if (NumeroMois (d1.mois)<NumeroMois (d2.mois))
            return -1;
        else if  (NumeroMois (d1.mois)> NumeroMois (d2.mois))
            return 1;
        else {
            if (d1.jour < d2.jour)
                return -1 ;
            else if (d1.jour>d2.jour)
                return 1 ;
            return 0;
        }
    }
}
/*//Example de test
Donnez la date: 5
Janvier
2023
Donnez la date: 10
Fevrier
2023
Donnez la date: 23
Janvier
2023
Donnez la date: 1
Mai
2023
Donnez la date: 20
Novembre
2023
5/Janvier/2023 10/Fevrier/2023 23/Janvier/2023 1/Mai/2023 20/Novembre/2023
 === comparer des dates ====
5/Janvier/2023  < 10/Fevrier/2023
10/Fevrier/2023  > 23/Janvier/2023 %
*/
int main () {
    int i, result;
    Date *dates = (Date *) malloc(5 * sizeof(Date)) ;


    for (i=0; i<5; i++)
        demandedate(dates+i);
    /*//Vous pouvez aussi utiliser &d[i]
    for (i=0; i<5; i++)
        demandedate(&d[i]);
    */
    for (i=0;i<5;i++)
        affichedate(dates+i);
    printf("\n === comparer des dates ====\n");

    //Comparer a date 0 avec la date 1
    result = comparedate(dates[0], dates[1]);
    if ( result< 0) {
        affichedate(&dates[0]);
        printf(" < ");
        affichedate(&dates[1]);
    } else if (result > 0){
        affichedate(&dates[0]);
        printf(" > ");
        affichedate(&dates[1]);
    } else {
        affichedate(&dates[0]);
        printf(" = ");
        affichedate(&dates[1]);
    }
    //Comparer a date 1 avec la date 2
    printf("\n");
    result = comparedate(dates[1], dates[2]);
    if ( result< 0) {
        affichedate(&dates[1]);
        printf(" < ");
        affichedate(&dates[2]);
    } else if (result > 0){
        affichedate(&dates[1]);
        printf(" > ");
        affichedate(&dates[2]);
    } else {
        affichedate(&dates[1]);
        printf(" = ");
        affichedate(&dates[2]);
    }
    return 0;
}
