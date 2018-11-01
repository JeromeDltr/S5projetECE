#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <time.h>
#include <windows.h>
#include "Personnage.h"
#include "Vieautonome.h"
#include "Plateau.h"
#include"Menu.h"



int main()
{
    // DECLARATION DES VARIABLES
    //Variables liées à la création du tableau
    int largeurTab=50;
    int longueurTab=20;
    int tab[20][50]= {0};
//Variable lié au menu
    int i=0;

//Variables liées au score
    int score=0;

//Variable de temps
    int temps=50;
//Variable de boucle infinie
    char keys='a';

//Creation des variables personnage
    Pcman pcm;
    Pcman ennemi[4];
    Objet diamants[5];

    srand(time(NULL));
    PremierEcran();
    menuOption();
    afficherFleche(i);

    while (keys!='n')
    {
        if(kbhit())
        {
            keys=getch();
            switch(keys)
            {
            case 'z':
                i -=2;
                bougerMenu(i);
                break;
            case 's':
                i +=2;
                bougerMenu(i);
                break;
            case 'e':
                if (i%6 == 0)
                {
                    rules();
                    menuOption();
                    afficherFleche(i);
                }
                if (i%6 == 2)
                {
                    ctrlSpeed(&temps);
                    menuOption();
                }
                if (i%6 == 4)
                {
                    lvl1(keys, temps, score,&pcm,&ennemi[4],&diamants[5],&tab,largeurTab,longueurTab);
                }
            }
        }

    }

    return 0;
}
