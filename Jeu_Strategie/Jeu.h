#pragma once


#include "Equipe.h"

class Jeu {
private:
    Equipe equipe1, equipe2;
public:
    Jeu();
    // methode principale pour gerer le combat
    void commencerCombat() ;
};