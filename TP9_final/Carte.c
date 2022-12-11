/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 13-04-2021 */
/* Dernière modification : 27-04-2021 */
#include "Carte.h"

Carte init_carte(char* nom_fichier) {
	Carte c;
	FILE *f;
	int taille, i;
	char lettre;

	taille = 0;
	i = 0;
	f = fopen(nom_fichier, "r");

	while((lettre = fgetc(f)) != EOF) {
		if(lettre == '\n')
			taille++;
	}

	c.taille = taille;
	c.tab = (Ville*)malloc(taille * sizeof(Ville));

	rewind(f);

	while(!feof(f)) {
		fscanf(f, "%s %d %d", c.tab[i].nom_ville, &(c.tab[i].x), &(c.tab[i].y));
		c.tab[i].etiquette = i;
		i++;
	}

	fclose(f);

	return c;
}

void configure_affichage(Carte c, int *largeur, int *hauteur) {
	int i;

	*largeur = 1;
	*hauteur = 1;

	for(i = 0; i < c.taille; i++) {
		if(*largeur < c.tab[i].x)
			*largeur = c.tab[i].x;
		if(*hauteur < c.tab[i].y)
			*hauteur = c.tab[i].y;
	}
}