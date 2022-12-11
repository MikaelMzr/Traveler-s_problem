/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 26-04-2021 */
/* Dernière modification : 26-04-2021 */
#ifndef __GRAPHIQUE__H__
#define __GRAPHIQUE__H__
#include <stdlib.h>
#include <assert.h>
#include <MLV/MLV_all.h>
#include "Visite.h"
#include "Carte.h"

/* Affiche sur la fenêtre les villes de la Carte c. */
void affiche_carte(Carte c, int largeur, int hauteur);

/* Affiche les chemins qui lient les villes. */
void affiche_chemin(Visite v);

/* Affiche la distance de la visite en haut à droite
 * de la fenêtre. */
void affiche_distance(Visite v, int largeur, int hauteur);

/* Affiche le numéro de la génération actuel. */
void affiche_generation(int n, int largeur, int hauteur);

/* Affiche les villes et les chemins. */
void affiche_visite(Visite v, Carte c, int largeur, int hauteur);

#endif
