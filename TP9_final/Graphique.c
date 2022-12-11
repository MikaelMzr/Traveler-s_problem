/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 26-04-2021 */
/* Dernière modification : 27-04-2021 */
#include "Graphique.h"

void affiche_carte(Carte c, int largeur, int hauteur) {
	int i;
	for(i = 0; i < c.taille; i++) {
		MLV_draw_filled_rectangle((c.tab[i].x + 1) * 100 - 10, (c.tab[i].y + 1) * 100 - 10, 20, 20, MLV_COLOR_RED);
		MLV_draw_text((c.tab[i].x + 1) * 100 + 15, (c.tab[i].y + 1) * 100 - 10, c.tab[i].nom_ville, MLV_COLOR_YELLOW);
	}		
}

void affiche_chemin(Visite v) {
	int i;
	for(i = 0; i < v.taille - 1; i++) {
		MLV_draw_line((v.tab[i].x + 1) * 100, (v.tab[i].y + 1) * 100, (v.tab[i + 1].x + 1) * 100, (v.tab[i + 1].y + 1) * 100, MLV_COLOR_WHITE);
	}
}

void affiche_distance(Visite v, int largeur, int hauteur) {
    char chaine[20];
    sprintf(chaine, "%f km", distance(v));
    MLV_draw_text((largeur - 0.5) * 100 - 45, 5, chaine, MLV_COLOR_YELLOW);
}

void affiche_generation(int n, int largeur, int hauteur) {
    char chaine[20];
    sprintf(chaine, "gen: %d", n);
    MLV_draw_text((largeur - 0.5) * 100 - 30, 20, chaine, MLV_COLOR_YELLOW);
}
	
void affiche_visite(Visite v, Carte c, int largeur, int hauteur) {
    MLV_clear_window(MLV_COLOR_BLACK);
    affiche_carte(c, largeur, hauteur);
    affiche_chemin(v);
    affiche_distance(v, largeur, hauteur);
    
}
