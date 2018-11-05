#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <windows.h>
#include <time.h>
#include "ListeFonctions.h"
// DEPLACEMENT

void Deplacement(Pcman *pcm)   // Deplace le personnage sur le terrain
{
    switch((*pcm).direction)
    {
        case 'd':
            (*pcm).coordonneX+=1;  //Deplacement vers la droite
            break;
        case 'q':
            (*pcm).coordonneX-=1;   // Deplacement vers la gauche
            break;
        case 'z':
            (*pcm).coordonneY-=1;   //Deplacement vers le haut
            break;
        case 's':
            (*pcm).coordonneY+=1;    //Deplacement vers le bas
            break;
    }
}

void Blocage(Pcman *pcm)    //Bloque le deplacement du personnage
{
   switch((*pcm).direction)
    {
        case 'd':
            (*pcm).coordonneX-=1;  // Bloque le deplacement à droite
            break;
        case 'q':
            (*pcm).coordonneX+=1;  // Bloque le deplacement à gauche
            break;
        case 'z':
            (*pcm).coordonneY+=1;  // Bloque le deplacement en haut
            break;
        case 's':
            (*pcm).coordonneY-=1;   // Bloque le deplacement en bas
            break;
    }
}
void Rebond(Pcman *pcm)    //Bloque le deplacement du personnage
{
   switch((*pcm).direction)
    {
        case 'd':
            (*pcm).coordonneX-=1;  // Bloque le deplacement à droite
            (*pcm).direction='d';
            break;
        case 'q':
            (*pcm).coordonneX+=1;  // Bloque le deplacement à gauche
            (*pcm).direction='q';
            break;
        case 'z':
            (*pcm).coordonneY+=1;  // Bloque le deplacement en haut
            (*pcm).direction='z';
            break;
        case 's':
            (*pcm).coordonneY-=1;   // Bloque le deplacement en bas
            (*pcm).direction='s';
            break;
    }
}


void ChangementDirPacman(Pcman *pcm, char *key)
{
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
                case 'v':

                    break;
                case 'p':
                    printf("Appuyer sur n'importe quelle touche pour reprendre");
                    *key=getch();
                    break;
                case 'o':
                    *key='n';
                    break;
            }
        }
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


void AugmentationVitesse(Pcman *pcm)
{
    if ((*pcm).vitesseON==1)
            {
                if((*pcm).vitesse<5)   //Si la vitesse ne dépasse pas déjà 3, alors elle est incrémentée de 1
                    (*pcm).vitesse+=1;
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
                PerteDePointDeVie(pcm);
            }


            else  if (tab[(*pcm).coordonneY][(*pcm).coordonneX]=='2')
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
            ConditionChangementDir(ennemi, pcm);
        }
        else if (tab[(*ennemi).coordonneY][(*ennemi).coordonneX]=='2')
        {
            (*ennemi).compteurmvt+=1;
            Blocage(ennemi);
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
