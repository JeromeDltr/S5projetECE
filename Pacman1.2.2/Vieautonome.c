
#include <stdio.h>
#include <stdlib.h>
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

void VieAutonome(Pcman *pcm, Objet diamants[5],int *score, int tab[20][50])
{
   if ((*pcm).direction=='d')
   {
       AffichageBlanc(pcm);
       AvancementX(pcm);

       if (tab[(*pcm).coordonneY][(*pcm).coordonneX]=='1')
        {
            RetourX(pcm);
            AffichagePacman(pcm);
        }

       else
        {
            *score=CompteurScore(score,pcm,diamants);
            AffichageScore(score);
            AffichagePointDeVie(pcm);
            AffichagePacman(pcm);
        }
   }

   if ((*pcm).direction=='s')
   {
         AffichageBlanc(pcm);
         ReculY(pcm);

         if (tab[(*pcm).coordonneY][(*pcm).coordonneX]=='1')
        {
            RetourY(pcm);
            AffichagePacman(pcm);
        }

         else
        {
            *score=CompteurScore(score,pcm,diamants);
            AffichageScore(score);
            AffichagePointDeVie(pcm);
            AffichagePacman(pcm);
        }
   }

   if ((*pcm).direction=='z')
   {
         AffichageBlanc(pcm);
         AvancementY(pcm);

        if (tab[(*pcm).coordonneY][(*pcm).coordonneX]=='1')
        {
            RetourYH(pcm);
            AffichagePacman(pcm);
        }

         else
        {
            *score=CompteurScore(score,pcm,diamants);
            AffichageScore(score);
            AffichagePointDeVie(pcm);
            AffichagePacman(pcm);
        }
   }

   if ((*pcm).direction=='q')
   {
         AffichageBlanc(pcm);
         ReculX(pcm);

         if (tab[(*pcm).coordonneY][(*pcm).coordonneX]=='1')
        {
            RetourXG(pcm);
            AffichagePacman(pcm);
        }

         else
        {
            *score=CompteurScore(score,pcm,diamants);
            AffichageScore(score);
            AffichagePointDeVie(pcm);
            AffichagePacman(pcm);
        }
   }
}
void VieAutonomeEnnemie(Pcman *ennemi, int tab[20][50], Objet diamants[5],Pcman *pcm)
{
   if ((*ennemi).direction=='d')
   {
         AffichageBlanc(ennemi);
         LesFantomesNeMangesPas(ennemi, diamants);
         AvancementX(ennemi);

         if (tab[(*ennemi).coordonneY][(*ennemi).coordonneX]=='1')
        {
            (*ennemi).compteurmvt+=1;
            ConditionChangementDir(ennemi, pcm);
            RetourX(ennemi);
            AffichagePacman(ennemi);

        }
         else
        {

            (*ennemi).compteurmvt+=1;
            AffichagePacman(ennemi);
            ConditionChangementDir(ennemi, pcm);
        }
   }

   if ((*ennemi).direction=='s')
   {
        AffichageBlanc(ennemi);
        LesFantomesNeMangesPas(ennemi, diamants);
        ReculY(ennemi);

        if (tab[(*ennemi).coordonneY][(*ennemi).coordonneX]=='1')
        {
            (*ennemi).compteurmvt+=1;
            ConditionChangementDir(ennemi, pcm);
            RetourY(ennemi);
            AffichagePacman(ennemi);

        }
        else
        {

            (*ennemi).compteurmvt+=1;
            AffichagePacman(ennemi);
            ConditionChangementDir(ennemi, pcm);
        }
   }
   if ((*ennemi).direction=='z')
   {
        AffichageBlanc(ennemi);
        LesFantomesNeMangesPas(ennemi, diamants);
        AvancementY(ennemi);

        if (tab[(*ennemi).coordonneY][(*ennemi).coordonneX]=='1')
        {
            (*ennemi).compteurmvt+=1;
            ConditionChangementDir(ennemi, pcm);
            RetourYH(ennemi);
            AffichagePacman(ennemi);

        }
        else
        {

            (*ennemi).compteurmvt+=1;
            AffichagePacman(ennemi);
            ConditionChangementDir(ennemi, pcm);
        }
   }

   if ((*ennemi).direction=='q')
   {
      AffichageBlanc(ennemi);
      LesFantomesNeMangesPas(ennemi, diamants);
      ReculX(ennemi);


      if (tab[(*ennemi).coordonneY][(*ennemi).coordonneX]=='1')
        {
            (*ennemi).compteurmvt+=1;
            ConditionChangementDir(ennemi, pcm);
            RetourXG(ennemi);
            AffichageBlanc(ennemi);
            AffichagePacman(ennemi);

        }

      else
        {

            AffichagePacman(ennemi);
            (*ennemi).compteurmvt+=1;
            ConditionChangementDir(ennemi, pcm);
        }
   }
}


