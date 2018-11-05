//http://blockofcodes.blogspot.com/2013/06/how-to-change-text-color-of-cc-console.html
//to change color
void gotoligcol(int lig, int col);

//Création niveau
void CreationContour(int largeurTab, int longueurTab, int tab[20][50]);
void GenerationNiveauAlea(int tab[20][50]);

// Placement des personnages et objets
void GenerationAleatoireDeDiamants(int largeurTab,int LongueurTab, Objet diamants[5]);
void GenerationAleatoireDePcman(Pcman *pcm);

//Fonction d'affichage
void AffichagePacman(Pcman *pcm);
void AffichageBlanc(Pcman *pcm);
void AffichageScore(int *score);
void AffichagePointDeVie(Pcman *pcm);

int CompteurScore(int *score, Pcman *pcm, Objet diamants[5]);

void ToucherCouler(Pcman *pcm,Pcman *ennemi);
void LesFantomesNeMangesPas(Pcman *ennemi, Objet diamants[5]);
void boucleToucherCouler(Pcman *pcm, Pcman ennemi[4]);
