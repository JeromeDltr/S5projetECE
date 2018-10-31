#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <windows.h>
#include <time.h>
#include "Personnage.h"

void gotoligcol(int lig, int col)
{
    COORD mycoord;
    mycoord.X =col;
    mycoord.Y = lig;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}
void AffichagePacman(Pcman *pcm)
{


    gotoligcol((*pcm).coordonneY,(*pcm).coordonneX);
    printf("%c",(*pcm).nom);
}


void AffichageBlanc(Pcman *pcm)
{
    gotoligcol((*pcm).coordonneY,(*pcm).coordonneX);
    printf(" ");
}

void CreationContour(int largeurTab, int longueurTab, int tab[20][50])
{
    int i;
    for (i=0;i<largeurTab;i++)
    {
        gotoligcol(0,i);
        tab[0][i]='1';
        printf("-");

    }
    for (i=0;i<largeurTab;i++)
    {
        gotoligcol(longueurTab,i);
        tab[longueurTab][i]='1';
        printf("-");
    }
    for (i=0;i<longueurTab;i++)
    {
        gotoligcol(i,0);
        tab[i][1]='1';
        printf("|");
    }
    for (i=0;i<longueurTab;i++)
    {
        gotoligcol(i,largeurTab);
        tab[i][largeurTab]='1';
        printf("|");
    }
}
/*
void creationNiveau(char tab[12][46], int *scoreF, Pcman *ennemie)
{

    FILE *fic=NULL;
    int val,x=0,y=0,i=0;
    fic=fopen("C:\\Users\\Hussonnois Maxence\\Desktop\\Infos5\\Pacman\\niveau.txt","r");
         if (fic != NULL)
        {

            do
            {
                val = fgetc(fic);
                switch(val)
                {
                case 'B':

                    tab[y][x]='*';

                    gotoligcol(y,x);
                    printf("*");
                    x++;
                    break;
                case 'e':

                    tab[y][x]=' ';
                    (ennemie[i]).coordonneX=x;
                    (ennemie[i]).coordonneY=y;
                    gotoligcol(y,x);
                    i++;
                    printf("*");
                    x++;
                    break;
                case 'a':
                    tab[y][x]='.';

                    *scoreF+=1;
                    gotoligcol(y,x);
                    printf(".");
                    x++;
                    break;
                case 'm':
                    tab[y][x]='*';


                    gotoligcol(y,x);
                    printf("*");
                    x++;
                    break;
                case ' ':
                    tab[y][x]=' ';

                    gotoligcol(y,x);
                    printf(" ");
                    x++;
                    break;
                case 'p':
                     tab[y][x]='*';
                     gotoligcol(y,x);
                     printf("*");
                     printf("\n");
                     x=1;
                     y++;
                     break;
                } // On lit le caractère
                 // On l'affiche
            } while (val != EOF);
        }
}
*/
void GenerationAleatoireDeDiamants(int largeurTab,int longueurTab,Objet diamants[5])
{
    int i=0;

    for (i=0; i<5;i++)
    {
        (diamants)[i].coordonneX=(rand()%(50-1)) +1;
        (diamants)[i].coordonneY=(rand()%(20-1)) +1;
        gotoligcol(((diamants)[i]).coordonneY,((diamants)[i]).coordonneX);

        printf("%c",((diamants)[i]).nom);

    }
}

void GenerationAleatoireDePcman(Pcman *pcm)
{
    char tabd[4];
    int i;
    tabd[0]='s';
    tabd[1]='d';
    tabd[2]='q';
    tabd[3]='z';
    i=rand()%4;
    (*pcm).direction=tabd[i];
    (*pcm).coordonneX=(rand()%(50-1)) +1;
    (*pcm).coordonneY=(rand()%(20-1)) +1;

}



void AffichageScore(int *score)
{
    gotoligcol(23,0);
    printf(" ");
    printf("Le score est de %d",*score);
}

void AffichagePointDeVie(Pcman *pcm)
{
    gotoligcol(21,0);
    printf(" ");
    printf("Il te reste %d point de vie",(*pcm).pointDeVie);
}

int CompteurScore(int *score, Pcman *pcm, Objet diamants[5])

{
    int i=0;

    for (i=0; i<5; i++)
    {
       if (((*pcm).coordonneY==(diamants[i]).coordonneY) && ((*pcm).coordonneX==(diamants[i]).coordonneX))
        {
        *score+=10;

        }
    }


    return *score;
}

void LesFantomesNeMangesPas(Pcman *ennemi, Objet diamants[5])
{
    int i=0;

    for (i=0; i<5; i++)
    {
       if (((*ennemi).coordonneY==(diamants[i]).coordonneY) && ((*ennemi).coordonneX==(diamants[i]).coordonneX))
        {
            gotoligcol((*ennemi).coordonneY,(*ennemi).coordonneX);
            printf("*");
        }
    }

}

void MORT(Pcman *pcm,Pcman ennemi[3])
{
    int i=0;

    for (i=0; i<3; i++)

        if (((ennemi[i]).coordonneY==(*pcm).coordonneY) && ((ennemi[i]).coordonneX==(*pcm).coordonneX))
         {
             (*pcm).pointDeVie-=1;
         }
}
