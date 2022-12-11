/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 13-04-2021 */
/* Dernière modification : 27-04-2021 */
#ifndef __CARTE__H__
#define __CARTE__H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ville.h"

typedef struct{
    int taille; 
    Ville *tab;
}Carte;

/* Initialise la carte en lisant les villes et leurs
 * coordonées dans le fichier nom_fichier.
 * Renvoie cette carte. */
Carte init_carte(char *nom_fichier);

/* Attribue à largeur le x le plus grand parmi les villes
 * de la Carte c, de même pour hauteur avec y.  */
void configure_affichage(Carte c, int *largeur, int *hauteur);

#endif