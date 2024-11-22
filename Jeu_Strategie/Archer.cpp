#include "Archer.h"
#include <string>

int Archer::count = 1; // distinguer les Archers( ex: Archer_1, Archer_2, ...)

Archer::Archer(std::string nom, double niv, double dommage) 
    : Guerrier(nom+"_" + std::to_string(count++), niv, dommage)
{}

void Archer::attaquer(Guerrier& ennemi) {
    // afficher celui qui attaque et la victime avant l'attaque
    std::cout << "-Attaquant : " << std::endl;
    this->afficherGuerrier();
    std::cout << "-Victime : " << std::endl;
    ennemi.afficherGuerrier();
    std::cout << "" << std::endl;
  
    // reduire le niveau de vie de l'enemi
    ennemi.reduireNiveau(this->dommage);
    // afficher les dommages causés par l'attaquant
    std::cout << "=> Dommages causes : " << this->dommage;

    // Recompense : augmenter le dommage du Archer de 20% s'il reussit a tuer son ennemi
    if (ennemi.estMort())// si l'ennemi est mort
    {
        this->dommage += 0.2;
        std::cout << "" << std::endl;
        std::cout << "(Archer) : +20% de Dommage pour avoir tuer un ennemi !!!" << std::endl;
    }


}


