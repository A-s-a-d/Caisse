#include "chiffrement.h"
#include "definitions.h"


int CLE = CLE_DEFAUT;

void crypto_initialiser_cle(int cle)
{
    CLE = cle;
}

void crypto_chiffrer()
{

    char LIGNE[50];
    while (fgets(LIGNE, sizeof(LIGNE), CLIENTS))
    {
        for(int i=0;i<strlen(LIGNE);i++)
        {
            if (strlen(LIGNE) == 1 || isspace(LIGNE[0]))
            {
                continue;
            }

            if (!isalpha(LIGNE[i]))
                LIGNE[i] = ((LIGNE[i] - '0' )+ CLE) % 10 + '0';
                continue;
            // checking for upper case
            if(isupper(LIGNE[i]))
                LIGNE[i]=((LIGNE[i]-'A') + CLE) % 26 + 'A';
            else
                //checking for lower case
                if(islower(LIGNE[i]))
                {
                    LIGNE[i]=((LIGNE[i]-'a') + CLE) % 26 + 'a';
                }

/*----------------------------------*/
        }

    }
    recreer_fichier();
    fermer_fichier();

}

void crypto_dechiffrer(CH50 chaine)
{


}


