/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 22-04-2021 */
/* Dernière modification : 22-04-2021 */
#ifndef __GENETIQUE__H__
#define __GENETIQUE__H__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Visite.h"

typedef struct {
	int alpha;
	int beta;
	int gamma;
} Parametre;

/* Demande à l'utilisateur de saisir les paramètres. */
Parametre init_parametre();

/* Renvoie 1 si toutes les cases sont à 1,
 * renvoie 0 sinon. */
int verif_tab_complet(int *tab, int taille);

/* Renvoie une visite aléatoire des villes de la carte c. */
Visite gen_visite_alea(Carte c);

/* Compare les distances des visites.
 * Renvoie -1 si la distance de v1 est inférieure à celle de v2.
 * Renvoie 0 si la distance de v1 est égale à celle de v2.
 * Renvoie 1 si la distance de v1 est supérieure à celle de v2.*/
int compare_distance(const void *v1, const void *v2);

/* Mute la visite v1. */
Visite mutation(Visite v1);

void nouvelle_generation(Visite* tab_v, int taille, Parametre p, Carte c);

#endif