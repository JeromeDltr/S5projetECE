//http://blockofcodes.blogspot.com/2013/06/how-to-change-text-color-of-cc-console.html


//***************************************************PLATEAU********************************************************************************

//to change color

//Création niveau
void CreationContour( int tab[20][50]);
void GenerationNiveauAlea(int tab[20][50]);

// Placement des personnages et objets
void GenerationAleatoireDeDiamants(Objet diamants[5]);
void GenerationAleatoireDePcman(Pcman *pcm);

//Fonction d'affichage
void AffichagePacman(Pcman *pcm);
void AffichageBlanc(Pcman *pcm);
void AffichageScore(int *score);
void AffichagePointDeVie(Pcman *pcm);

;


//************************************************InitialisationPers***************************************************************

void InitialisationPerso(Pcman *pcm);
void InitialisationObjet(Objet diamants[5]);
void initialisationEnnemi(Pcman ennemi[4]);
void InitialisationEnnemiIA(Pcman ennemi[4]);
void InitialisationVitesseON(Pcman *pcm, Pcman ennemi[4]);
void Reinitialisation(Pcman *pcm, Pcman ennemi[4], Objet diamants[5],int tab[20][50], int *score,char *key);

//***********************************************MENU************************************************************************

void pacmanAffichage();
void PremierEcran();
void menuOption();
void regles();

void bougerMenu(int indiceFleche);
void afficherFleche(int indiceFleche);

void lvl1(char *key, unsigned long int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50]);
void lvl2(char *key, unsigned long int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50]);
void lvl3(char *key, unsigned long int *temps, int *score, Pcman *pcm, Pcman ennemi[4], Objet diamants[5], int tab[20][50]);

void modifVitesse(unsigned long int *temps, int indiceFleche);
void choixVitesse(unsigned long int *temps, int indiceFleche);
void ctrlVitesse();


//************************************************Deplacement*****************************************************************************


void changementDirEnnemie(Pcman *pcm);
void ConditionChangementDir(Pcman *pcm, Pcman *ennemi);
void changementDirIntelligente(Pcman *pcm, Pcman *ennemi);
void ChangementDirPacman(Pcman *pcm, char *key);

void VieAutonome(Pcman *pcmn,Objet diamants[5], int *score, int tab[20][50],Pcman ennemi[4]);
void VieAutonomeEnnemie(Pcman *ennemi, int tab[20][50], Objet diamants [5], Pcman *pcm);



//*************************************************Test************************************************************************************
void Clignotement(Pcman *pcm);
void TestDefaite(Pcman *pcm, char *key);

int CompteurScore(int *score, Pcman *pcm, Objet diamants[5]);

void ToucherCouler(Pcman *pcm,Pcman *ennemi);
void PerteDePointDeVie(pcm);

void LesFantomesNeMangesPas(Pcman *ennemi, Objet diamants[5]);
void boucleToucherCouler(Pcman *pcm, Pcman ennemi[4]);

//**************************************************OutilsAutres**************************************************************************
int MinTab(double tab[4], int tailleTab);
int modulo(int x,int N);
void gotoligcol(int lig, int col);

