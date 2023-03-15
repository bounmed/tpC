#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int jour ;
    int mois ;
    int annee;
} date ;

typedef struct{
    int numero ;
    date dd ;
    date df;
} conge;

typedef struct{
    char nom[20];
    char prenom[20];
    int matricule;
    int nb_conges;
    date dr;
    conge *lc;
} employe;
/*example de test*/
/*
Donnez le nom:salmi
Donnez le prenom:ali
Donnez le matricule (entier):1
Donnez la date de recrutement:1
3
2010
Donnez le nom:alaoui
Donnez le prenom:kamal
Donnez le matricule (entier):2
Donnez la date de recrutement:1
1
2015
Donner l'indice de l'employe:0
Donner le numero de conge:1
Donnez la date de debut:1
5
2023
Donnez la date de fin:27
5
2023
Donner l'indice de l'employe:1
Donner le numero de conge:2
Donnez la date de debut:1
6
2023
Donnez la date de fin:30
6
2023

Nom et prenom: salmi ali
Matricule: 1
Date recrutement: 1/3/2010
Comnges:
		Conge no 1 de 1/5/2023 jusqu'a 27/5/2023

Nom et prenom: alaoui kamal
Matricule: 2
Date recrutement: 1/1/2015
Comnges:
		Conge no 2 de 1/6/2023 jusqu'a 30/6/2023
*/
int main () {
    int i, j;
    int nb_employes = 2, nb_conges =2;

    employe *tabemp=(employe*)malloc(nb_employes * sizeof(employe)) ;
    for (i = 0;i < nb_conges; i++)
        tabemp[i].lc = (conge*) malloc( nb_conges * sizeof(conge));

    for (i=0; i < nb_employes; i++)
    {
        printf("Donnez le nom:");
        scanf(" %s", tabemp[i].nom);
        printf("Donnez le prenom:");
        scanf(" %s", tabemp[i].prenom);
        printf("Donnez le matricule (entier):");
        scanf(" %d", &tabemp[i].matricule);
        printf("Donnez la date de recrutement:");
        scanf("%d %d %d", &tabemp[i].dr.jour, &tabemp[i].dr.mois, &tabemp[i].dr.annee);
        //initialisation du nombre de conges de l'employe
        tabemp[i].nb_conges = 0;
    }
    // Ajouter les conges pour un employee
    printf("====== Saisie des conges ======");
    for (j=0; j<nb_conges; j++)
    {
        int indice;
        do{
            printf("Donner l'indice de l'employe:");
            scanf("%d",&indice) ;
        } while(indice > nb_employes || indice < 0);

        int positionConge = tabemp[indice].nb_conges;

        printf("Donner le numero de conge:");
        scanf("%d",&tabemp[indice].lc[positionConge].numero);
        printf("Donnez la date de debut:");
        scanf("%d%d%d",&tabemp[indice].lc[positionConge].dd.jour, &tabemp[indice].lc[positionConge].dd.mois,&tabemp[indice].lc[positionConge].dd.annee);
        printf("Donnez la date de fin:");
        scanf("%d%d%d",&tabemp[indice].lc[positionConge].df.jour, &tabemp[indice].lc[positionConge].df.mois,&tabemp[indice].lc[positionConge].df.annee);
        // Incrementer le nombre de conge de l'employes
        tabemp[indice].nb_conges ++;
    }

    //Affichage des employes et leurs conges
    printf("====== Affichage des employes et leurs conges ======");
    for (i=0; i < nb_employes; i++) {
        printf("\nNom et prenom: %s %s\n", tabemp[i].nom,tabemp[i].prenom);
        printf("Matricule: %d\n", tabemp[i].matricule);
        printf("Date recrutement: %d/%d/%d\n", tabemp[i].dr.jour, tabemp[i].dr.mois, tabemp[i].dr.annee);
        printf("Comnges: \n\t\t");
        for (j=0; j <  tabemp[i].nb_conges; j++) {
            printf("Conge no %d de %d/%d/%d jusqu'a ", tabemp[i].lc[j].numero, tabemp[i].lc[j].dd.jour, tabemp[i].lc[j].dd.mois, tabemp[i].lc[j].dd.annee);
            printf("%d/%d/%d\n\t\t", tabemp[i].lc[j].df.jour, tabemp[i].lc[j].df.mois, tabemp[i].lc[j].df.annee);
        }
    }
}