//Initialisations des attributs
void InitialisationPerso(Pcman *pcm);
void InitialisationObjet(Objet diamants[5]);
void initialisationEnnemi(Pcman ennemi[4]);
void InitialisationEnnemiIA(Pcman ennemi[4]);
void InitialisationVitesseON(Pcman *pcm, Pcman ennemi[4]);

void Reinitialisation(Pcman *pcm, Pcman ennemi[4], Objet diamants[5],int tab[20][50],int *score, char *key);

void AugmentationVitesse(Pcman *pcm);
//DEPLACEMENT
// BLOCAGE
void Blocage(Pcman *pcm);
void Deplacement(Pcman *pcm);
void Rebond(Pcman *pcm);


