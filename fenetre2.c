/* Auteur: yorick LE MOING Groupe: 6*/
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

#include "initialisation.h"



void DessinerJoueur(int x,int y,couleur c,int cote){
  ChoisirCouleurDessin(c);
  RemplirRectangle(x*cote+X_POS_GRILLE+ECART/2,y*cote+Y_POS_GRILLE+ECART/2,cote-ECART,cote-ECART);
  return;
}

int AffichageGrille(int taille){
  int cote,x,y;
  couleur noir,bleu,rouge,blanc;
  rouge=CouleurParComposante(255,0,0);
  noir=CouleurParComposante(0,0,0);
  bleu=CouleurParComposante(0,0,255);
  blanc=CouleurParComposante(255,255,255);
  cote=COTE_GRILLE/taille;
  
  ChoisirCouleurDessin(noir);
  for(x=X_POS_GRILLE;x<(taille*cote+X_POS_GRILLE);x=x+cote){
    for(y=Y_POS_GRILLE;y<(taille*cote+Y_POS_GRILLE);y=y+cote){
      ChoisirCouleurDessin(blanc);
      RemplirRectangle(x,y,cote,cote);
      ChoisirCouleurDessin(noir);
      DessinerRectangle(x,y,cote,cote);
    }
  }
  DessinerJoueur(INI,INI,bleu,cote);
  DessinerJoueur(taille-1,taille-1,rouge,cote);
  return(cote);
}

void DessinerCroix(int x,int y,couleur c,int cote){
  ChoisirCouleurDessin(c);
  DessinerSegment(x*cote+X_POS_GRILLE,y*cote+Y_POS_GRILLE,(x+1)*cote+X_POS_GRILLE,(y+1)*cote+Y_POS_GRILLE);
  DessinerSegment(x*cote+X_POS_GRILLE,(y+1)*cote+Y_POS_GRILLE,(x+1)*cote+X_POS_GRILLE,y*cote+Y_POS_GRILLE);
  return;
}
void TourJoueur(int cote,int tab_pos[9][9],int old_pos[2][2],int joueur){
  int x,y,i=0,x_adj,y_adj;
  couleur noir,bleu,rouge,blanc;
  rouge=CouleurParComposante(255,0,0);
  noir=CouleurParComposante(0,0,0);
  bleu=CouleurParComposante(0,0,255);
  blanc=CouleurParComposante(255,255,255);
 
  while(i!=2){
    if(SourisCliquee()){
      SourisPosition();
      if(_X>X_POS_GRILLE && _X<X_POS_GRILLE+COTE_GRILLE && _Y>Y_POS_GRILLE && _Y<Y_POS_GRILLE+COTE_GRILLE){
	x=(_X-X_POS_GRILLE)/cote;
	y=(_Y-Y_POS_GRILLE)/cote;
	
	if(tab_pos[x][y]==0 && i==0){
	  if(joueur==1){
	    x_adj=(old_pos[0][0]-x)*(old_pos[0][0]-x);
	    y_adj=(old_pos[0][1]-y)*(old_pos[0][1]-y);
	    if(x_adj<2 && y_adj<2){
	      DessinerJoueur(old_pos[0][0],old_pos[0][1],blanc,cote);
	      DessinerJoueur(x,y,bleu,cote);
	      tab_pos[old_pos[0][0]][old_pos[0][1]]=0;
	      old_pos[0][0]=x;
	      old_pos[0][1]=y;
	      i++;
	      tab_pos[x][y]=2;
	    }
	  }
	  else if(joueur==2){
	    x_adj=(old_pos[1][0]-x)*(old_pos[1][0]-x);
	    y_adj=(old_pos[1][1]-y)*(old_pos[1][1]-y);
	    if(x_adj<2 && y_adj<2){
	      DessinerJoueur(old_pos[1][0],old_pos[1][1],blanc,cote);
	      DessinerJoueur(x,y,rouge,cote);
	      tab_pos[old_pos[1][0]][old_pos[1][1]]=0;
	      old_pos[1][0]=x;
	      old_pos[1][1]=y;
	      i++;
	      tab_pos[x][y]=3;
	    } 
	  }
	}
	if(tab_pos[x][y]==0  && i==1){
	  DessinerCroix(x,y,noir,cote);
	  i++;
	  tab_pos[x][y]=1;
	}
      }
    }
  }
  return;
}

void TourBot(int taille,int tab_pos[9][9],int old_pos[2][2],int cote){
  int x,y,i=0,x_adj,y_adj;
  couleur noir,bleu,blanc;
  noir=CouleurParComposante(0,0,0);
  bleu=CouleurParComposante(0,0,255);
  blanc=CouleurParComposante(255,255,255);
 
  while(i!=2){
    x=(Microsecondes()%((taille-1)-0+1))+0;
    y=(Microsecondes()%((taille-1)-0+1))+0;
    if(tab_pos[x][y]==0 && i==0){
      x_adj=(old_pos[0][0]-x)*(old_pos[0][0]-x);
      y_adj=(old_pos[0][1]-y)*(old_pos[0][1]-y);
      if(x_adj<2 && y_adj<2){
	Tempo();
	DessinerJoueur(old_pos[0][0],old_pos[0][1],blanc,cote);
	DessinerJoueur(x,y,bleu,cote);
	tab_pos[old_pos[0][0]][old_pos[0][1]]=0;
	old_pos[0][0]=x;
	old_pos[0][1]=y;
	i++;
	tab_pos[x][y]=2;
      }
    }
    if(tab_pos[x][y]==0  && i==1){
      Tempo();
      DessinerCroix(x,y,noir,cote);
      i++;
      tab_pos[x][y]=1;
    }
  }
  return;
}
int FinDeJeu(int tab_pos[9][9],int taille){
  int i,j,x,y,i_ini,j_ini,i_max,j_max,cpt,bloque,fin=0;
  for(x=0;x<taille;x++){
    for(y=0;y<taille;y++){
      i_max=x+2;
      j_max=y+2;
      i_ini=x-1;
      j_ini=y-1;
      cpt=bloque=0;
      
      if(tab_pos[x][y]==2){

	if(x==0)
	  i_ini=x;
	if(y==0)
	  j_ini=y;
	if(x==(taille-1))
	  i_max=x+1;
	if(y==(taille-1))
	  j_max=y+1;

	for(i=i_ini;i<i_max;i++){
	  for(j=j_ini;j<j_max;j++){
	    cpt++;
	    if(tab_pos[i][j]!=0)
	      bloque++;
	  }
	}
	if(cpt==bloque)
	    fin=2;
      }
      if(tab_pos[x][y]==3){

	if(x==0)
	  i_ini=x;
	if(y==0)
	  j_ini=y;
	if(x==(taille-1))
	  i_max=x+1;
	if(y==(taille-1))
	  j_max=y+1;
	
	for(i=i_ini;i<i_max;i++){
	  for(j=j_ini;j<j_max;j++){
	    cpt++;
	    if(tab_pos[i][j]!=0)
	      bloque++;
	  }
	}
	if(cpt==bloque)
	  fin=1;
	
      }
      
    }
  }
  return(fin);
}
