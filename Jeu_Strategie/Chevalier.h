#pragma once

#include "Guerrier.h"

class Chevalier : public Guerrier {
private:
    static int count;//pour faire la difference entre les chevaliers
public:
    Chevalier(std::string nom, double niv, double dommage);
    void attaquer(Guerrier& ennemi) override;
};