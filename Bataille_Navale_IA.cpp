#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>

const int max = 50;
using ligne = std::array<char, max>;
using matrice = std::array<ligne, max>;
// matrice grilleB,  grille;

const int TAILLE_GRILLE = 10;
char let;

// création de la stucture bateau
struct bateau
{
    int taille;
    int num;
    char orientation;
    int lig;
    int col;
};

// initialisation des bateaux
void creation_portAvion(bateau &porte_avion)
{
    porte_avion.taille = 5;
    porte_avion.num = 1;
}

void creation_croiseur(bateau &croiseur)
{
    croiseur.taille = 4;
    croiseur.num = 2;
}

void creation_contre_torpilleur(bateau &contre_torpilleur)
{
    contre_torpilleur.taille = 3;
    contre_torpilleur.num = 3;
}

void creation_contre_torpilleur2(bateau &contre_torpilleur2)
{
    contre_torpilleur2.taille = 3;
    contre_torpilleur2.num = 4;
}

void creation_torpilleur(bateau &torpilleur)
{
    torpilleur.taille = 2;
    torpilleur.num = 5;
}

// tableau_bateau est un tableau de 5 bateaux
using tableau_bateau = std::array<bateau, 5>;

// création de la structure joueur
struct joueur
{
    bateau t[5];
    std::string nom;
    matrice grilleJ;
};

// les fonctions de caractère en entier et entier en caractère
int convertint(char y)
{
    if (y == 'A')
        return 1;
    else if (y == 'B')
        return 2;
    else if (y == 'C')
        return 3;
    else if (y == 'D')
        return 4;
    else if (y == 'E')
        return 5;
    else if (y == 'F')
        return 6;
    else if (y == 'G')
        return 7;
    else if (y == 'H')
        return 8;
    else if (y == 'I')
        return 9;
    else if (y == 'J')
        return 10;
    else
        return 0;
}

char convertchar(int x)
{
    if (x == 1)
        return '1';
    else if (x == 2)
        return '2';
    else if (x == 3)
        return '3';
    else if (x == 4)
        return '4';
    else if (x == 5)
        return '5';
    else if (x == 6)
        return '6';
    else if (x == 7)
        return '7';
    else if (x == 8)
        return '8';
    else if (x == 9)
        return '9';
    else
        return '0';
}
// remplissage du tableau de bateaux
void cree(joueur &j)
{
    creation_portAvion(j.t[0]);
    creation_croiseur(j.t[1]);
    creation_contre_torpilleur(j.t[2]);
    creation_contre_torpilleur2(j.t[3]);
    creation_torpilleur(j.t[4]);
}

// la fonction qui iniatialise la grille
void initialisegrille(matrice &grille)
{
    for (int i = 1; i <= TAILLE_GRILLE; i++)
    {
        for (int j = 1; j <= TAILLE_GRILLE; j++)
        {
            grille[i][j] = '.'; // les grilles vides contiendront des point
        }
    }
}

// la fonction qui affiche la grille
void affichegrille(matrice grille)
{
    for (int i = 1; i <= TAILLE_GRILLE; i++)
    {
        let = 'A' + i - 1; // la première ligne sera numeroté de A à J pour les 10 colonnes
        std::cout << "   " << let;
    }
    for (int i = 1; i <= TAILLE_GRILLE; i++)
    {
        std::cout << std::endl
                  << i << " |"; // la première colonne sera numeroté de 1 à 10 pour les 10 lignes
        for (int j = 1; j <= TAILLE_GRILLE; j++)
        {
            std::cout << " " << grille[i][j] << " |"; // le contenu de la matrice sera séparé par des barres à l'affichage
        }
        std::cout << std::endl;
        if (i < TAILLE_GRILLE)
            std::cout << "____________________________________________";
    }
}

