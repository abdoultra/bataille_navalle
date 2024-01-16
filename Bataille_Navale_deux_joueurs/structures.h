#pragma once
#include <iostream>
#include <array>
#include <string>

const int max  = 50;
const int TAILLE_GRILLE = 10;

using ligne = std::array <char,max>;
using matrice = std::array <ligne,max>;



//création de la structure bateau
struct bateau{
    int taille;
    int num;
    char orientation;
    int lig;
    int col;
};

// tableau_bateau est un tableau de 5 bateaux
using tableau_bateau = std::array<bateau, 5>;

// création de la structure joueur
struct joueur
{
    bateau t[5];
    std::string nom;
    matrice grilleJ;
};

// initialisation des bateaux
void creation_portAvion(bateau &porte_avion);

void creation_croiseur(bateau &croiseur);

void creation_contre_torpilleur(bateau &contre_torpilleur);

void creation_contre_torpilleur2(bateau &contre_torpilleur2);

void creation_torpilleur(bateau &torpilleur);


// les fonctions de caractère en entier et entier en caractère
int convertint(char y);

char convertchar(int x);


// remplissage du tableau de bateaux
void cree(joueur &j);

// la fonction qui iniatialise la grille
void initialisegrille(matrice &grille);

// la fonction qui affiche la grille
void affichegrille(matrice grille);

// la fonction qui classe un seul bateau
void place_bat1(bateau &bateaux, matrice &grille);

// deplacer permet à un bateau de se déplacer tant qu'il n'a pas encore été touché
void deplacer(matrice &grille, bateau &bateaux);

// placer place tous les bateaux en faisant appelle à la fonction placebat1 qui place un bateau pour chaque bateau
void Placer(joueur &j);

// permet de tirer à partir des coordonnées données par le joueur
void attaque(joueur &j);

// verifie si le bateaux n'existe splus ur la grille  return que c'est coulée
bool couler(matrice grille, bateau bateaux);

//la fonction qui permet de lancer une partie
void Joue(joueur &joueurA, joueur &joueurB);

// Verrifie si tous les bateaux d'un joueur sont coulé pour stoper le jeu !
bool fin(joueur j);


