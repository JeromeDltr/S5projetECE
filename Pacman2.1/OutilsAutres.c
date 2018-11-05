#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include<math.h>
#include <windows.h>
#include <time.h>
#include "ListeFonctions.h"
void gotoligcol(int lig, int col) //Place le curseur à une ligne, colonne donnée
{
    COORD mycoord;
    mycoord.X =col;
    mycoord.Y = lig;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}
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
int modulo(int x,int N)
{
    return (x % N + N) %N;
}
