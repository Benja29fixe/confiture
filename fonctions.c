#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "fonctions.h"

/***********************************************
Initialise l'entrée 
***********************************************/
void initialise(Donnees *d){
  d->L=NULL;
}

/* 
SAUT DES ESPACES LORS DE LA LECTURE DANS UN FICHIER POINTE PAR f 
*/

void Skip(FILE *f) {

  char c ;
  
  while (isspace(c=getc(f))) ;
  ungetc(c,f) ;

}

/***********************************************
Lecture de chaine de caracteres jusqu'a un espace, la fin de la ligne ou la fin de fichier
***********************************************/
void GetChaine(FILE *f,int taille_max,char *s)
{
  char c ;
  int i;

  Skip(f) ;
  i=0;
  c = getc(f) ;
  while (!(isspace(c))&&(c!=EOF)&&(c!='\n')&&(i<taille_max-1)){
    s[i]=c;
    c = getc(f) ;    
    i++;
  }
  s[i]='\0';
  ungetc(c,f) ;
}


/***********************************************
Lit entrees du fichier nomfic et stocke les
informations dans la bibliotheque B
***********************************************/
void lecture_fic(char *nomfic, Donnees *D)
{
  FILE *f=fopen(nomfic,"r");

  if(f==NULL){
    printf("\nErreur lors de l'ouverture du fichier. \n");
    return;
  }

  int i=0;
  char s[100];
  s_data *element;


  
  element=(s_data*)malloc(sizeof(s_data));
    
  GetChaine(f, 100, s);
  element->quantite_conf=atoi(s);
    
  GetChaine(f, 100, s);
  element->nb_bocaux=atoi(s);

  element->tab=(int*)malloc(element->nb_bocaux*sizeof(int));
  for(i=0; i<element->nb_bocaux; i++){
    GetChaine(f, 100, s);
    element->tab[i]=atoi(s);
  }

 element->suiv=D->L;
    D->L=element;

  fclose(f);
}
