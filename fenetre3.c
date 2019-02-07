/* Auteur: yorick LE MOING Groupe: 6*/
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

#include "initialisation.h"

void AffichageResultat(int joueur){
  
  ChargerImage("img/vainqueur.png",X_POS,Y_POS_TITRE,INI,INI,X_RECT,Y_RECT);
  if(joueur==1)
    ChargerImage("img/gagnant_j1.png",X_POS_JOUEUR_GAGNANT,Y_POS_JOUEUR_GAGNANT,INI,INI,X_RECT,Y_RECT);
  else
    ChargerImage("img/gagnant_j2.png",X_POS_JOUEUR_GAGNANT,Y_POS_JOUEUR_GAGNANT,INI,INI,X_RECT,Y_RECT);
  ChargerImage("img/rejouez.png",X_POS,Y_POS_REJOUER,INI,INI,X_RECT,Y_RECT);
  ChargerImage("img/quitter.png",X_POS,Y_POS_QUITTER,INI,INI,X_RECT,Y_RECT);
}
int ChoixFin(void){
  int choix_fin=0;
  while(choix_fin==0){
    if(SourisCliquee()){
      SourisPosition();
      if(_X>X_POS && _X<X_POS+X_RECT){
	if(_Y>Y_POS_REJOUER && _Y<Y_POS_REJOUER+Y_RECT){
	  choix_fin=1;
	}
	else if(_Y>Y_POS_QUITTER && _Y<Y_POS_QUITTER+Y_RECT){
	  choix_fin=-1;
	}
      }
    }
  }
  return(choix_fin);
}


