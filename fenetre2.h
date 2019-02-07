/* Auteur: yorick LE MOING Groupe: 6*/
#ifndef FENETRE2_H
#define FENETRE2_H


void DessinerJoueur(int x,int y,couleur c,int cote);
/* Dessine un carre de couleur representant un joueur
 * 1er argument: la position x du joueur
 * 2eme argument: la position y du joueur
 * 3eme argument : la couleur du joueur
 * 4eme argument : le cote du carre
 */

int AffichageGrille(int taille);
/* Affiche la grille avec la taille souhaitée
* argument : taille de la grille
* renvoie le cote d'un carre de la grille
*/

void DessinerCroix(int x,int y,couleur c,int cote);
/* Dessine une croix representant une case bloquée 
 * 1er argument: la position x de la croix
 * 2eme argument: la position y de la croix
 * 3eme argument : la couleur de la croix (noir)
 * 4eme argument : le cote d'un carre de la grille
 */

void TourJoueur(int cote,int tab_pos[9][9],int old_pos[2][2],int joueur);
/* change la position du joueur en verifiant si la case est adjacente
 * ou si elle n'est pas bloquée et place une croix a la position souhaitée
 * 1er argument: le cote d'un carre de la grille
 * 2eme argument: le tableau des position des joueur et croix
 * 3eme argument : les ancienne position des joueur                        
 * old_pos[0][0]=x_joueur1 , old_pos[0][1]=y_joueur1
 * old_pos[1][0]=x_joueur1 , old_pos[1][1]=y_joueur1
 * 4eme argument : le joueur dont c'est le tour
 */

void TourBot(int taille,int tab_pos[9][9],int old_pos[2][2],int cote);
/* change la position du joueur aléatoirement en verifiant si la case
 * est adjacente
 * ou si elle n'est pas bloquée et place une croix aléatoirement
 * 1er argument: la taille de la grille
 * 2eme argument: le tableau des position des joueur et croix
 * 3eme argument : les ancienne position des joueur                        
 * old_pos[0][0]=x_joueur1 , old_pos[0][1]=y_joueur1
 * old_pos[1][0]=x_joueur2 , old_pos[1][1]=y_joueur2
 * 4eme argument : le cote d'un carre de la grille
 */

int FinDeJeu(int tab_pos[9][9],int taille);
/* verifie si un joueur et bloquée
 * 1er argument: le tableau des position des joueur et croix
 * 2eme argument: la taille de la grille 
 * renvoie 1 si un joueur ne peut plus se déplacer
 */


  
#endif /* FENETRE2_H */
