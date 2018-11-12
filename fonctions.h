#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>

typedef struct data{
  int quantite_conf;
  int nb_bocaux;
  int *tab;
  struct data *suiv;
} s_data;

typedef struct{
  s_data *L; 
}Donnees;


/*************************
Fonctions 
*************************/
void initialise(Donnees *d);

void GetChaine(FILE *f,int taille_max,char *s);

void lecture_fic(char *nomfic, Donnees *D);
