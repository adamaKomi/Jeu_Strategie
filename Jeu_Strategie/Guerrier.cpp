#include "Guerrier.h"
#include "Carre.h"
#include "Cercle.h"
#include "Triangle.h"
#include <iostream>

Guerrier::Guerrier(std::string n, double niv, double dommage)
	: nom(n), niveau(niv), dommage(dommage)
{
	// La strategie est choisie aleatoirement
	int strategie = rand() % 3;

	switch (strategie)
	{
	case 0:
		this->strategieCombat = new Carre();
		break;
	case 1:
		this->strategieCombat = new Cercle();
		break;
	default:
		this->strategieCombat = new Triangle();
		break;
	}

	this->dommage += this->strategieCombat->appliquerStrategie();
}

// surcharge de l'operateur ==
bool Guerrier::operator==(const Guerrier & guerrier) const
{
	return this->nom == guerrier.nom && this->niveau == guerrier.niveau && this->dommage==guerrier.dommage;
}

// verifier si un guerrier est mort
bool Guerrier::estMort() const
{
	return this->niveau<=0;
}
// pour reduire le niveau de vie apres une attaque
void Guerrier::reduireNiveau(double dom)
{
	this->niveau -= dom;
}

// pour changer les information( appliquer ou annuler une strategie)
void Guerrier::changerCaracteristique(double niv, double dom, std::string type)
{
	if (type == "+") {// appliquer une strategie
		this->niveau += this->niveau * niv;
		this->dommage += this->dommage * dom;
	}
	else if(type=="-") {//annuler une strategie
		this->niveau -= this->niveau * niv;
		this->dommage -= this->dommage * dom;
	}
}


// afficher un guerrier
void Guerrier::afficherGuerrier() const
{
	std::cout << "Nom : " << this->nom 
		<< " | Niveau : " << this->niveau 
		<< " | Dommage : " << this->dommage << std::endl;

	std::cout << "Strategie : ";
	this->strategieCombat->afficherStrategie();
}

Guerrier::~Guerrier()
{
	delete this->strategieCombat;
}



