#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct Pcman Pcman;
struct Pcman
{
    char nom;
    int coordonneX;
    int coordonneY;
    int compteurmvt;
    int pointDeVie;
    int vitesse;
    int vitesseON;
    char direction;
    int IAON;
    int couleur;
};

typedef struct Objet Objet;
struct Objet
{
    char nom;
    int coordonneX;
    int coordonneY;
};
