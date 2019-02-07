/* Auteur: yorick LE MOING Groupe: 6*/
#ifndef DEFINE_H
#define DEFINE_H

#define COTE_FOND 170
#define NB_CHOIX_GRILLE 7
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

void Fond(void);
/*Affiche le fond d'écran*/

void Tempo(void);
/*temporise de 0.2 seconde*/

void InitialiserPos(int tab_pos[9][9]);
/* remet les position a 0 
 * 1er argument:le tableau des position des joueur et croix
 */

#endif /* DEFINE_H */
