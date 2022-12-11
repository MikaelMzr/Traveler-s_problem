/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 22-04-2021 */
/* Dernière modification : 22-04-2021 */
#include "Genetique.h"

Parametre init_parametre(){
    Parametre p;

    printf("Veuillez saisir un paramètre alpha\n");
    scanf("%d",&p.alpha);
    printf("Veuillez saisir un paramètre beta\n");
    scanf("%d",&p.beta);
    p.gamma = 100 - p.alpha - p.beta;

    if(p.gamma < 0){
        fprintf(stderr, "probleme alpha ou beta\n");
    }

    return p;
}

int verif_tab_complet(int *tab, int taille){
    int i;

    for(i=0; i < taille; i++){
        if(tab[i] == 0){
            return 0;
        }
    }
    return 1;
}

Visite gen_visite_alea(Carte c) {
	Visite v;
	int tab_mem[c.taille];
	int i, choix_alea;

	v = init_visite(c.taille);

	for(i = 0; i < c.taille; i++)
		tab_mem[i] = 0;

	i = 0;
	while(!(verif_tab_complet(tab_mem, c.taille))) {
		choix_alea = rand() % c.taille;
		/* Si c'est la première fois que l'on a cette étiquette. */
		if(tab_mem[choix_alea] == 0) {
			v.tab[i] = c.tab[choix_alea];
			tab_mem[choix_alea] = 1;
			i++;
		}
	}

	return v;
}

int compare_distance(const void *v1, const void *v2) {
	Visite visite_1, visite_2;
	float d1, d2, resultat;

	visite_1 = (* (const Visite *) v1);
	visite_2 = (* (const Visite *) v2);

	d1 = distance(visite_1);
	d2 = distance(visite_2);

	resultat = d1 - d2;

	if(resultat < 0)
		return -1;
	else if(resultat > 0)
		return 1;
	return 0;
}

Visite mutation(Visite v1){
    Ville res;
    int i;
    int alea_debut, alea_taille, alea_3;

    alea_debut = rand() % (v1.taille / 2);
    alea_taille = rand() % ((v1.taille - alea_debut) / 2) + 1;
    if(v1.taille - alea_debut - (2 * alea_taille) + 1 == 0)
    	alea_3 = 0;
    else
    	alea_3 = rand() % (v1.taille - alea_debut - (2 * alea_taille) + 1);

    /*printf("alea_debut: %d\n", alea_debut);
    printf("alea_taille: %d\n", alea_taille);
    printf("alea_3: %d\n", alea_3);*/

    /*échange*/
    for(i = alea_debut; i < alea_debut + alea_taille; i++){
    	res = v1.tab[i];
        v1.tab[i] = v1.tab[i + alea_taille + alea_3];
        v1.tab[i + alea_taille + alea_3] = res;
        /*printf("%s %s\n", v1.tab[i].nom_ville, v1.tab[i + alea_taille + alea_3].nom_ville);*/
    }

    return v1;
}

void nouvelle_generation(Visite* tab_v, int taille, Parametre p, Carte c) {
	int i;
	assert(p.alpha + p.beta + p.gamma == taille);
	for(i = p.beta; i < p.beta + p.alpha; i++)
		tab_v[i] = mutation(tab_v[i]);
	for(i = p.beta + p.alpha; i < p.beta + p.alpha + p.gamma; i++)
		tab_v[i] = gen_visite_alea(c);
}
