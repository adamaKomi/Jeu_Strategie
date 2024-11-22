#pragma once
#include "Strategie.h"
#include <iostream>

class Guerrier {
protected:
    std::string nom;
    double niveau; // niveau de vie du combattant
    double dommage;// capacité de dommage du combattant
    Strategie *strategieCombat ;
public:
    Guerrier(std::string n, double niv, double dommage);
    // attaquer un guerrier ennemi
    virtual void attaquer(Guerrier& ennemi) = 0;
    bool operator==(const Guerrier& guerrier) const;
    // si le combattant est mort
    bool estMort() const;
    // reduire le niveau de vie du combattant s'il est attaqué
    void reduireNiveau(double dom);
    // changer les infos( niveau, dommage) lors du changement de strategie de l'equipe
    void changerCaracteristique(double niv, double dom, std::string type);
    void afficherGuerrier() const;// afficher
    ~Guerrier();
};


