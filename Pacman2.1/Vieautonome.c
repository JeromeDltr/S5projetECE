
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"
#include <windows.h>
#include <time.h>
#include "Plateau.h"
#include "Personnage.h"

int MinTab(double tab[4], int tailleTab)
{
   int i;
   double min;
   int minIndice=0;
   min=tab[0];

   for(i=0;i<tailleTab;i++)
   {
       if (min>tab[i])
       {
           min=tab[i];
           minIndice=i;

       }
   }
   return minIndice;
}

void changementDirEnnemie(Pcman *ennemi)
{
    char tabd[4];
    int i;
    tabd[0]='s';
    tabd[1]='d';
    tabd[2]='q';
    tabd[3]='z';
    i=rand()%4;
    (*ennemi).direction=tabd[i];
}
void changementDirIntelligente(Pcman *pcm, Pcman *ennemi)
{
    double tabDistance[4];
    char tabd[4];

    tabd[0]='d';
    tabd[1]='q';
    tabd[2]='s';
    tabd[3]='z';

    tabDistance[0]= sqrt(pow((*pcm).coordonneX - ((*ennemi).coordonneX + 1),2) + pow((*pcm).coordonneY - ((*ennemi).coordonneY),2));
    tabDistance[1]= sqrt(pow((*pcm).coordonneX - ((*ennemi).coordonneX - 1),2) + pow((*pcm).coordonneY - ((*ennemi).coordonneY),2));
    tabDistance[2]= sqrt(pow((*pcm).coordonneX - ((*ennemi).coordonneX),2) + pow((*pcm).coordonneY - ((*ennemi).coordonneY + 1),2));
    tabDistance[3]= sqrt(pow((*pcm).coordonneX - ((*ennemi).coordonneX),2) + pow((*pcm).coordonneY - ((*ennemi).coordonneY - 1),2));

    (*ennemi).direction=tabd[MinTab(tabDistance,4)];
}

void ConditionChangementDir(Pcman *ennemi,Pcman *pcm)
{
    if ((*ennemi).compteurmvt ==5)
    {
        if ((*ennemi).IAON=='1')
        {
            changementDirIntelligente(pcm,ennemi);
            (*ennemi).compteurmvt=0;
        }
        else
        {
            changementDirEnnemie(ennemi);
            (*ennemi).compteurmvt=0;
        }
    }
}

void VieAutonome(Pcman *pcm, Objet diamants[5],int *score, int tab[20][50], Pcman ennemi[4])
{
    int i = 0;
        while(i<((*pcm).vitesse))
        {
            AffichageBlanc(pcm);
            Deplacement(pcm);
            if (tab[(*pcm).coordonneY][(*pcm).coordonneX]=='1')
            {
                Blocage(pcm);
                AffichagePacman(pcm);
            }

            else
            {
                boucleToucherCouler(pcm,ennemi);
                *score=CompteurScore(score,pcm,diamants);
                AffichageScore(score);
                AffichagePointDeVie(pcm);
                AffichagePacman(pcm);
            }
            i++;
        }


}

void VieAutonomeEnnemie(Pcman *ennemi, int tab[20][50], Objet diamants[5],Pcman *pcm)
{
        int i=0;
       while (i<(*ennemi).vitesse)
       {
         ConditionChangementDir(ennemi, pcm);
         AffichageBlanc(ennemi);
         LesFantomesNeMangesPas(ennemi, diamants);
         Deplacement(ennemi);

         if (tab[(*ennemi).coordonneY][(*ennemi).coordonneX]=='1')
        {
            (*ennemi).compteurmvt+=1;
            Rebond(ennemi);
            AffichagePacman(ennemi);
        }
         else
        {
             ToucherCouler(pcm,ennemi);
            (*ennemi).compteurmvt+=1;
            AffichagePacman(ennemi);
        }
         i++;
       }


}

