/* Dos Santos Loïc */
/* Mikael Mezouar */
/* Création : 13-04-2021 */
/* Dernière modification : 13-04-2021 */
#include "Ville.h"

int sont_ega_ville(Ville v1, Ville v2){
    if (v1.x == v2.x && v1.y == v2.y){
        return 1;
    }
    return 0;
}

int sont_dif_ville(Ville v1, Ville v2){
    if (v1.x != v2.x || v1.y != v2.y){
        return 1;
    }
    return 0;
}