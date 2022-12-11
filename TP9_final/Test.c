/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 28-04-2021 */
/* Dernière modification : 03-05-2021 */
#include "Test.h"

int test_verif_tab_complet(void) {
	int verif_retour, verif_actuel;
	int tab_1[1], tab_2[4], tab_3[4];

	verif_retour = 1;
	/* tab_1. */
	tab_1[0] = 1;
	/* tab_2. */
	tab_2[0] = 1;
	tab_2[1] = 1;
	tab_2[2] = 1;
	tab_2[3] = 1;
	/* tab_3. */
	tab_3[0] = 1;
	tab_3[1] = 0;
	tab_3[2] = 1;
	tab_3[3] = 1;

	verif_actuel = verif_tab_complet(tab_1, 1);
	printf("\tverif_tab_complet([1], 1): %d\n", verif_actuel);
	if(verif_actuel != 1)
		verif_retour = 0;

	verif_actuel = verif_tab_complet(tab_2, 4);
	printf("\tverif_tab_complet([1, 1, 1, 1], 4): %d\n", verif_actuel);
	if(verif_actuel != 1)
		verif_retour = 0;

	verif_actuel = verif_tab_complet(tab_3, 4);
	printf("\tverif_tab_complet([1, 0, 1, 1], 4): %d\n", verif_actuel);
	if(verif_actuel != 0)
		verif_retour = 0;

	return verif_retour;
}

int test_sont_ega_ville(void) {
	int verif_retour, verif_actuel;
	Ville v1, v2, v3, v4;

	verif_retour = 1;
	/* v1. */
	v1.x = 5;
	v1.y = 2;
	/* v2. */
	v2.x = 5;
	v2.y = 2;
	/* v3. */
	v3.x = 1;
	v3.y = 1;
	/* v4. */
	v4.x = 0;
	v4.y = 0;

	printf("\tv1 : x=%d, y=%d\n", v1.x, v1.y);
	printf("\tv2 : x=%d, y=%d\n", v2.x, v2.y);
	printf("\tv3 : x=%d, y=%d\n", v3.x, v3.y);
	printf("\tv4 : x=%d, y=%d\n", v4.x, v4.y);
	verif_actuel = sont_ega_ville(v1, v2);
	printf("\tsont_ega_ville(v1, v2): %d\n", verif_actuel);
	if(verif_actuel != 1)
		verif_retour = 0;

	verif_actuel = sont_ega_ville(v1, v3);
	printf("\tsont_ega_ville(v1, v3): %d\n", verif_actuel);
	if(verif_actuel != 0)
		verif_retour = 0;

	verif_actuel = sont_ega_ville(v3, v4);
	printf("\tsont_ega_ville(v3, v4): %d\n", verif_actuel);
	if(verif_actuel != 0)
		verif_retour = 0;

	return verif_retour;
}

int test_global(void) {
	int verif_global, verif_actuel;

	verif_global = 1;

	printf("Test verif_tab_complet():\n");
	verif_actuel = test_verif_tab_complet();
	printf("Renvoie test_verif_tab_complet(): %d\n\n", verif_actuel);

	verif_global = verif_global && verif_actuel;
	
	printf("Test sont_ega_ville():\n");
	verif_actuel = test_sont_ega_ville();
	printf("Renvoie test_sont_ega_ville(): %d\n\n", verif_actuel);

	verif_global = verif_global && verif_actuel;

	return verif_global;
}