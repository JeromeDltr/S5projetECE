#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <time.h>
#include <windows.h>
#include "conio.h"
#include "ListeFonctions.h"

void afficherFleche(int indiceFleche)
{

    gotoligcol(indiceFleche+3,18);
    printf("->");
}

void pacmanAffichage()
{
    /*for(int i = 0; i<255; i++)
    {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
    printf("Text Color %d\n", i);
    }*/

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

    printf("         _______  _______  _______  _______  _______  _       \n");
    printf("        (  ____ )(  ___  )(  ____ \\(       )(  ___  )( (    /|\n");
    printf("        | (    )|| (   ) || (    \\/| () () || (   ) ||  \\  ( |\n");
    printf("        | (____)|| (___) || |      | || || || (___) ||   \\ | |\n");
    printf("        |  _____)|  ___  || |      | |(_)| ||  ___  || (\\ \\) |\n");
    printf("        | (      | (   ) || |      | |   | || (   ) || | \\   |\n");
    printf("        | )      | )   ( || (____/\\| )   ( || )   ( || )  \\  |\n");
    printf("        |/       |/     \\|(_______/|/     \\||/     \\||/    )_| ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}


void PremierEcran()
{
    char keys='a';
    pacmanAffichage();
    gotoligcol(10,20);
    printf("Par : ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    printf("Maxence, Remi et Jerome");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoligcol(15,20);
    printf("Appuyer pour continuer");

    keys=getch();
}
void regles()//explication des règles
{
    char keys='b';
    system("cls");
    printf("\n\n\n\t\tLe PACMAN est un jeu classique dans lequel un personnage se deplace \n\n\t\tdans un espace plus ou moins complexe pour manger des diamants. \n\n\n\t\t");
    printf("Il peut aller dans 4 directions a l\'aide du clavier et doit eviter de se faire \n\n\t\tattraper par des fantomes qui sillonnent l\'espace de jeu.\n\n\n\t\tLes touches de deplacement sont ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("z,q,s,d.");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("\n\n\n\t\t\tAppuyer pour continuer");

    keys=getch();
}
void menuOption()
{
    system("cls");
    gotoligcol(3,6);
    printf("\t\t\t1. rules\n\n\t\t\t2. reglage de la vitesse\n");
    printf("\n\t\t\t3. Nouvelle Partie\n\n\t\t\t4. Reprendre Partie\n\n\t\t\t5. Bordure\n\n\t\t\t6. Quitter\n\n\n\t\tAppuyer sur e pour valider");
}
void bougerMenu(int indiceFleche)
{
    menuOption();
    afficherFleche((modulo(indiceFleche,12)));
}

void ctrlVitesse()//Sert à définir la vitesse du jeu
{
    system("cls");
    gotoligcol(3,6);
    printf("\t\t\t  Lent \n\n\t\t\t Modere \n");
    printf("\n\t\t\t Rapide\n\n\n\t\tAppuyer sur e pour valider");
}

void modifVitesse(unsigned long int *temps, int indiceFleche)//Pour afficher la vitesse choisi dans le menu "vitesse"
{
    ctrlVitesse();
    afficherFleche(modulo(indiceFleche,6));
}

void choixVitesse(unsigned long int *temps, int indiceFleche)//pour choisir la vitesse du jeu
{
    char keys='b';
    char answer='b';
    afficherFleche(indiceFleche);
    while (keys!='m')
    {
        if(kbhit())
        {
            answer=getch();
            switch (answer)
            {
            case 'z':
                indiceFleche -= 2;
                modifVitesse(&temps,indiceFleche);
                break;
            case 's':
                indiceFleche += 2;
                modifVitesse(&temps,indiceFleche);
                break;
            case 'e':
                if (modulo(indiceFleche,6)==0)
                {
                    *temps = 200;
                    keys = 'm';
                }
                if (modulo(indiceFleche,6)==2)
                {
                    *temps = 150;
                    keys = 'm';
                }
                if (modulo(indiceFleche,6)== 4)
                {
                    *temps = 75;
                    keys ='m';
                }

            }
        }
    }
}


void lvl3(char *key, unsigned long int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50])
{
    system("cls");
    InitialisationPerso(pcm);
    InitialisationObjet(diamants);
    initialisationEnnemi(ennemi);
    //Initialise les
    CreationContour(tab);
    GenerationNiveauAlea(tab);
    InitialisationEnnemiIA(ennemi);// Creation du niveau
    InitialisationVitesseON(pcm, ennemi);
    GenerationAleatoireDePcman(pcm);
    GenerationAleatoireDePcman(&ennemi[0]);
    GenerationAleatoireDePcman(&ennemi[1]);
    GenerationAleatoireDePcman(&ennemi[2]);
    GenerationAleatoireDePcman(&ennemi[3]);

    AffichagePacman(pcm);
    GenerationAleatoireDeDiamants(diamants);

    while (*key!='n')
    {
        Sleep(*temps);
        VieAutonome(pcm, diamants,score,tab,ennemi);
        VieAutonomeEnnemie(&ennemi[0],tab,diamants,pcm);
        VieAutonomeEnnemie(&ennemi[1],tab,diamants,pcm);
        VieAutonomeEnnemie(&ennemi[2],tab,diamants,pcm);
        VieAutonomeEnnemie(&ennemi[3],tab,diamants,pcm);
        TestDefaite(pcm,key);
        ChangementDirPacman(pcm,key);
    }
}

void lvl2(char *key, unsigned long int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50])
{
    system("cls");
    InitialisationPerso(pcm);
    InitialisationObjet(diamants);
    initialisationEnnemi(ennemi); //Initialise les
    CreationContour(tab);
    // Creation du niveau
    GenerationAleatoireDePcman(pcm);
    GenerationAleatoireDePcman(&ennemi[0]);
    GenerationAleatoireDePcman(&ennemi[1]);
    GenerationAleatoireDePcman(&ennemi[2]);
    GenerationAleatoireDePcman(&ennemi[3]);

    AffichagePacman(pcm);
    GenerationAleatoireDeDiamants(diamants);
    while (*key!='n')
    {
        Sleep(*temps);
        VieAutonome(pcm, diamants,score,tab,ennemi);
        VieAutonomeEnnemie(&ennemi[0],tab,diamants,pcm);
        VieAutonomeEnnemie(&ennemi[1],tab,diamants,pcm);
        VieAutonomeEnnemie(&ennemi[2],tab,diamants,pcm);
        VieAutonomeEnnemie(&ennemi[3],tab,diamants,pcm);

        TestDefaite(pcm,key);
        ChangementDirPacman(pcm,key);
        if (*score==100)
        {
            system("cls");
            lvl3(key, temps, score,pcm, ennemi, diamants,tab);
        }
    }
}


void lvl1(char *key, unsigned long int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50])
{

    system("cls");
    InitialisationPerso(pcm);
    InitialisationObjet(diamants); //Initialise les
    CreationContour(tab);// Creation du niveau
    GenerationAleatoireDePcman(pcm);
    AffichagePacman(pcm);
    GenerationAleatoireDeDiamants(diamants);
    while (*key!='n')
    {
        Sleep(*temps);
        VieAutonome(pcm, diamants,score,tab,ennemi);
        ChangementDirPacman(pcm, key);
        if (*score==50)
        {
            system("cls");
            lvl2(key, temps, score,pcm, ennemi, diamants,tab);
        }
    }
}

