#pragma once
#include <iostream>

class Strategie {
protected:
    std::string nom;
    double bonusNiveau; // en pourcentage
    double bonusDommage;// en pourcentage
public:
    Strategie(std::string nom,double bonusNiveau, double bonusDommage);
    bool operator==(const Strategie& strt) const;
 
    
    double appliquerStrategie();
    // annuler l'ancienne strategie avant le changement de strategie (equipe rusée)
    void afficherStrategie()const;
};

