#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <time.h>
#include <windows.h>
#include "Personnage.h"
#include "Vieautonome.h"
#include "Plateau.h"




  // DECLARATION DES VARIABLES
  //Variables liées à la création du tableau
  int largeurTab=50;
  int longueurTab=20;
  int tab[20][50]={0};



 //Variables liées au score
  int score=0;

//Variable de temps
  int temps=250;
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

void rules()//explication des règles
{
    printf("Le PACMAN est un jeu classique dans lequel un personnage se déplace \n dans un espace plus ou moins complexe pour manger des diamants. \nIl peut aller dans 4 directions à l’aide du clavier et doit éviter de se faire \nattraper par des fantômes qui sillonnent l’espace de jeu.\n Les touches de déplacement sont 2,4,6,8.");
}
void ctrlSpeed()//Sert à définir la vitesse du jeu
{
    int answer;
    printf("Selectionner une vitesse de jeu entre 1 (lent),2 et 3(rapide)");
    scanf("%d",&answer);
    switch(answer)
    {
    case '1':
        temps = 250;
        break;
    case '2':
        temps = 150;
        break;
    case '3':
        temps = 50;
        break;
    default :
        ctrlSpeed();
    }

}
void startNew()
{


}
void lvl1()
{

    while (key!='n')
    {
        Sleep(temps);
        if (CompteurScore(score, pcm, diamants) == 50)
        {
            lvl2();
        }
        VieAutonome(&pcm, diamants,&score,tab);
        MORT(&pcm,ennemi);
        if(kbhit())
        {
            key=getch();
            switch(key)
            {
            case '6':
                pcm.direction='d';
                break;
            case '4':
                pcm.direction='q';
                break;
            case '8':
                pcm.direction='z';
                break;
            case '2':
                pcm.direction='s';
                break;
            case 'q':
                menu();
                break;
            case 'p':
                printf("Appuyer sur n'importe quelle touche pour reprendre.");
                getchar();
                break;
            }
        }

        else if ((pcm.compteurmvt==20) && (Pomme==1))
        {
            GenerationAleatoireObjet(largeurTab,longueurTab,&point,tab);
            pcm.compteurmvt=0;
            Pomme=0;
        }
    }
}
void lvl2()
{
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
void bordure()
{
    int i,j;
    for (i=0,i<longueurTab,i++)
    {
        for (j=0,j<largeurTab,j++)
        {
            if (tab[i][j] == '1')
            {
                tab[i][j] = // A compléter
            }
        }
    }
}
void menu()
{
    //Initialisation des variables
    int i = 0;
    char keys ;
    //Traitement et affichage
    if(kbhit())
    {
        keys=getch();
        switch(keys)
        {
            {

            case 'z':
                i = i-1;
                break;
            case 's':
                i = i+1;
                break;
            case 'Space':
                if (i%6 == 0)
                {
                    rules();
                }
                if (i%6 == 1)
                {
                    ctrlSpeed();
                }
                if (i%6 == 2)
                {
                    bordure();
                }
                if (i%6 == 3)
                {
                    startNew();
                }
                if (i%6 == 4)
                {
                    resume();
                }
                if (i%6 == 5);
                {
                    quit();
                }
            default:
                menu();
            }
        }

    }
