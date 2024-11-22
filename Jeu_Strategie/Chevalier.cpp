#include "Chevalier.h"

#include <string>

int Chevalier::count = 1;  // distinguer les Chevaliers( ex: Chevalier_1, Chevalier_2, ...)

Chevalier::Chevalier(std::string nom, double niv, double dommage) 
    : Guerrier(nom+ "_" + std::to_string(count++), niv, dommage)
{}

void Chevalier::attaquer(Guerrier& ennemi) {
    // afficher celui qui attaque et la victime avant l'attaque
    std::cout << "-Attaquant : " << std::endl;
    this->afficherGuerrier();
    std::cout << "-Victime : " << std::endl;
    ennemi.afficherGuerrier();
    std::cout << "" << std::endl;
    std::cout << "Ajout" << std::endl;
  
    // reduire le niveau de vie de l'enemi
    ennemi.reduireNiveau(this->dommage);
    // afficher les dommages causés par l'attaquant
    std::cout << "=> Dommages causer : " << this->dommage;

    // Recompense : augmenter le dommage du Chevalier de 10% s'il reussit a tuer son ennemi
    if (ennemi.estMort())// si l'ennemi est mort
    {
        this->dommage += 0.1;
        std::cout << "" << std::endl;
        std::cout << "(Chevalier) : +10% de Dommage pour avoir tuer un ennemi !!!" << std::endl;
    }
}
