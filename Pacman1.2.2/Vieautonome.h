#ifndef Vieautonome
#define Vieautonome
void VieAutonome(Pcman *pcmn,Objet diamants[5], int *score, int tab[20][50]);
void VieAutonomeEnnemie(Pcman *ennemi, int tab[20][50], Objet diamants [5], Pcman *pcm);
void changementDirEnnemie(Pcman *pcm);
void ConditionChangementDir(Pcman *pcm, Pcman *ennemi);
void changementDirIntelligente(Pcman *pcm, Pcman *ennemi);
int MinTab(double tab[4], int tailleTab);
#endif
