/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 13-04-2021 */
/* Dernière modification : 26-04-2021 */
#include "Genetique.h"
#include "Graphique.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>

int main(int argc, char const *argv[]) {
	Visite tab_v[100];
	Carte c;
	Parametre p;
	int i;
	int generation;
	int largeur, hauteur;
	MLV_Button_state touche_entrer;

	srand(time(NULL));

	if(argc >= 2) {
		if(strcmp(argv[1], "-t") == 0)
			test_global();
		else
			printf("Erreur arguments.\n");
	}
	else {
		/* Initialisation de la Carte. */
		c = init_carte("Villes.txt");
		/* Initialisation de la première génération. */
		for(i = 0; i < 100; i++)
			tab_v[i] = gen_visite_alea(c);
		/* Nombre de générations. */
		generation = 1;
		/* Initialisaiton des paramètres. */
		p = init_parametre();
		/* Configuration de la fenêtre. */
		configure_affichage(c, &largeur, &hauteur);
		largeur += 2;
		hauteur += 2;

		/* Initialisation graphique. */
		MLV_create_window("Voyageur", "", 100 * largeur, 100 * hauteur);
		/* touche_entrer initialisé à non appuyée. */
		touche_entrer = MLV_RELEASED;

		affiche_carte(c, largeur, hauteur);
		MLV_actualise_window();

		while(touche_entrer == MLV_RELEASED) {
			touche_entrer = MLV_get_keyboard_state(MLV_KEYBOARD_RETURN);
		}

		while(touche_entrer != MLV_RELEASED) {
			touche_entrer = MLV_get_keyboard_state(MLV_KEYBOARD_RETURN);
		}

		while(touche_entrer == MLV_RELEASED) {
			touche_entrer = MLV_get_keyboard_state(MLV_KEYBOARD_RETURN);
			qsort(tab_v, 100, sizeof(Visite), compare_distance);

			affiche_visite(tab_v[0], c, largeur, hauteur);
			affiche_generation(generation, largeur, hauteur);
			MLV_actualise_window();
			
			nouvelle_generation(tab_v, 100, p, c);
			generation++;
		}

		MLV_free_window();

		sauvegarde_visite(tab_v[0]);

		for(i = 0; i < 100; i++)
			free(tab_v[i].tab);
		free(c.tab);
	}
	

	return 0;
}
