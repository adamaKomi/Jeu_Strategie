#pragma once
#include "Guerrier.h"

class Archer 
    :public Guerrier {
private:
    static int count; //pour faire la difference entre les archer
public:
    Archer(std::string nom, double niv, double dommage);//constructeur

    void attaquer(Guerrier& ennemi) override;
};

