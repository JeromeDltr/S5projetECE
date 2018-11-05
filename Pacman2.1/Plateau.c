#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <windows.h>
#include <time.h>
#include "ListeFonctions.h"



void CreationContour(int tab[20][50]) // Créer les contours du terrain
{
    int i;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 135);
    for (i=0; i<50; i++)
    {
        gotoligcol(0,i);
        tab[0][i]='1';

        printf("#");
    }
    for (i=0; i<50; i++)
    {
        gotoligcol(20,i);
        tab[20][i]='1';
        printf("#");
    }
    for (i=0; i<20; i++)
    {
        gotoligcol(i,0);
        tab[i][0]='1';
        printf("#");
    }
    for (i=0; i<20; i++)
    {
        gotoligcol(i,50-1);
        tab[i][50-1]='1';
        printf("#");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void GenerationNiveauAlea(int tab[20][50])  //Générer des murs globalements aléatoirement pour le niveau 3
{
    int i=2,j=2;
    int nombreMurX=30; // Initialisation arbitraire du nombre de mur qu'on vas poser en ligne
    int MurOuPasMur;   // Boolean, variable aléatoire qui vas décider avec 1/2 de poser un mur ou non
    int nombreMurY=20;   // Initialsation arbitraire du nombre de mur qu'on va poser en colonne
    // PS: les initialisations arbitraire corresponde au test effectué avec un résultat le plus satisfaisant

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 135);
    while(nombreMurX!=0)
    {
        MurOuPasMur=rand()%2; // Une chance sur deux de poser le mur sur cette colonne
        if (MurOuPasMur==0)
        {
            nombreMurX--;     // on décrémante ce nombre
            nombreMurY=20;    // on initialise le nombre de mur qu'on va poser sur cette colonne
            while(nombreMurY!=0)
            {
                MurOuPasMur=rand()%2;  // une chance sur deux de poser le
                if (MurOuPasMur==0)
                {
                    nombreMurY--;
                    tab[j][i]='2';
                    gotoligcol(j,i);
                    printf("#");
                }
                j+=4;
                j=j%18 +2;
            }
        }
        i+=1;
        i=i%48  ;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}


void GenerationAleatoireDeDiamants(Objet diamants[5]) // Place les diamants de manière aléatoires sur le plateau
{
    int i=0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    for (i=0; i<5; i++)
    {
        (diamants)[i].coordonneX=(rand()%(50-2)) +1;
        (diamants)[i].coordonneY=(rand()%(20-2)) +1;
        gotoligcol(((diamants)[i]).coordonneY,((diamants)[i]).coordonneX);

        printf("%c",((diamants)[i]).nom);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void GenerationAleatoireDePcman(Pcman *pcm)  //Place un personnage de manière aléatoire sur le terrain
{
    char tabd[4];
    int i;
    tabd[0]='s';
    tabd[1]='d';
    tabd[2]='q';
    tabd[3]='z';
    i=rand()%4;
    (*pcm).direction=tabd[i];
    (*pcm).coordonneX=(rand()%(50-2)) +1;
    (*pcm).coordonneY=(rand()%(20-2)) +1;
}


void AffichagePacman(Pcman *pcm)  //Affiche le Pacman
{
    gotoligcol((*pcm).coordonneY,(*pcm).coordonneX);
    if ((*pcm).couleur==0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
        printf("%c",(*pcm).nom);
        gotoligcol(25, 55);
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 64);
        printf("%c",(*pcm).nom);
        gotoligcol(25, 55);
    }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void AffichageBlanc(Pcman *pcm)  //Efface le Pacman
{
    gotoligcol((*pcm).coordonneY,(*pcm).coordonneX);
    printf(" ");
}

void AffichageScore(int *score) //Affiche le score
{
    gotoligcol(23,0);
    printf(" Le score est de");
    printf(ANSI_COLOR_RED " %d",*score);
    printf(ANSI_COLOR_RESET"");
}

void AffichagePointDeVie(Pcman *pcm)  // Affiche les points de vie
{
    gotoligcol(21,0);
    printf(" Il te reste ");
    printf(ANSI_COLOR_MAGENTA "%d ",(*pcm).pointDeVie);
    printf(ANSI_COLOR_RESET"point de vie");
}



