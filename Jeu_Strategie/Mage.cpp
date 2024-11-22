#include "Mage.h"
#include <string>

int Mage::count = 1;  // distinguer les Mages( ex: Mage_1, Mage_2, ...)

Mage::Mage(std::string nom, double niv, double dommage) 
    : Guerrier(nom + "_" + std::to_string(count++), niv, dommage)
{}

void Mage::attaquer(Guerrier& ennemi) {
    // afficher celui qui attaque et la victime avant l'attaque
    std::cout << "-Attaquant : " << std::endl;
    this->afficherGuerrier();
    std::cout << "-Victime : " << std::endl;
    ennemi.afficherGuerrier();
    std::cout << "" << std::endl;
    // reduire le niveau de vie de l'enemi
    ennemi.reduireNiveau(this->dommage);
    // afficher les dommages causés par l'attaquant
    std::cout << "=> Dommages causer : " << this->dommage;

    // Recompense : augmenter le niveau du Mage de 2 s'il reussit a tuer son adversaire
    if (ennemi.estMort())
    {
        this->niveau += 2;
        std::cout << "" << std::endl;
        std::cout << "(Mage) : +2 niveau pour avoir tuer un enemi !!!" << std::endl;
    }

}
