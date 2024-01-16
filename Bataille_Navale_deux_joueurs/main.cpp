#include "structures.h"

int main()
{
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
    Joue(joueurA, joueurB);

    return 0;
}
