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


void AugmentationVitesse(Pcman *pcm)
{
    if ((*pcm).vitesseON==1)
            {
                if((*pcm).vitesse<5)   //Si la vitesse ne dépasse pas déjà 3, alors elle est incrémentée de 1
                    (*pcm).vitesse+=1;
            }
}
