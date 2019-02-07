/* Auteur: yorick LE MOING Groupe: 6*/
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "fenetre1.h"
#include "fenetre2.h"
#include "fenetre3.h"
#include "initialisation.h"

int main(void){
  int choix_fin=0,fin=0,cote;
  int choix_parametre[2]={0,0};
  couleur noir;
  int old_pos[2][2]={{0,0},
		     {0,0}};
  int tab_pos[9][9];
  
  InitialiserGraphique();
  
  noir=CouleurParComposante(0,0,0);
  
  CreerFenetre(INI,INI,FENETRE,FENETRE);
  while(choix_fin!=-1){
    InitialiserPos(tab_pos);
    fin=0;
    ChoisirEcran(1);
    Fond();
    ChoisirCouleurDessin(noir);
    AffichageAccueil();
    ChoisirEcran(0);
    CopierZone(1,0,INI,INI,FENETRE,FENETRE,INI,INI);
    ChoixAccueil(choix_parametre);
    old_pos[0][0]=0;
    old_pos[0][1]=0;
    old_pos[1][0]=(choix_parametre[1]-1);
    old_pos[1][1]=(choix_parametre[1]-1);
    tab_pos[0][0]=2;
    tab_pos[choix_parametre[1]-1][choix_parametre[1]-1]=3;
    ChoisirEcran(2);
    Fond();
    ChoisirCouleurDessin(noir);
    cote=AffichageGrille(choix_parametre[1]);
    CopierZone(2,0,INI,INI,FENETRE,FENETRE,INI,INI);
    ChoisirEcran(0);
    while(fin==0){
      if(choix_parametre[0]==1){
	TourBot(choix_parametre[1],tab_pos,old_pos,cote);
      }
      else{
	TourJoueur(cote,tab_pos,old_pos,1);
      }
      fin=FinDeJeu(tab_pos,choix_parametre[1]);
      if(fin==0){
	TourJoueur(cote,tab_pos,old_pos,2);
	fin=FinDeJeu(tab_pos,choix_parametre[1]);
      }
      Tempo();
    }
    ChoisirEcran(3);
    Fond();
    ChoisirCouleurDessin(noir);
    AffichageResultat(fin);
    CopierZone(3,0,INI,INI,FENETRE,FENETRE,INI,INI);
    ChoisirEcran(0);
    choix_fin=ChoixFin();
  }
    FermerGraphique();
    return EXIT_SUCCESS;
}
