/* Auteur: yorick LE MOING Groupe: 6*/
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

#define NB_CHOIX_GRILLE 7
#define COTE_GRILLE 450
#define COTE_FOND 170
#define COTE_GRILLE 450
#define ECART 20
#define X_POS_GRILLE 125
#define Y_POS_GRILLE 200
#define FENETRE 700
#define INI 0
#define Y_RECT 100
#define X_RECT 300
#define X_CHOIX_JOUEUR 140
#define COTE_CHOIX_GRILLE 42
#define X_CHOIX_GRILLE 294
#define X_POS 200
#define X_POS_2 360
#define Y_POS_TITRE 208
#define X_POS_CHOIX_GRILLE 203
#define Y_POS_CHOIX_JOUEUR 333
#define Y_POS_CHOIX_GRILLE 458
#define Y_POS_JOUER 525
#define Y_POS_REJOUER 450
#define Y_POS_QUITTER 555
#define Y_POS_VAINQUEUR 208
#define Y_POS_JOUEUR_GAGNANT 333
#define X_POS_JOUEUR_GAGNANT 220

void Fond(void){
  int i,y;
  for(i=INI;i*COTE_FOND<FENETRE;i++){
    for(y=INI;y*COTE_FOND<FENETRE;y++){
      ChargerImage("img/fond.jpg",i*COTE_FOND,y*COTE_FOND,INI,INI,COTE_FOND,COTE_FOND);
    }
  }
  return;
}

void InitialiserPos(int tab_pos[9][9]){
  int i,j;
  for(i=0;i<9;i++){
    for(j=0;j<9;j++){
      tab_pos[i][j]=0;
    }
  }
  return;
}

void Tempo(void){
  unsigned long temp=0,i;
  i=Microsecondes();
  while(temp<200000){
    
    temp=Microsecondes()-i;
  }
}
