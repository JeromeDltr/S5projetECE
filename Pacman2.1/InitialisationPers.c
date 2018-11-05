
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <windows.h>
#include <time.h>
#include "ListeFonctions.h"



// INITIALISATION DES PARAMETRES
void InitialisationPerso(Pcman *pcm) // Initialise les attributs du pacman
{
    (*pcm).nom='X';
    (*pcm).coordonneX=0;
    (*pcm).coordonneY=0;
    (*pcm).compteurmvt=0;
    (*pcm).direction='d';
    (*pcm).pointDeVie=5;
    (*pcm).vitesse=1;
    (*pcm).vitesseON=0;
    (*pcm).couleur=0;
}

void InitialisationObjet(Objet diamants[5]) // Initialise les attributs des Objets
{
    int i;

    for(i=0; i<5; i++)
    {
        (diamants)[i].nom='*';
        (diamants)[i].coordonneX=0;
        (diamants)[i].coordonneY=0;
    }
}
void initialisationEnnemi(Pcman ennemi[4]) // Initialise les attributs des ennemis
{
    int i;
    for(i=0; i<4; i++)
    {
        (ennemi[i]).nom='E';
        (ennemi[i]).coordonneX=0;
        (ennemi[i]).coordonneY=0;
        (ennemi[i]).compteurmvt=0;
        (ennemi[i]).direction='d';
        (ennemi[i]).couleur=1;
        (ennemi[i]).vitesse=1;
    }
}
void InitialisationEnnemiIA(Pcman ennemi[4])  // Active l'intelligense des ennemis
{
    int i;
    for(i=0; i<4; i++)
        (ennemi[i]).IAON='1';
}

void InitialisationVitesseON(Pcman *pcm, Pcman ennemi[4]) // Active le changement de vitesse des ennemis
{
    (*pcm).vitesseON=1;
    (ennemi[0]).vitesse=1;
    (ennemi[1]).vitesse=1;
    (ennemi[2]).vitesse=2;
    (ennemi[3]).vitesse=2;
}
void Reinitialisation(Pcman *pcm, Pcman ennemi[4], Objet diamants[5],int tab[20][50], int *score,char *key)
{
    int i,j;
    initialisationEnnemi(ennemi);
    InitialisationObjet(diamants);
    InitialisationPerso(pcm);
    for (j=0;j<20;j++)
    {
        for (i=0;i<50;i++)
        {
            tab[j][i]=0;
        }
    }
    *score=0;
    *key='b';

}
