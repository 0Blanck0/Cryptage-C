#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Crypting(char *tableau, int tailleTableau, FILE* fichier){

    char crypTab[] = "azertyuiopmlkjhgfdsqwxcvbn!:;?.§ù*$^%µ£¨¤_-|";
    char verifTab[3];
    char caractere = NULL;

    int tailleCrypTab = strlen(crypTab);
    int simili = 0;
    int simili2 = 0;
    int boucle = 0;
    int boucle2 = 0;
    int alea = 0;
    int newPos = 0;

    do{

        srand(time(NULL));

        for(int i=0;i<tailleTableau;i++){
            alea = rand() % tailleCrypTab;
            tableau[i] = crypTab[alea];
        }

        rewind(fichier); //Curseur remis au début du fichier
        fseek(fichier, 5, SEEK_SET);

        do{

            simili = 0;
            caractere = fgetc(fichier);
            verifTab[boucle] = caractere;
            boucle++;
            boucle2++;
            printf("%c", caractere);

            if(boucle2 == 16){
                newPos = (ftell(fichier)) + 9;
                fseek(fichier, newPos, SEEK_SET);
                boucle2 = 0;
                boucle = 0;
            }

            if(boucle == 4){
                for(int i=0;i<4;i++){
                    if(tableau[i] == verifTab[i])
                        simili++;
                    }

                if(simili >= 3)
                    simili2++;

                newPos = (ftell(fichier)) + 7;
                fseek(fichier, newPos, SEEK_SET);
                boucle = 0;
            }

        }while(caractere != EOF);

    }while(simili2 > 1);
}
