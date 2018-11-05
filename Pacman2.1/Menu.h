



void pacmanAffichage();
void PremierEcran();
void menuOption();
void regles();

void bougerMenu(int indiceFleche);
void afficherFleche(int indiceFleche);

int modulo(int x,int N);


void lvl1(char *key, unsigned long int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50], int longueurTab,int largeurTab);
void lvl2(char *key, unsigned long int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50], int longueurTab,int largeurTab);
void lvl3(char *key, unsigned long int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50], int largeurTab,int longueurTab);


void ChangementDirPacman(Pcman *pcm, char *key);
void TestDefaite(Pcman *pcm, char *key);
void modifVitesse(unsigned long int *temps, int indiceFleche);
void choixVitesse(unsigned long int *temps, int indiceFleche);
void ctrlVitesse();
void NiveauSup(char *key, unsigned long int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50], int largeurTab,int longueurTab);
