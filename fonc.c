#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ALGORITHME :
1. Récupérer la valeur de x depuis la ligne de commande (dernier argument).
2. Vérifier si x appartient au domaine de définition (Df) :
   - x doit être > 0 pour le logarithme ln(2x).
   - 5x - 1 doit être >= 0 pour la racine carrée, soit x >= 0.2.
   - x doit être différent de 0 pour le dénominateur.
3. Si x < 0.2, lever un drapeau d'erreur.
4. Sinon, calculer y = (cos(x) - ln(2*x) + sqrt(5*x - 1)) / x.
5. Afficher le résultat ou le message d'erreur selon le drapeau.
*/

int verifier(int c) {
    return (c >= 3);
}

float faire_calculs(float x, int *err) {
    if (x < 0.2) {
        *err = 1;
        return 0;
    }
    return (cos(x) - log(2 * x) + sqrt(5 * x - 1)) / x;
}

void affiche(int e, float x, float r) {
    if (e) {
        printf("Erreur : x=%.2f est hors du domaine (Df : x >= 0.2)\n", x);
    } else {
        printf("f(%.2f) = %.4f\n", x, r);
    }
}

int main(int argc, char **tab) {
    if (!verifier(argc)) {
        printf("Usage: %s -p \"formule\" valeur_x\n", tab[0]);
        return 1;
    }

    float x = atof(tab[argc - 1]);
    int erreur = 0;
    float y = faire_calculs(x, &erreur);

    affiche(erreur, x, y);

    return 0;
}
