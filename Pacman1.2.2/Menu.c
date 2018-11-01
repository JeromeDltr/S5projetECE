#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <time.h>
#include <windows.h>
#include "Personnage.h"
#include "Vieautonome.h"
#include "Plateau.h"

int modulo(int x,int N)
{
    return (x % N + N) %N;
}
void rules()//explication des règles
{
    char keys='b';
    system("cls");
    printf("Le PACMAN est un jeu classique dans lequel un personnage se deplace \ndans un espace plus ou moins complexe pour manger des diamants. \nIl peut aller dans 4 directions a l aide du clavier et doit eviter de se faire \nattraper par des fantomes qui sillonnent l espace de jeu.\nLes touches de deplacement sont z,q,s,d.");
    printf("\nAppuyer sur n pour continuer");
    while (keys!='n')
    {
        if(kbhit())
        {
            keys=getch();
        }
    }
}
void ctrlSpeed(unsigned long int *temps)//Sert à définir la vitesse du jeu
{
    int j = 0;
    char keys='b';
    char answer='b';
    system("cls");
    gotoligcol(0,2);
    printf("1 (lent)");
    gotoligcol(2,2);
    printf("2 (modere)");
    gotoligcol(4,2);
    printf("3 (rapide)");
    printf("\nSelectionner une vitesse de jeu");
    afficherFleche(j);

    while (keys!='m')
    {
        if(kbhit())
        {
            answer=getch();
            switch (answer)
            {
            case 'z':
                j -=2;
                printf("%d",j);
                bougerSpeed(*temps,j);
                break;
            case 's':
                j +=2;
                bougerSpeed(*temps,j);
                break;
            case 'e':
                if (j%6 == 0)
                {
                    *temps = 250;
                }
                if (j%6 == 2)
                {
                    *temps = 150;
                }
                if (j%6 == 4)
                {
                    *temps = 50;
                }
                keys = 'm';
                break;
            }
        }

    }


}

void PremierEcran()
{
    char keys='b';
    gotoligcol(1,5);
    printf("PACMAN");
    gotoligcol(3,2);
    printf("Par: Maxence, Remi et Jerome");
    gotoligcol(6,2);
    printf("Appuyer sur n pour continuer");

    while (keys!='n')
    {
        if(kbhit())
        {
            keys=getch();
        }

    }
}
void menuOption()
{
    system("cls");
    gotoligcol(0,2);
    printf("1. rules\n");
    gotoligcol(2,2);
    printf("2. reglage de la vitesse\n");
    gotoligcol(4,2);
    printf("3. Nouvelle Partie\n");
    gotoligcol(10,2);
    printf("Appuyer sur e pour valider");
}

void afficherFleche(int i)
{
    gotoligcol(i,0);
    printf("->");
}
void bougerMenu(int i)
{
    menuOption();
    afficherFleche((modulo(i,6)));
}

void bougerSpeed(unsigned long int *temps,int j)
{
    ctrlSpeed(&temps);
    afficherFleche(modulo(j,6));
}









void lvl1(char *key, int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50], int largeurTab,int longueurTab)
{
    system("cls");
    InitialisationPerso(pcm);
    initialisationObjet(diamants); //Initialise les
    CreationContour(largeurTab,longueurTab,tab);// Creation du niveau
    GenerationAleatoireDePcman(pcm);
    AffichagePacman(pcm);
    GenerationAleatoireDeDiamants(largeurTab,longueurTab,diamants);
    while (*key!='n')
    {
        Sleep(*temps);
        VieAutonome(pcm, diamants,score,tab);
        if(kbhit())
        {
            {
                *key=getch();
                switch(*key)
                {
                case 'd':
                    (*pcm).direction='d';
                    break;
                case 'q':
                    (*pcm).direction='q';
                    break;
                case 'z':
                    (*pcm).direction='z';
                    break;
                case 's':
                    (*pcm).direction='s';
                    break;
                case 'v':
                    system("cls");
                    menuOption();
                    break;
                case 'p':
                    printf("Appuyer sur n'importe quelle touche pour reprendre.");
                    getchar();
                    break;
                }
            }
        }
    }
}

void lvl2(char *key, int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50], int largeurTab,int longueurTab)
{
    system("cls");
    InitialisationPerso(pcm);
    initialisationObjet(diamants);
    initialisationEnnemi(ennemi); //Initialise les
    CreationContour(largeurTab,longueurTab,tab);
    // Creation du niveau
    GenerationAleatoireDePcman(pcm);
    GenerationAleatoireDePcman(&ennemi[0]);
    GenerationAleatoireDePcman(&ennemi[1]);
    GenerationAleatoireDePcman(&ennemi[2]);
    GenerationAleatoireDePcman(&ennemi[3]);

    AffichagePacman(pcm);
    GenerationAleatoireDeDiamants(largeurTab,longueurTab,diamants);
    while (*key!='n')
    {
        Sleep(*temps);
        VieAutonome(pcm, diamants,score,tab);
        VieAutonomeEnnemie(&ennemi[0],tab,diamants,pcm);
        VieAutonomeEnnemie(&ennemi[1],tab,diamants,pcm);
        VieAutonomeEnnemie(&ennemi[2],tab,diamants,pcm);
        VieAutonomeEnnemie(&ennemi[3],tab,diamants,pcm);
        MORT(pcm,ennemi);

        if(kbhit())
        {
            *key=getch();
            switch(*key)
            {
            case 'd':
                (*pcm).direction='d';
                break;
            case 'q':
                (*pcm).direction='q';
                break;
            case 'z':
                (*pcm).direction='z';
                break;
            case 's':
                (*pcm).direction='s';
                break;
            case 'n':
                printf("a bientôt");
            }
        }

    }
}
void lvl3(char *key, int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50], int largeurTab,int longueurTab)
{
    system("cls");
    InitialisationPerso(pcm);
    initialisationObjet(diamants);
    initialisationEnnemi(ennemi);
    //Initialise les
    CreationContour(largeurTab,longueurTab,tab);

    InitialisationEnnemiIA(ennemi);// Creation du niveau
    GenerationAleatoireDePcman(pcm);
    GenerationAleatoireDePcman(&ennemi[0]);
    GenerationAleatoireDePcman(&ennemi[1]);
    GenerationAleatoireDePcman(&ennemi[2]);
    GenerationAleatoireDePcman(&ennemi[3]);

    AffichagePacman(pcm);
    GenerationAleatoireDeDiamants(largeurTab,longueurTab,diamants);

    while (*key!='n')
    {
        Sleep(*temps);
        VieAutonome(pcm, diamants,score,tab);
        VieAutonomeEnnemie(&ennemi[0],tab,diamants,pcm);
        VieAutonomeEnnemie(&ennemi[1],tab,diamants,pcm);
        VieAutonomeEnnemie(&ennemi[2],tab,diamants,pcm);
        VieAutonomeEnnemie(&ennemi[3],tab,diamants,pcm);
        MORT(pcm,ennemi);

        if(kbhit())
        {
            *key=getch();
            switch(*key)
            {
            case 'd':
                (*pcm).direction='d';
                break;
            case 'q':
                (*pcm).direction='q';
                break;
            case 'z':
                (*pcm).direction='z';
                break;
            case 's':
                (*pcm).direction='s';
                break;
            case 'n':
                printf("a bientôt");
            }
        }

    }
}


/*
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
    */
