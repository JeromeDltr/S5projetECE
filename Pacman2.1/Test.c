#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <windows.h>
#include <time.h>
#include "ListeFonctions.h"

void Clignotement(Pcman *pcm)
{
    int i=0;
    for (i=0;i<10;i++)
    {

         AffichageBlanc(pcm);
         Sleep(2);
         AffichagePacman(pcm);

    }

}

void ToucherCouler(Pcman *pcm,Pcman *ennemi)  //  Test si un ennemi à touché le pacman
{

        if (((*ennemi).coordonneY==(*pcm).coordonneY) && ((*ennemi).coordonneX==(*pcm).coordonneX))
        {
            (*pcm).pointDeVie-=1;
            Clignotement(pcm);
        }
}
void boucleToucherCouler(Pcman *pcm, Pcman ennemi[4]) // Test la colission sur tout les ennemis
{
    int i = 0;
    for (i=0;i<4;i++)
    {
        ToucherCouler(pcm,&ennemi[i]);
    }
}
void LesFantomesNeMangesPas(Pcman *ennemi, Objet diamants[5])  // Empeche les fantomes de manger des diamants
{
    int i=0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    for (i=0; i<5; i++)
    {
        if (((*ennemi).coordonneY==(diamants[i]).coordonneY) && ((*ennemi).coordonneX==(diamants[i]).coordonneX))
        {
            gotoligcol((*ennemi).coordonneY,(*ennemi).coordonneX);
            printf("*");
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
int CompteurScore(int *score, Pcman *pcm, Objet diamants[5])  // Mets à jours le score
{
    int i=0;

    for (i=0; i<5; i++)
    {
        if (((*pcm).coordonneY==(diamants[i]).coordonneY) && ((*pcm).coordonneX==(diamants[i]).coordonneX))
        {
            (diamants[i]).coordonneY=0;
            (diamants[i]).coordonneX=0;
            *score+=10;

            AugmentationVitesse(pcm);
        }
    }

    return *score;
}

void TestDefaite(Pcman *pcm, char *key)
{
    if ((*pcm).pointDeVie<1)
        {
            system("cls");
            *key='n';
        }

}
void PerteDePointDeVie(Pcman *pcm)
{
    (*pcm).pointDeVie-=1;
    Clignotement(pcm);
}
