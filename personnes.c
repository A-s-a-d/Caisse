#include "definitions.h"
#include "fichiers.h"
#include "chiffrement.h"

Personne PERSONNES[MAX_PERSONNES];
int      NB_PERS;
int Personne_existe = 0;
int vide = 1;


void personnes_remplir_liste()
{
    if (NB_PERS == 0 && !fichier_ouvert()) {
        printf("La base de donnee n'est pas ouverte !");
        return;
    }
/*
* to read the line and copy it to PERSONNES
*/
    char LIGNE[50];
    while (fgets(LIGNE, sizeof(LIGNE), CLIENTS))
        {
            if (strlen(LIGNE) == 1 || isspace(LIGNE[0]))
            {
                continue;
            }

            Personne p;
            //sscanf(LIGNE, "%49s %49s %u", p.nom, p.pnom, &p.tel); //
            sscanf(LIGNE, "%s %s %u", &p.nom, &p.pnom, &p.tel);
            printf("test : %s %s %u\n", p.nom, p.pnom, p.tel);



            for(int i = 0; i<NB_PERS; i++)
            {
                if(strcmp(PERSONNES[i].nom, p.nom) == 0 && strcmp(PERSONNES[i].pnom, p.pnom) == 0 && PERSONNES[i].tel == p.tel)
                {
                    Personne_existe = 1;
                    break;
                }
            }
            if(!Personne_existe)
            {
                PERSONNES[NB_PERS] = p;
                NB_PERS++;
            }

        }
    /*
    *print the number of lines read to verify
    */
        printf("TEST : -------------------------------: TEST\n");
        printf("test : Nombre de personnes lues : %d\n", NB_PERS);
    /*
    *print all the persones read to verify
    */
         for (int i = 0; i < NB_PERS; i++) {
        printf("test : %s %s %u\n", PERSONNES[i].nom, PERSONNES[i].pnom, PERSONNES[i].tel);
    }
/*
* j'ai fais cette fonction
*/
}

int personne_cmp(Personne p1, Personne p2)
{
    int cmp;

    cmp = strcmp(p1.nom, p2.nom);
    if (cmp != 0) return cmp;

    cmp = strcmp(p1.pnom, p2.pnom);
    if (cmp != 0) return cmp;

    if (p1.tel < p2.tel) return -1;
    else if (p1.tel > p2.tel) return 1;

    return 0;
}

int personne_rechercher(Personne p)
{
    for (int i = 0; i < NB_PERS; ++i)
        if (personne_cmp(p, PERSONNES[i]) == 0)
            return i;

    return -1;
}

int personne_ajouter(Personne p)
{
    if (NB_PERS >= MAX_PERSONNES)
        return MAX_PERSONNES;

    int idx = personne_rechercher(p);

    if (idx != -1)
        return idx;

    PERSONNES[NB_PERS++] = p;

    return 0;
}


/* une meilleure solution est d'utiliser isspace()  (voir la doc de ctype.h) */
bool est_un_espace(char c) {
    return c == ' ' || c == '\t';
}

/* Fonction utilitaire.
 * Elle ne sert que dans ce fichier, c'est pourquoi elle n'est pas exposée dans
 * personnes.h.
 *
 * XXX Note : peut-être que vous n'aurez pas besoin de la fonction
 * copier_prochain_champ, mais le fait qu'elle existe devrait vous donner un
 * indice sur une façon de réaliser personne_creer…
 */
int copier_prochain_champ(char dst[], int taille, CH50 ligne, int decalage)
{
//  retirer cette ligne une fois que vous avez commencé à écrire le code de cette fonction.
    A_FAIRE();
    return  0; // indice du prochain caractère à traiter
}


Personne personne_creer(CH50 ligne)
{
    /* indice : utiliser la fonction strtoul() pour convertir une chaîne de
     * caractères en nombre entier non-signé.
     * Exemple d'utilisation :
     * unsigned nb;
     * // ...
     * nb = strtoul(chaine_a_convertir,NULL,10);
     *
     *  => chaine_a_convertir est la chaîne de caractère qui contient le nombre
     *     sous forme caractères
     *  => NULL indique une adresse « vide » (laisser tel quel)
     *  => 10 indique qu'on veut lire un nombre en base 10.
     *     NOTE: On pourrait écrire 0 à la place de 10, ce qui signifie «
     *     détermine la base tout seul ». Voir la doc de strotoul pour savoir
     *     comment s'en servir.
     */

//  XXX Si vous voulez juste tester le reste de votre programme, vous pouvez initialiser p
//  XXX avec des valeurs « en dur » directement.
    Personne p;
//  retirer cette ligne une fois que vous avez commencé à écrire le code de cette fonction.
    A_FAIRE();
    return p;
}

void personne_afficher(Personne p)
{
//  retirer cette ligne une fois que vous avez commencé à écrire le code de cette fonction.
    A_FAIRE();
}
