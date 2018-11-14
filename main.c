#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

int main(int argc ,char** argv){
  /* argc est le nombre de mot de la ligne de commande
     argv est un tableau de chaines de caracteres:
     une chaine par mot de la ligne de commande  */

  int i;
  char *nomfic;
  Donnees D;
  initialise(&D);

  if(argc !=2){
    printf("Erreur format: %s  <Nom_du_Fichier.txt> ",argv[0]);
    return 1;
  }

  /* Nom du fichier */
  nomfic=strdup(argv[1]);

  /* Lecture du fichier externe, contenant quantites, nombre de bocaux et tableau de pots
 (ici fic1) */
  lecture_fic(nomfic, &D);

  /* Test du bon fonctionnement entrées */
  printf("Il y a %d grammes de confiture et %d pots de différentes tailles.\n\n", D.L->quantite_conf, D.L->nb_bocaux);
 
  printf("Les tailles des pots de confiture sont les suivantes :\n");
 
  for(i=0; i<D.L->nb_bocaux; i++){
    printf("valeur du pot %d : %d\n", i, D.L->tab[i]);
  }


  printf("\n=========================\n");
  printf("1/ Algorithme exhaustif\n");
  printf("=========================\n");
  printf("Nombre minimum de bocaux necessaires pour %d g de confiture: %d \n",D.L->quantite_conf, recherche_exhaustive(D.L->nb_bocaux, D.L->tab, D.L->quantite_conf));
  
  
 
}

