
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <windows.h>
#include <time.h>
#include "Plateau.h"
#include "Personnage.h"

void changementDirEnnemie(Pcman *pcm)
{
    char tabd[4];
    int i;
    tabd[0]='s';
    tabd[1]='d';
    tabd[2]='q';
    tabd[3]='z';
    i=rand()%4;
    (*pcm).direction=tabd[i];
}

void ConditionChangementDir(Pcman *pcm)
{
    if ((*pcm).compteurmvt ==10)
    {
        changementDirEnnemie(pcm);
        (*pcm).compteurmvt=0;
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
void VieAutonomeEnnemie(Pcman *pcm, int tab[20][50], Objet diamants[5])
{
   if ((*pcm).direction=='d')
   {
         AffichageBlanc(pcm);
         LesFantomesNeMangesPas(pcm, diamants);
         AvancementX(pcm);

         if (tab[(*pcm).coordonneY][(*pcm).coordonneX]=='1')
        {
            RetourX(pcm);
            AffichagePacman(pcm);
            (*pcm).compteurmvt+=1;
            ConditionChangementDir(pcm);
        }
         else
        {

            (*pcm).compteurmvt+=1;
            AffichagePacman(pcm);
            ConditionChangementDir(pcm);
        }
   }

   if ((*pcm).direction=='s')
   {
        AffichageBlanc(pcm);
        LesFantomesNeMangesPas(pcm, diamants);
        ReculY(pcm);

        if (tab[(*pcm).coordonneY][(*pcm).coordonneX]=='1')
        {
            RetourY(pcm);
            AffichagePacman(pcm);
            (*pcm).compteurmvt+=1;
            ConditionChangementDir(pcm);
        }
        else
        {

            (*pcm).compteurmvt+=1;
            AffichagePacman(pcm);
            ConditionChangementDir(pcm);
        }
   }
   if ((*pcm).direction=='z')
   {
        AffichageBlanc(pcm);
        LesFantomesNeMangesPas(pcm, diamants);
        AvancementY(pcm);

        if (tab[(*pcm).coordonneY][(*pcm).coordonneX]=='1')
        {
            RetourYH(pcm);
            AffichagePacman(pcm);
            (*pcm).compteurmvt+=1;
            ConditionChangementDir(pcm);
        }
        else
        {

            (*pcm).compteurmvt+=1;
            AffichagePacman(pcm);
            ConditionChangementDir(pcm);
        }
   }

   if ((*pcm).direction=='q')
   {
      AffichageBlanc(pcm);
      LesFantomesNeMangesPas(pcm, diamants);
      ReculX(pcm);


      if (tab[(*pcm).coordonneY][(*pcm).coordonneX]=='1')
        {
            RetourXG(pcm);
            AffichageBlanc(pcm);
            AffichagePacman(pcm);
            (*pcm).compteurmvt+=1;
            ConditionChangementDir(pcm);
        }

      else
        {

            AffichagePacman(pcm);
            (*pcm).compteurmvt+=1;
            ConditionChangementDir(pcm);
        }
   }
}


