// Jeu_Strategie.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <ctime>
#include "Jeu.h"
#include "Guerrier.h"

int main() {
   srand(time(0));

    Jeu game;// creer un jeu


    game.commencerCombat();
  
   


    return 0;
}
