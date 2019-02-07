/* Auteur: yorick LE MOING Groupe: 6*/
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

#include "initialisation.h"



void AffichageAccueil(void){
  int i;
  ChargerImage("img/titre_fenetre1.png",X_POS,Y_POS_TITRE,INI,INI,X_RECT,Y_RECT);
  ChargerImage("img/rectangle_cocher.png",X_POS,Y_POS_CHOIX_JOUEUR,INI,INI,X_CHOIX_JOUEUR,Y_RECT);
  ChargerImage("img/1joueur.png",X_POS,Y_POS_CHOIX_JOUEUR,INI,INI,X_CHOIX_JOUEUR,Y_RECT);
  ChargerImage("img/rectangle_joueur.png",X_POS_2,Y_POS_CHOIX_JOUEUR,INI,INI,X_CHOIX_JOUEUR,Y_RECT);
  ChargerImage("img/2joueur.png",X_POS_2,Y_POS_CHOIX_JOUEUR,INI,INI,X_CHOIX_JOUEUR,Y_RECT);
  ChargerImage("img/carre_cocher.png",X_POS_CHOIX_GRILLE,Y_POS_CHOIX_GRILLE,INI,INI,COTE_CHOIX_GRILLE,COTE_CHOIX_GRILLE);
 
  for(i=1;i<NB_CHOIX_GRILLE;i++){
    ChargerImage("img/carre.png",X_POS_CHOIX_GRILLE+i*COTE_CHOIX_GRILLE,Y_POS_CHOIX_GRILLE,INI,INI,COTE_CHOIX_GRILLE,COTE_CHOIX_GRILLE);
  }
  ChargerImage("img/choix_grille.png",X_POS_CHOIX_GRILLE,Y_POS_CHOIX_GRILLE,INI,INI,X_CHOIX_GRILLE,COTE_CHOIX_GRILLE);
  ChargerImage("img/bouton_jouer.png",X_POS,Y_POS_JOUER,INI,INI,X_RECT,Y_RECT);
  return;
}

void ChoixAccueil(int choix[2]){
  int nb_joueur=1,choix_taille=0,quit=0,old_choix_taille;
  while(quit==0){
    if(SourisCliquee()){
      SourisPosition();
      if(_Y>Y_POS_CHOIX_JOUEUR && _Y<Y_POS_CHOIX_JOUEUR+Y_RECT){
	if(_X>X_POS && _X<X_POS+X_CHOIX_JOUEUR){
	  ChargerImage("rectangle_cocher.png",X_POS,Y_POS_CHOIX_JOUEUR,INI,INI,X_CHOIX_JOUEUR,Y_RECT);
	  ChargerImage("rectangle_joueur.png",X_POS_2,Y_POS_CHOIX_JOUEUR,INI,INI,X_CHOIX_JOUEUR,Y_RECT);
	  ChargerImage("2joueur.png",X_POS_2,Y_POS_CHOIX_JOUEUR,INI,INI,X_CHOIX_JOUEUR,Y_RECT);
	  ChargerImage("1joueur.png",X_POS,Y_POS_CHOIX_JOUEUR,INI,INI,X_CHOIX_JOUEUR,Y_RECT);
	  nb_joueur=1;
	}
	else if(_X>X_POS_2 && _X<X_POS_2+X_CHOIX_JOUEUR){
	  ChargerImage("img/rectangle_cocher.png",X_POS_2,Y_POS_CHOIX_JOUEUR,INI,INI,X_CHOIX_JOUEUR,Y_RECT);
	  ChargerImage("img/rectangle_joueur.png",X_POS,Y_POS_CHOIX_JOUEUR,INI,INI,X_CHOIX_JOUEUR,Y_RECT);
	  ChargerImage("img/2joueur.png",X_POS_2,Y_POS_CHOIX_JOUEUR,INI,INI,X_CHOIX_JOUEUR,Y_RECT);
	  ChargerImage("img/1joueur.png",X_POS,Y_POS_CHOIX_JOUEUR,INI,INI,X_CHOIX_JOUEUR,Y_RECT);
	  nb_joueur=2;
	}
      }
      if(_Y>Y_POS_CHOIX_GRILLE && _Y<Y_POS_CHOIX_GRILLE+COTE_CHOIX_GRILLE && _X>X_POS_CHOIX_GRILLE && _X<X_POS_CHOIX_GRILLE+COTE_CHOIX_GRILLE*NB_CHOIX_GRILLE){
	old_choix_taille=choix_taille;
	choix_taille=(_X-X_POS_CHOIX_GRILLE)/COTE_CHOIX_GRILLE;
        ChargerImage("img/carre_cocher.png",X_POS_CHOIX_GRILLE+choix_taille*COTE_CHOIX_GRILLE,Y_POS_CHOIX_GRILLE,INI,INI,COTE_CHOIX_GRILLE,COTE_CHOIX_GRILLE);
	ChargerImage("img/carre.png",X_POS_CHOIX_GRILLE+old_choix_taille*COTE_CHOIX_GRILLE,Y_POS_CHOIX_GRILLE,INI,INI,COTE_CHOIX_GRILLE,COTE_CHOIX_GRILLE);
	ChargerImage("img/choix_grille.png",X_POS_CHOIX_GRILLE,Y_POS_CHOIX_GRILLE,INI,INI,X_CHOIX_GRILLE,COTE_CHOIX_GRILLE);
        
      }
      
      if(_X>X_POS && _X<X_POS+X_RECT){
	if(_Y>Y_POS_JOUER && _Y<Y_POS_JOUER+Y_RECT){
	  quit=1;
	  choix[0]=nb_joueur;
	  choix[1]=choix_taille+3;
	}
      }
    }
  }
  return;
}

