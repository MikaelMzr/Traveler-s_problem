/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 28-04-2021 */
/* Dernière modification : 03-05-2021 */
#ifndef __TEST__H__
#define __TEST__H__
#include <stdio.h>
#include "Genetique.h"

/* Test la fonction verif_tab_complet()
 * Renvoie 1 si tous les tests réussissent, 
 * renvoie 0 si au moins 1 test échoue. */
int test_verif_tab_complet(void);

/* Lance tous les tests.
 * Renvoie si tous les tests réussissent, 
 * renvoie 0 si au moins 1 test échoue. */
int test_global(void);

#endif