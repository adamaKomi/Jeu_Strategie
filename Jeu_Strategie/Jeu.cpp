#include "Jeu.h"
#include <iostream>
#include <thread>
#include <chrono> // pour sleep()

// il n'ya que deux equipes par defaut
Jeu::Jeu()
	:equipe1("Equipe 1"), equipe2("Equipe 2")
{
}


void Jeu::commencerCombat()
{	
	// afficher les equipes au debut avant le combat
	std::cout << "000000-------Les equipes---------000000" << std::endl;
	std::cout << "" << std::endl;
	equipe1.afficherEquipe();// afficher equipe1
	equipe2.afficherEquipe();// afficher equipe2


	std::cout << "" << std::endl;
	std::cout << "-------DEBUT DU JEU---------" << std::endl;

	
	int count = 1; // pour compter le nombre de tours de jeu

	// on verifie si l'une des equipes est epuisée
	while (!equipe1.estEpuisee() && !equipe2.estEpuisee()) {
		std::cout << "-----------------------------------------------------" << std::endl;
		std::cout << "TOUR " << count++<<")" << std::endl;
		std::cout << "" << std::endl;

		// chaque equipe va attaquer a tour de role
		std::cout << "********EQUIPE_1 ATTAQUE EQUIPE_2 !!!********" << std::endl;
		std::cout << "" << std::endl;
		equipe1.attaquerEquipe(equipe2); 

		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "********EQUIPE_2 ATTAQUE AQUIPE_1 !!!*********" << std::endl;
		std::cout << "" << std::endl;
		equipe2.attaquerEquipe(equipe1);
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;

		// attendre 2 secondes avant de passer au tour suivant
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}

	// annoncer le vainqueur

	Equipe& gagnante = equipe2.estEpuisee() ? equipe1 : equipe2;

	std::cout << "" << std::endl;
	std::cout << "################################################################" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "L'equipe gagnante est : " << (equipe2.estEpuisee() ? "Equipe 1" : "Equipe 2") << std::endl;
	std::cout << "" << std::endl;
	// Afficher les informations de l'equipe gagante apres le combat
	std::cout << "Informations : " << std::endl;
	std::cout << "" << std::endl;
	gagnante.afficherEquipe();
	std::cout << "" << std::endl;
	std::cout << "################################################################" << std::endl;
	std::cout << "" << std::endl;

	std::cout << "------------FIN DU JEU------------" << std::endl;
	std::cout << "" << std::endl;
	// afficher le nombre de tours de jeu qu'il a fallu pour finir le combat
	std::cout <<count<< " TOURS DE JEU" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
}
