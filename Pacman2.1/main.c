#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <time.h>
#include <windows.h>
#include "ListeFonctions.h"

int main()
{
    // DECLARATION DES VARIABLES
    //Variables liées à la création du tableau
    int largeurTab=50;
    int longueurTab=20;
    int tab[20][50]= {0};
//Variable lié au menu
    int indiceFleche=0;

//Variables liées au score
    int score=0;

//Variable de temps
    unsigned long temps=100;
//Variable de boucle infinie
    char key='a';

//Creation des variables personnages
    Pcman pcm;
    Pcman ennemi[4];
    Objet diamants[5];

    srand(time(NULL));
    PremierEcran();
    menuOption();
    afficherFleche(indiceFleche);

    while (key!='v')
    {
        if(kbhit())
        {
            key=getch();
            switch(key)
            {
            case 'z':
                indiceFleche -=2;
                bougerMenu(indiceFleche);
                break;
            case 's':
                indiceFleche +=2;
                bougerMenu(indiceFleche);
                break;
            case 'e':
                if (indiceFleche%12 == 0)
                {
                    regles();
                    menuOption();
                    afficherFleche(indiceFleche);
                }
                if (indiceFleche%12 == 2)
                {
                    ctrlVitesse();
                    choixVitesse(&temps,0);
                    menuOption();
                    afficherFleche(indiceFleche);
                }
                if (indiceFleche%12 == 4)
                {
                    lvl1(&key, &temps, &score,&pcm, ennemi, diamants,tab);
                    Reinitialisation(&pcm,ennemi,diamants,tab,&score,&key);
                    menuOption();
                    afficherFleche(0);
                    indiceFleche=0;
                }
                if (indiceFleche%12 == 6)
                {
                    //Reprendre
                }
                if (indiceFleche%12 == 8)
                {
                    //bordure
                }
                if (indiceFleche%12 == 10)
                {
                    key ='v';
                }

            }
        }

    }

    return 0;
}
