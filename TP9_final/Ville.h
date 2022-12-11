/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 13-04-2021 */
/* Dernière modification : 13-04-2021 */
#ifndef __VILLE__H__
#define __VILLE__H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nom_ville[128];
    int x;
    int y;
    int etiquette;
}Ville;

/* Renvoie 1 si v1 est égale à v2,
 * Renvoie 0 sinon. */
int sont_ega_ville(Ville v1, Ville v2);

/* Renvoie 1 si v1 est différente à v2,
 * Renvoie 0 sinon. */
int sont_dif_ville(Ville v1, Ville v2);

#endif