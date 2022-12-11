/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 13-04-2021 */
/* Dernière modification : 22-04-2021 */
#include "Visite.h"

Visite init_visite(int taille) {
	Visite v;

	v.taille = taille;
	v.tab = (Ville*)malloc(taille * sizeof(Ville));

	return v;
}

float distance(Visite v){
    int i;
    int j;
    float d;

    d = 0;
    for(i=0, j=1; i < v.taille - 1 && j < v.taille; i++, j++){
        d += sqrt(pow(v.tab[j].x - v.tab[i].x, 2) + pow(v.tab[j].y - v.tab[i].y, 2));
    }
    return d;
}

int sont_ega_visite(Visite v1, Visite v2){
    int i, taille;
    
    taille = v1.taille;
    for(i=0; i < taille; i++){
        if(v1.tab[i].etiquette != v2.tab[i].etiquette){
            return 0;
        }
    }
    return 1;
}

int sont_dif_visite(Visite v1, Visite v2){
    int i, taille;
    
    taille = v1.taille;
    for(i=0; i < taille; i++){
        if(v1.tab[i].etiquette != v2.tab[i].etiquette){
            return 1;
        }
    }
    return 0;
}

void sauvegarde_visite(Visite v) {
	FILE *f;
	int i;

	f = fopen("CARTE.pvc", "w+");

	for(i = 0; i < v.taille; i++)
		fprintf(f, "%s ", v.tab[i].nom_ville);
	fprintf(f, "%f\n", distance(v));

	fclose(f);
}