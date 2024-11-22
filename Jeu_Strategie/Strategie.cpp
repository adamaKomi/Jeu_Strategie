#include <cstdlib>
#include "Strategie.h"

Strategie::Strategie(std::string nom,double bonus,double doma )
	:nom(nom),bonusDommage(doma),bonusNiveau(bonus)
{}

bool Strategie::operator==(const Strategie& strt) const
{
	return this->nom==strt.nom;
}

double Strategie::appliquerStrategie()
{
	return this->bonusDommage + this->bonusNiveau;
}


// afficher les informations sur la strategie
void Strategie::afficherStrategie() const
{
	std::cout << "Nom : " << this->nom
		<< " | Bonus niveau : " << this->bonusNiveau
		<< " | Bonus dommage : " << this->bonusDommage << std::endl;
	 
}
