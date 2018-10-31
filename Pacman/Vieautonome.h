#ifndef Vieautonome
#define Vieautonome
void VieAutonome(Pcman *pcmn,Objet diamants[5], int *score, int tab[20][50]);
void VieAutonomeEnnemie(Pcman *pcm, int tab[20][50], Objet diamants [5]);
void changementDirEnnemie(Pcman *pcm);
void ConditionChangementDir(Pcman *pcm);
#endif
