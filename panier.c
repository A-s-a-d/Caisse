#include "panier.h"
#include "personnes.h"
#include "produits.h"

int     PANIER_PRODS_QTE[MAX_PRODUITS]  =   { 0 };
float   PRIX_TOTAL                      =     0.0;
bool    CLIENT_FIDELE                   =   false;


bool panier_remise_client(void)
{
//  retirer cette ligne une fois que vous avez commencé à écrire le code de cette fonction. 
    A_FAIRE();
    return true;
}

void panier_initialiser(void)
{
    for (int i = 0; i < MAX_PRODUITS; ++i)
        PANIER_PRODS_QTE[i] = 0;
    PRIX_TOTAL = 0.;
}

void panier_afficher(void)
{
    /* TODO
     * Lit la quantite de chaque produit dans le tableau des quantites. Si la
     * quantite d'un produit est positive, alors on affiche le produit, sa
     * quantite, et le prix total par produit.
     * On affiche un produit/quantite/total par ligne.
     * On affiche le prix total à la fin sur une ligne à part, et on retourne à
     * la ligne.
     */
//  retirer cette ligne une fois que vous avez commencé à écrire le code de cette fonction. 
    A_FAIRE();
}

void panier_payer(void)
{
    float prix = PRIX_TOTAL;
    panier_afficher();
    if (! CLIENT_FIDELE) {
        printf("Faites-vous partie du programme fidelite ? (o/n) ");
        char reponse = lire_char();
    }
    if (CLIENT_FIDELE) {
        float remise = 0.0;
        if        (prix >= 100) {
            prix *= .90;
            remise = 10;
        } else if (prix >= 15)  {
            prix *= .95;
            remise = 5;
        }
        printf("Total apres remise : %.2f (%.0f%% de remise)\n", prix, remise);
    }
//  retirer cette ligne une fois que vous avez commencé à écrire le code de cette fonction, 
//  et que vous avez vérifié que tout fonctionne comme spécifié.
    A_FAIRE();
}