// la fonction qui classe un seul bateau
void place_bat1(bateau &bateaux, matrice &grille)
{
    std::cout << " Donner les coordonnées de début du bateau, ligne puis colonne " << std::endl;
    std::cin >> bateaux.lig >> bateaux.col; // récupère les coordonnées du depart du bateau

    // place les bateaux en horizontale ou verticale

    do
    {
        std::cout << "Horizontal : h , ou Vertical v" << std::endl;
        std::cin >> bateaux.orientation;
    } while ((bateaux.orientation != 'h') and (bateaux.orientation != 'v'));

    if (bateaux.orientation == 'v')
    {

        if (bateaux.taille - 1 + bateaux.lig <= TAILLE_GRILLE)
        {
            bool libre = true;
            for (int i = bateaux.lig; i <= bateaux.taille - 1 + bateaux.lig; i++)
            {
                // vérifie que c'est libre
                if (grille[i][bateaux.col] != '.')
                    libre = false;
            }

            // si c'est libre :
            // on renseigne la matrice
            if (libre)
            {
                for (int i = bateaux.lig; i <= bateaux.taille - 1 + bateaux.lig; i++)
                {
                    if (bateaux.num == 1)
                        grille[i][bateaux.col] = '1';
                    else if (bateaux.num == 2)
                        grille[i][bateaux.col] = '2';
                    else if (bateaux.num == 3)
                        grille[i][bateaux.col] = '3';
                    else if (bateaux.num == 4)
                        grille[i][bateaux.col] = '4';
                    else if (bateaux.num == 5)
                        grille[i][bateaux.col] = '5';
                }
            }
            // si c'est pas libre, on redemande à l'utilisateur de placer le bateau :
            else
            {
                // si placement des choix de l'utilisateur sont impossible on lui redemande de faire le choix
                std::cout << "place indisponible reprennez" << std::endl;
                place_bat1(bateaux, grille);
            }
        }
        else
        {
            // si placement des choix de l'utilisateur sont impossible on lui redemande de faire le choix
            std::cout << "place indisponible reprennez" << std::endl;
            place_bat1(bateaux, grille);
        }
    }

    else if (bateaux.orientation == 'h')
    {
        if (bateaux.taille - 1 + bateaux.col <= TAILLE_GRILLE)
        {

            bool libre = true;
            for (int j = bateaux.col; j <= bateaux.taille - 1 + bateaux.col; j++)
            {
                if (grille[bateaux.lig][j] != '.')
                    libre = false;
            }
            if (libre)
            {
                for (int j = bateaux.col; j <= bateaux.taille - 1 + bateaux.col; j++)
                {
                    if (bateaux.num == 1)
                        grille[bateaux.lig][j] = '1';
                    else if (bateaux.num == 2)
                        grille[bateaux.lig][j] = '2';
                    else if (bateaux.num == 3)
                        grille[bateaux.lig][j] = '3';
                    else if (bateaux.num == 4)
                        grille[bateaux.lig][j] = '4';
                    else if (bateaux.num == 5)
                        grille[bateaux.lig][j] = '5';
                }
            }
            else
            {
                std::cout << "place indisponible reprennez" << std::endl;
                place_bat1(bateaux, grille);
            }
        }

        else
        {
            std::cout << "place indisponible reprennez" << std::endl;
            place_bat1(bateaux, grille);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////

void place_batIA(bateau &bateaux, matrice &grille)
{
    bateaux.lig = rand() % 10 + 1; //donner les coordonnée de la ligne au hasard
    bateaux.col = rand() % 10 + 1; //donner les coordonnée de la colonne au hasard

    int alea = rand() % 2;
    //alea donne deux valeurs soit 0 qui renvoi verticale ou 1 qui renvoi horizontale
    // horizontale ou verticale

    if (alea == 1) 
        bateaux.orientation = 'v';
    else
        bateaux.orientation = 'h';

    if (bateaux.orientation == 'v')
    {

        if (bateaux.taille - 1 + bateaux.lig <= TAILLE_GRILLE)
        {
            bool libre = true;
            for (int i = bateaux.lig; i <= bateaux.taille - 1 + bateaux.lig; i++)
            {
                // vérifie que c'set libre
                if (grille[i][bateaux.col] != '.')
                    libre = false;
            }

            // si c'est libre :
            // on renseigne la matrice
            if (libre)
            {
                for (int i = bateaux.lig; i <= bateaux.taille - 1 + bateaux.lig; i++)
                {
                    if (bateaux.num == 1)
                        grille[i][bateaux.col] = '1';
                    else if (bateaux.num == 2)
                        grille[i][bateaux.col] = '2';
                    else if (bateaux.num == 3)
                        grille[i][bateaux.col] = '3';
                    else if (bateaux.num == 4)
                        grille[i][bateaux.col] = '4';
                    else if (bateaux.num == 5)
                        grille[i][bateaux.col] = '5';
                }
            }
            // si c'est pas libre, on redemande à l'utilisateur de placer le bateau :
            else
            {
                place_batIA(bateaux, grille);
            }
        }
        else
        {
            place_batIA(bateaux, grille);
        }
    }

    else if (bateaux.orientation == 'h')
    {
        if (bateaux.taille - 1 + bateaux.col <= TAILLE_GRILLE)
        {
            bool libre = true;
            for (int j = bateaux.col; j <= bateaux.taille - 1 + bateaux.col; j++)
            {
                if (grille[bateaux.lig][j] != '.')
                    libre = false;
            }
            if (libre)
            {
                for (int j = bateaux.col; j <= bateaux.taille - 1 + bateaux.col; j++)
                {
                    if (bateaux.num == 1)
                        grille[bateaux.lig][j] = '1';
                    else if (bateaux.num == 2)
                        grille[bateaux.lig][j] = '2';
                    else if (bateaux.num == 3)
                        grille[bateaux.lig][j] = '3';
                    else if (bateaux.num == 4)
                        grille[bateaux.lig][j] = '4';
                    else if (bateaux.num == 5)
                        grille[bateaux.lig][j] = '5';
                }
            }
            else
            {
                place_batIA(bateaux, grille);
            }
        }

        else
        {
            place_batIA(bateaux, grille);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////

// deplacer permet à un bateau de se déplacer tant qu'il n'a pas encore été touché
void deplacer(matrice &grille, bateau &bateaux)
{
    if (bateaux.orientation == 'h')
    {
        int i = bateaux.col;
        char direction;
        std::cout << "voulez-vous deplacer le bateau vers la Gauche : G ou vers la droite : D" << std::endl;
        std::cin >> direction;

        for (int j = i; j <= bateaux.taille - 1 + i; j++)
        {
            if (grille[bateaux.lig][j] == convertchar(bateaux.num))
            {

                if (direction == 'G')
                {
                    std::cout << "dir :" << direction << std::endl;
                    if ((grille[bateaux.lig - 1][i] == '.') or (grille[bateaux.lig - 1][i] == 'w'))
                    {
                        // ajoute une case de plus aux cases occupées par le bateau
                        grille[bateaux.lig][i - 1] = convertchar(bateaux.num);
                        // diminue une case de mooins aux cases occupées par le bateau
                        grille[bateaux.lig][bateaux.taille + i - 1] = '.';
                        // récupère les nouvelles coordonnées du bateau
                        bateaux.col = bateaux.col - 1;
                    }
                }
                else if (direction == 'D')
                {
                    if ((grille[bateaux.lig][i + bateaux.taille] == '.') or (grille[bateaux.lig][i + bateaux.taille] == 'w'))
                    {
                        // diminue une case de mooins aux cases occupées par le bateau
                        grille[bateaux.lig][i] = '.';
                        // ajoute une case de plus aux cases occupées par le bateau
                        grille[bateaux.lig][bateaux.taille + i] = convertchar(bateaux.num);
                        // récupère les nouvelles coordonnées du bateau
                        bateaux.col = bateaux.col + 1;
                    }
                }
                else
                {
                    // redemande le choix de l'orientation lorsque le cas précedent ne marche pas
                    std::cout << "Choix impossible ! Réesseyez : la Gauche : G ou vers la droite : D" << std::endl;
                    std::cin >> direction;
                }
            }
        }
    }
    else if (bateaux.orientation == 'v')
    {
        char direction;
        std::cout << "voulez-vous deplacer le bateau vers le haut : H ou vers le bas : B" << std::endl;
        std::cin >> direction;
        int x = bateaux.lig;
        for (int i = x; i <= bateaux.taille - 1 + x; i++)
        {
            if (grille[i][bateaux.col] == convertchar(bateaux.num))
            {
                if (direction == 'H')
                {
                    if ((grille[x - 1][bateaux.col] == '.') or (grille[x - 1][bateaux.col] == 'w'))
                    {
                        grille[x - 1][bateaux.col] = convertchar(bateaux.num);
                        grille[x + bateaux.taille - 1][bateaux.col] = '.';
                        bateaux.lig = bateaux.lig - 1;
                        std::cout << "ligne " << bateaux.lig << " colonne " << bateaux.col << std::endl;
                    }
                }
                else if (direction == 'B')
                {
                    if ((grille[x + bateaux.taille][bateaux.col] == '.') or (grille[x + bateaux.taille][bateaux.col] == 'w'))
                    {
                        grille[x][bateaux.col] = '.';
                        grille[x + bateaux.taille][bateaux.col] = convertchar(bateaux.num);
                        bateaux.lig = bateaux.lig + 1;
                        std::cout << "ligne " << bateaux.lig << " colonne " << bateaux.col << std::endl;
                    }
                }
                else
                {
                    std::cout << "Choix impossible ! Réesseyez : la Gauche : G ou vers la droite : D" << std::endl;
                    std::cin >> direction;
                }
            }
        }
    }
}
//placerIA place les bateaux aléatoirement en faisant appelle à la foncton placebatIA
void PlacerIA(joueur &j)
{
    std::cout << "Saisie du porte avion (taille = 5)" << std::endl;
    std::cout << "---------------------" << std::endl;
    place_batIA(j.t[0], j.grilleJ);

    std::cout << "Saisie du croiseur (taille = 4)" << std::endl;
    std::cout << "---------------------" << std::endl;
    place_batIA(j.t[1], j.grilleJ);

    std::cout << "Saisie du contre_torpieur (taille = 3)" << std::endl;
    std::cout << "---------------------" << std::endl;
    place_batIA(j.t[2], j.grilleJ);

    std::cout << "Saisie du contre_torpieur2 (taille = 3)" << std::endl;
    std::cout << "---------------------" << std::endl;
    place_batIA(j.t[3], j.grilleJ);

    std::cout << "Saisie du torpilleur (taille = 2)" << std::endl;
    std::cout << "---------------------" << std::endl;
    place_batIA(j.t[4], j.grilleJ);
}

// placer place tous les bateaux en faisant appelle à la fonction placebat1 qui place un bateau pour chaque bateau
void Placer(joueur &j)
{
    std::cout << "Saisie du porte avion (taille = 5)" << std::endl;
    std::cout << "---------------------" << std::endl;
    place_bat1(j.t[0], j.grilleJ);

    std::cout << "Saisie du croiseur (taille = 4)" << std::endl;
    std::cout << "---------------------" << std::endl;
    place_bat1(j.t[1], j.grilleJ);

    std::cout << "Saisie du contre_torpieur (taille = 3)" << std::endl;
    std::cout << "---------------------" << std::endl;
    place_bat1(j.t[2], j.grilleJ);

    std::cout << "Saisie du contre_torpieur2 (taille = 3)" << std::endl;
    std::cout << "---------------------" << std::endl;
    place_bat1(j.t[3], j.grilleJ);

    std::cout << "Saisie du torpilleur (taille = 2)" << std::endl;
    std::cout << "---------------------" << std::endl;
    place_bat1(j.t[4], j.grilleJ);
}

// permet de tirer à partir des coordonnées données par le joueur
void attaque(joueur &j)
{
    int lig, col;
    bool touchee;
    std::cout << "donner les coordonnées de l'attaque pour tirer ";
    std::cin >> lig >> col;
    if (j.grilleJ[lig][col] == '.') // verifie si la case est vide
    {
        j.grilleJ[lig][col] = 'w'; // les tir raté sont marqués par w
        touchee = false;
    }
    else if (j.grilleJ[lig][col] != '.')
    {
        j.grilleJ[lig][col] = 'x'; // les bateaux touché sont marqués par x
        touchee = true;
    }

    if (touchee)
        std::cout << "Touché !" << std::endl;
    else
        std::cout << "Dommage, vous avez raté !" << std::endl;
}

void attaqueIA(joueur &j)
{
    int lig = rand() % 10 + 1; //choix aléatoire des coordonné de la ligne en 1 à 10
    int col = rand() % 10 + 1; //choix aléatoire des coordonné de la colonne en 1 à 10
    ;
    bool touchee;
    std::cout << "les coordonnées du tir sont: " << lig << " " << col << std::endl;
    ;

    if (j.grilleJ[lig][col] == '.') // verifie si la case est vide
    {

        j.grilleJ[lig][col] = 'w'; // les tir raté sont marqués par w
        touchee = false;
    }
    else if (j.grilleJ[lig][col] != '.')
    {
        j.grilleJ[lig][col] = 'x'; // les bateaux touché sont marqués par x
        touchee = true;
    }

    if (touchee)
        std::cout << "Touché !" << std::endl;
    else
        std::cout << "Dommage, il a raté !" << std::endl;
}

// verifie si le bateaux n'existe splus ur la grille  return que c'est coulée
bool couler(matrice grille, bateau bateaux)
{
    if (bateaux.orientation == 'v')
    {
        for (int i = bateaux.lig; i <= bateaux.taille - 1 + bateaux.lig; i++)
        {
            if (grille[i][bateaux.col] == convertchar(bateaux.num)) // on cherche si le numero du bateau n'existe plus sur la grille
                return false;                                       // si elle existe c'est qu"il en reste encore donc pas coulée encore
        }
        return true; // si le n"existe plus c'est que le bateau a coulé
    }
    else if (bateaux.orientation == 'h')
    {
        for (int j = bateaux.col; j <= bateaux.taille - 1 + bateaux.col; j++)
        {
            if (grille[bateaux.lig][j] == convertchar(bateaux.num))
                return false;
        }
        return true;
    }
    else
        return false;
}

// Verrifie si l'un des joueur a coulé tous les bateux de l'autre joueur
void gagner(joueur j, joueur k)
{
    if ((couler(j.grilleJ, j.t[0])) and (couler(j.grilleJ, j.t[1])) and (couler(j.grilleJ, j.t[2])) and (couler(j.grilleJ, j.t[3])) and (couler(j.grilleJ, j.t[4])))
        std::cout << k.nom << " Vous avez Gagner !" << std::endl;
    else if ((couler(k.grilleJ, k.t[0])) and (couler(k.grilleJ, k.t[1])) and (couler(k.grilleJ, k.t[2])) and (couler(k.grilleJ, k.t[3])) and (couler(k.grilleJ, k.t[4])))
        std::cout << j.nom << " Vous avez Gagner !" << std::endl;
    else
        std::cout << "" << std::endl;
}

// Verrifie si tous les bateaux d'un joueur sont coulé pour stoper le jeu !
bool fin(joueur j)
{
    return ((couler(j.grilleJ, j.t[0])) and (couler(j.grilleJ, j.t[1])) and (couler(j.grilleJ, j.t[2])) and (couler(j.grilleJ, j.t[3])) and (couler(j.grilleJ, j.t[4])));
}

void Joue(joueur &joueurA, joueur &joueurB)
{
    initialisegrille(joueurA.grilleJ);
    initialisegrille(joueurB.grilleJ);

    std::cout << "Joueur 1, donnez votre nom" << std::endl;
    std::cin >> joueurA.nom;
    std::cout << joueurA.nom << "  place tes bateaux" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    Placer(joueurA);
    affichegrille(joueurA.grilleJ);

    joueurB.nom = " SIRI ";
    std::cout << "Le nom de l'intelligence artificielle est :" << joueurB.nom << std::endl;
    PlacerIA(joueurB);
    affichegrille(joueurB.grilleJ);

    do
    {
        char choixA;
        std::cout << "-------------------" << std::endl;
        std::cout << joueurA.nom << "  a vous de jouer tirer 'T' ou deplace 'D'" << std::endl;
        std::cin >> choixA;

        if (choixA == 'T')
        {
            attaque(joueurB);
            if (couler(joueurB.grilleJ, joueurB.t[0]) or couler(joueurB.grilleJ, joueurB.t[1]) or couler(joueurB.grilleJ, joueurB.t[2]) or couler(joueurB.grilleJ, joueurB.t[3]) or couler(joueurB.grilleJ, joueurB.t[4]))
            {
                std::cout << "Touché et coulé" << std::endl;
            }
            affichegrille(joueurA.grilleJ);
        }
        else if (choixA == 'D')
        {
            int i;
            std::cout << "donner le numéro [1-5] du bateau à deplacer" << std::endl;
            std::cin >> i;
            deplacer(joueurA.grilleJ, joueurA.t[i - 1]);
            affichegrille(joueurA.grilleJ);
        }
        else
        {
            std::cout << joueurA.nom << "mauvais choix tirer 'T' ou deplace 'D'" << std::endl;
            std::cin >> choixA;
        }

        std::cout << "-------------------" << std::endl;
        std::cout << "Au tour de" << joueurB.nom << "de jouer" << std::endl;
        std::cout << joueurB.nom << " tire" << std::endl;
        attaqueIA(joueurA);
        if ((couler(joueurA.grilleJ, joueurA.t[0])) or (couler(joueurA.grilleJ, joueurA.t[1])) or (couler(joueurA.grilleJ, joueurA.t[2])) or (couler(joueurA.grilleJ, joueurA.t[3])) or (couler(joueurA.grilleJ, joueurA.t[4])))
        {
            std::cout << "Touché et coulé" << std::endl;
        }

        // Verrifie si l'un des joueur a coulé tous les bateux de l'autre joueur
        gagner(joueurA, joueurB);

    } while ((not(fin(joueurA))) or (not(fin(joueurB))));
}
    //////////////////////////////////////////////////////////////////////////
/*
    INTEGRATION DE LA FONCTION JOUER !
    __________________________________

*/


// G
// matrice grillejoueur1;
// matrice grillejoueur2;

void attaquer(matrice & grille, int lig, int col)
{
    bool touchee;
    //std::cout << "donner les coordonnées de l'attaque pour tirer ";
    //std::cin >> lig >> col;
    
    lig = rand() % 10 + 1; //choix aléatoire des coordonné de la ligne en 1 à 10
    col = rand() % 10 + 1; //choix aléatoire des coordonné de la colonne en 1 à 10
    
    
    if (grille[lig][col] == '.') // verifie si la case est vide
    {
        grille[lig][col] = 'w'; // les tir raté sont marqués par w
        touchee = false;
    }
    else if (grille[lig][col] != '.')
    {
        grille[lig][col] = 'x'; // les bateaux touché sont marqués par x
        touchee = true;
    }
 			if (touchee)
        std::cout << " 1 : Touché !" << std::endl;
    else
        std::cout << "2 : Dommage, vous avez raté !" << std::endl;
}

bool coulee( matrice grille, char bat)
{
	bool coul = true;
	for (int i = 1; i <= TAILLE_GRILLE; i++)
    {
        for (int j = 1; j <= TAILLE_GRILLE; j++)
        {
            if(grille[i][j] == bat) 
            coul = false;
        }
    }
	return coul;    
	
}

struct coup {
    char action;
    int p1;
    int p2;
};

coup coupJoueur1() {
    coup c;

    do {
        std::cout << "donner votre action T pour Tirer ou D pour deplacer"<<std::endl;
        std::cin>>c.action;
    } while((c.action != 'T') or (c.action != 'D'));

    // Ajouter le code pour demander les coordonnées du tir (stockés dans c.p1 et c.p2)
    if(c.action=='T')
	{
		std::cout<<"donner les coordonnées de l'action x et y"<<std::endl;
		std::cin>>c.p1>>c.p2;
	
	}
    // ou le numéro du bateau (c.p1) et la direction de son déplacement (c.p2)
	else if(c.action=='D')
	{
		std::cout<<"donner le numero du bateau à déplacer 1-5 "<<std::endl;
		std::cin>>c.p1;
		std::cout<<"donnez la direction 0 horizontale et 1 verticale "<<std::endl;
		std::cin>>c.p2;
	}
    return c;
}

int jouerjoueur1( matrice & grillejoueur2, coup c)
{
	if(c.action=='T')
	{
		attaquer(grillejoueur2, c.p1, c.p2);
		           
    if((coulee(grillejoueur2, '1')) or (coulee(grillejoueur2, '2')) or (coulee(grillejoueur2, '3')) or (coulee(grillejoueur2, '4')) or (coulee(grillejoueur2, '5')))
    	return 2; // un bateau coulé !
    if((coulee(grillejoueur2, '1')) and (coulee(grillejoueur2, '2')) and (coulee(grillejoueur2, '3')) and (coulee(grillejoueur2, '4')) and (coulee(grillejoueur2, '5')))
    	return 3; // couler et gagner (tous les bateaux coulés) !
	}
	else if(c.action=='D')
	{		
		//deplacer(grillejoueur1, )
	}

 return 1; // erreur 

}

int jouerjoueur2(matrice & grillejoueur1, coup c)
{

	if(c.action=='T')
	{
		attaquer(grillejoueur1, c.p1, c.p2);
		           
    if((coulee(grillejoueur1, '1')) or (coulee(grillejoueur1, '2')) or (coulee(grillejoueur1, '3')) or (coulee(grillejoueur1, '4')) or (coulee(grillejoueur1, '5')))
    	return 2; // un bateau coulé !
    if((coulee(grillejoueur1, '1')) and (coulee(grillejoueur1, '2')) and (coulee(grillejoueur1, '3')) and (coulee(grillejoueur1, '4')) and (coulee(grillejoueur1, '5')))
    	return 3; // couler et gagner (tous les bateaux coulés) !
	}
	else if(c.action=='D')
	{		
		//deplacer(grillejoueur2, )
	}

   return 1; // erreur
}



    /////////////////////////////////////////////////////////////////////////
/*
    std::cout << "Grille de " << joueurA.nom << std::endl;
    std::cout << "-------------------" << std::endl;
    affichegrille(joueurA.grilleJ);

    std::cout << "Grille de " << joueurB.nom << std::endl;
    std::cout << "-------------------" << std::endl;
    affichegrille(joueurB.grilleJ);

    std::cout << "          *********************************************************\n"
              << "          *                                                       *\n"
              << "          *                     FIN DU JEU                        *\n"
              << "          *                                                       *\n"
              << "          *       BATAILLE NAVALE DE LA MORT QUI TUE !!!          *\n"
              << "          *                                                       *\n"
              << "          *********************************************************\n\n\n\n";

*/
int main()
{
    srand(time(NULL));

    std::cout << "          *********************************************************\n"
              << "          *                                                       *\n"
              << "          *                 BIENVENUE DANS LA                     *\n"
              << "          *                                                       *\n"
              << "          *       BATAILLE NAVALE DE LA MORT QUI TUE !!!          *\n"
              << "          *                                                       *\n"
              << "          *********************************************************\n\n\n\n";

    joueur joueurA, joueurB;

    cree(joueurA);
    cree(joueurB);
  
    //Joue(joueurA, joueurB); /* joueur vs IA */
    initialisegrille(joueurA.grilleJ);
    initialisegrille(joueurB.grilleJ);

    Placer(joueurA);
    affichegrille(joueurA.grilleJ);

    joueurB.nom = " SIRI ";
    std::cout << "Le nom de l'intelligence artificielle est :" << joueurB.nom << std::endl;
    PlacerIA(joueurB);
    affichegrille(joueurB.grilleJ);

 	coupJoueur1();
    std::cout<< "l1 "<<(jouerjoueur1(joueurA.grilleJ, coupJoueur1()));
    coupJoueur1();
    std::cout<< "l2 "<<(jouerjoueur2(joueurB.grilleJ, coupJoueur1()));
   
    return 0;
}
