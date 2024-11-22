#pragma once

#include "Guerrier.h"

class Mage : public Guerrier {
private:
    static int count;//pour faire la difference entre les mages
public:
    Mage(std::string nom, double niv, double dommage);
    void attaquer(Guerrier& ennemi) override;
};
