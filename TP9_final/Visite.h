/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 13-04-2021 */
/* Dernière modification : 22-04-2021 */
#ifndef __VISITE__H__
#define __VISITE__H__
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>
#include "Carte.h"

typedef struct{
    int taille; 
    Ville *tab;
}Visite;

/* Initialise une visite,
 * alloue dynamiquement le tab de Ville.
 * Renvoie la visite. */
Visite init_visite(int taille);

/* Libère le tab de Ville. */
void libere_visite(Visite v);

/* Renvoie la somme des distances entre les villes. */
float distance(Visite v);

/* Renvoie 1 si v1 est égale à v2,
 * Renvoie 0 sinon. */
int sont_ega_visite(Visite v1, Visite v2);

/* Renvoie 1 si v1 est différente à v2,
 * Renvoie 0 sinon. */
int sont_dif_visite(Visite v1, Visite v2);

/* Enregistre les villes parcourues par la visite dans l'ordre
 * dans le fichier CARTE.pvc. */
void sauvegarde_visite(Visite v);

#endif