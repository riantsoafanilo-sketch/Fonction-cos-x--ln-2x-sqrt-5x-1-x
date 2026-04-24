#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ALGORITHME :
   1. Entrée : Récupérer la chaîne de caractères à la fin de la commande (tab[argc-1]).
   2. Conversion : Transformer cette chaîne en nombre flottant (x) via atof.
   3. Vérification du Df (Domaine de définition) :
      - La fonction contient ln(2x) -> impose 2x > 0 (x > 0).
      - La fonction contient sqrt(5x-1) -> impose 5x-1 >= 0 (x >= 0.2).
      - La borne restrictive est donc x >= 0.2.
   4. Traitement : 
      - Si x < 0.2, lever un indicateur d'erreur.
      - Sinon, calculer y = (cos(x) - ln(2*x) + sqrt(5*x - 1)) / x.
   5. Sortie : Appeler la fonction d'affichage pour imprimer soit l'erreur, soit le résultat.
*/

void afficher_resultat(int erreur, float x, float y) {
    if (erreur) {
        printf("Erreur : x=%.2f est hors du domaine de definition.\n", x);
    } else {
        printf("f(%.2f) = %.4f\n", x, y);
    }
}

float calculer(float x, int *statut_erreur) {
    if (x < 0.2) {
        *statut_erreur = 1;
        return 0;
    }
    *statut_erreur = 0;
    return (cos(x) - log(2 * x) + sqrt(5 * x - 1)) / x;
}

int main(int argc, char **tab) {
    if (argc < 3) return 1;

    float x = atof(tab[argc - 1]);
    int erreur;
    float resultat = calculer(x, &erreur);

    afficher_resultat(erreur, x, resultat);

    return erreur;
}
