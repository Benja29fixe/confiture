#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "fonctions.h"

/***********************************************
Initialise l'entrée 
***********************************************/
void initialise(Donnees *d){
  d->L=NULL;
}

/***********************************************
Saut des espaces lors de la lecture dans un fichier pointe par f 
***********************************************/
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
informations dans la base de donnees D
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

  tri_insertion(element->tab, element->nb_bocaux);

 element->suiv=D->L;
    D->L=element;

  fclose(f);
}

/***********************************************
Fonction Tri par Insertion 
***********************************************/
void tri_insertion(int *T, int n){

  int i, j;
  int z, k;

  for(i=1; i<n; i++){
    z=T[i];
    k=i-1;

    while(k>-1 && T[k]>z){
      T[k+1]=T[k];
      k=k-1;
    }

    T[k+1]=z;
  }
}

/***********************************************
Algorithme 1 : recherche exhaustive
***********************************************/
int recherche_exhaustive(int k, int *V, int s){

  int i, NbCont, x;

  if(s<0){
    return 100000;
  }

  else{
    if(s==0){
      return 0;
    }

    else{
      
      NbCont=s;

      for(i=0; i<k; i++){
	x=recherche_exhaustive(k, V, s-V[i]);

	  if((x+1)<NbCont) {
	    NbCont=x+1;
	  }
      }

      return NbCont;
    }
  }
}
