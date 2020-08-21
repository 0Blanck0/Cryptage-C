#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main(int argc, char *argv[])
{

    printf("Debut du programme\n");

    //Definition de la taille du tableau
    const int longTab = 16;

    int verifRegistre = false; //Definition du bool de verification registre
    int continu = false;
    int posCurs = NULL; //Definition de la position du curseur fichier
    int newPos = NULL; //Definition de la nouvelle position du curseur

    char tableau[longTab]; //Definition du tableau
    char caractere = NULL; //Definition du caractere entrer dans la console
    char caractereActuel = NULL; //Definition de la variable d'observation des caracteres deja present.
    char cont = NULL;

    FILE* fichier = NULL; //Definition du fichier afin de le lire

    fichier = fopen("CripTest.txt", "a+"); //Ouverture du fichier txt

    //verification de l'existance du fichier
    if(fichier != NULL){
        printf("Crypto Programme pret\n");
    }
    else{
        fichier = fopen("CripTest.txt", "w+");

        if(fichier == NULL){
            printf("\n\n---ERROR---\n\n");
            return EXIT_FAILURE;
        }
        else{
            printf("Crypto Programme pret\n");
        }
    }

        //Saisi du caractere a enregistrer
        printf("\n\nQuelle caractere enregistrer ?\n");
        scanf("%c", &caractere);

        rewind(fichier); //Curseur remis au début du fichier
        posCurs = ftell(fichier); //Enregistrement de la position du curseur

        //Verification de l'existance du caractere dans le fichier txt
        do{
            newPos = (ftell(fichier)) + 46;
            caractereActuel = fgetc(fichier);
            fseek(fichier, newPos, SEEK_SET);

            if(caractereActuel == caractere)
                verifRegistre = true;
        }while(caractereActuel != EOF);

        if(verifRegistre == true){
            printf("\nCaractere deja enregistrer...");
        }
        else{ //Si le caractere n'est pas present l'enregistrament debute
            fseek(fichier, 0, SEEK_END); //possitionne le curseur a la fin du fichier
            fprintf(fichier, "%c => ", caractere);

            //Chiffrement du caractere
            Crypting(tableau, longTab, fichier);

            for(int i=0;i<longTab;i++){
                fprintf(fichier, "%c", tableau[i]);
                if(i==3 || i==7 || i==11){
                    fprintf(fichier, "\n     ");
                }
            }
            fprintf(fichier, "\n\n");
        }

    fclose(fichier); //fermeture du ficheir txt
    return EXIT_SUCCESS; //Fin programme
}
