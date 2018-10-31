#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <windows.h>
#include <time.h>
#include "Plateau.h"
// INITIALISATION DES PARAMETRES
void InitialisationPerso(Pcman *pcm, Objet diamants[5], Pcman ennemi[3])
{
  (*pcm).nom='X';
  (*pcm).coordonneX=2;
  (*pcm).coordonneY=1;
  (*pcm).compteurmvt=0;
  (*pcm).direction='d';
  (*pcm).pointDeVie=5;


  (diamants)[0].nom='*';
  (diamants)[0].coordonneX=0;
  (diamants)[0].coordonneY=0;
  (diamants)[0].marque=2;


  (diamants)[1].nom='*';
  (diamants)[1].coordonneX=0;
  (diamants)[1].coordonneY=0;
  (diamants)[1].marque=2;

  (diamants)[2].nom='*';
  (diamants)[2].coordonneX=0;
  (diamants)[2].coordonneY=0;
  (diamants)[2].marque=2;

  (diamants)[3].nom='*';
  (diamants)[3].coordonneX=0;
  (diamants)[3].coordonneY=0;
  (diamants)[3].marque=2;

  (diamants)[4].nom='*';
  (diamants)[4].coordonneX=0;
  (diamants)[4].coordonneY=0;
  (diamants)[4].marque=2;

  (ennemi[0]).nom='E';
  (ennemi[0]).coordonneX=3;
  (ennemi[0]).coordonneY=3;
  (ennemi[0]).compteurmvt=0;
  (ennemi[0]).direction='d';

  (ennemi[1]).nom='E';
  (ennemi[1]).coordonneX=5;
  (ennemi[1]).coordonneY=5;
  (ennemi[1]).compteurmvt=0;
  (ennemi[1]).direction='d';

  (ennemi[2]).nom='E';
  (ennemi[2]).coordonneX=7;
  (ennemi[2]).coordonneY=7;
  (ennemi[2]).compteurmvt=0;
  (ennemi[2]).direction='d';
}

// DEPLACEMENT
void AvancementX(Pcman *pcm)
{
    (*pcm).coordonneX+=1;
}
void ReculX(Pcman *pcm)
{
    (*pcm).coordonneX-=1;
}
void AvancementY(Pcman *pcm)
{
    (*pcm).coordonneY-=1;
}
void ReculY(Pcman *pcm)
{
    (*pcm).coordonneY+=1;
}

void RetourX(Pcman *pcm)
{
    (*pcm).coordonneX-=1;
}
void RetourXG(Pcman *pcm)
{
    (*pcm).coordonneX+=1;
}
void RetourY(Pcman *pcm)
{

    (*pcm).coordonneY-=1;
}
void RetourYH(Pcman *pcm)
{

    (*pcm).coordonneY+=1;
}

//


