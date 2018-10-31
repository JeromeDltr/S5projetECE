#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <time.h>
#include <windows.h>
#include "Personnage.h"
#include "Vieautonome.h"
#include "Plateau.h"



int main()
{
  // DECLARATION DES VARIABLES
  //Variables liées à la création du tableau
  int largeurTab=50;
  int longueurTab=20;
  int tab[20][50]={0};



 //Variables liées au score
  int score=0;

//Variable de temps
  long temps=300;
//Variable de boucle infinie
  char key='a';

//Creation des variables personnage
  Pcman pcm;
  Pcman ennemi[3];
  Objet diamants[5];

  srand(time(NULL));

  InitialisationPerso(&pcm,diamants,ennemi); //Initialise les
  CreationContour(largeurTab,longueurTab,tab);// Creation du niveau
  GenerationAleatoireDePcman(&pcm);
  AffichagePacman(&pcm);
  GenerationAleatoireDeDiamants(largeurTab,longueurTab,diamants);

  while (key!='n')
    {
        Sleep(temps);
        VieAutonome(&pcm, diamants,&score,tab);

        VieAutonomeEnnemie(&ennemi[0],tab,diamants);
        VieAutonomeEnnemie(&ennemi[1],tab,diamants);
        VieAutonomeEnnemie(&ennemi[2],tab,diamants);
        MORT(&pcm,ennemi);

        if(kbhit())
        {
            key=getch();
            switch(key)
            {
                case 'd':
                    pcm.direction='d';
                    break;
                case 'q':
                    pcm.direction='q';
                    break;
                case 'z':
                    pcm.direction='z';
                    break;
                case 's':
                    pcm.direction='s';
                    break;
                case 'n':
                    printf("a bientôt");
            }
        }

    }
}
