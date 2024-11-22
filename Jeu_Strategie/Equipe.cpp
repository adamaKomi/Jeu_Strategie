#include <iostream>
#include <cstdlib>
#include "Equipe.h"
#include "Strategie.h"
#include "Archer.h"
#include "Chevalier.h"
#include "Mage.h"
#include "Carre.h"
#include "Cercle.h"
#include "Triangle.h"


Equipe::Equipe(std::string nom)
    :nom(nom), capacite(10), nombreGuerriers(5)
    
{
    // initialiser un tableau de combattant
    this->guerriers = new Guerrier * [capacite];
    for (int i = 0; i < this->nombreGuerriers; i++)
    {
        // on ajoute des combattants de facon aleatoire par equipe
        this->guerriers[i] = ajouterGuerrier();
    }

    // le reste du tableau est initialisé à 'nullptr'
    for (int i = nombreGuerriers; i < this->capacite; i++)
    {
    this->guerriers[i] = nullptr;
    }

}


// cette fonction nous retourne un combattant de type aleatoire
Guerrier* Equipe::ajouterGuerrier() const
{
    if (this->nombreGuerriers == capacite) {
        std::cout << "Capacité maximale atteinte, impossible d'ajouter un guerrier." << std::endl;
        return nullptr;
    }
    //generer un combattant de facon aleatoire
    int random_combattant = rand() % 3;
    switch (random_combattant)
    {
    case 0:
        return (new Archer("Archer", 10, 5));
    case 1:
        return (new Chevalier("Chevalier", 15, 2));
    default:
        return (new Mage("Mage", 18, 3));
    }
}


// cette fonction supprime un combattant de l'equipe (s'il est mort)
void Equipe::supprimerGuerrier(Guerrier& guerrier)
{
    for (int i = 0; i < this->nombreGuerriers; i++)// trouver le combattant
    {
        if (*this->guerriers[i]==guerrier) {
            delete this->guerriers[i];
            //on remplace juste le combattant par le dernier combattant du tableau
            this->guerriers[i] = this->guerriers[--nombreGuerriers];
            // on met le dernier element a nullptr
            this->guerriers[nombreGuerriers] = nullptr;
            break;
        }
    }
}




// cette fonction permet de choisir le combattant qui va attaquer
Guerrier* Equipe::choisirCombattant() const
{
    if (this->estEpuisee()) return nullptr;

    // le combattant est choisi aleatoirement dans l'equipe
    int comb = rand() % this->nombreGuerriers;

    // Vérifiez si le guerrier choisi est valide
    if (this->guerriers[comb] == nullptr) {
        return nullptr;
    }

    return this->guerriers[comb];
}

// cette fonction verifie si une equipe est epuisée
bool Equipe::estEpuisee() const 
{
    return this->nombreGuerriers==0;
}

//cette fonction affiche les informations d'une equipe
void Equipe::afficherEquipe() const
{
    std::cout<<"__________" << this->nom<<"______________" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "**********Liste des combattants********** " << std::endl;
    std::cout << "" << std::endl;
    for (int i = 0; i < this->nombreGuerriers; i++) {
        std::cout << i+1<<". ";
        this->guerriers[i]->afficherGuerrier();
        std::cout << "" << std::endl;
    }

}


// cette fonction permet de lancer une attaque sur l'equipe ennemie
void Equipe::attaquerEquipe(Equipe& equipe2) const
{
    if (this->estEpuisee() || equipe2.estEpuisee()) return;// pour eviter la division par 0

    // selectionner les combattants qui vont s'affronter aleatoirement dans chaque equipe
    Guerrier* attaquant = this->choisirCombattant(); // celui qui attaque
    Guerrier* victime = equipe2.choisirCombattant();// la victime de l'attaque

    //verifie si les combattants choisis existent bien
    if (!attaquant || !victime) return; 

    // lancer l'attaque
    attaquant->attaquer(*victime);

    //supprimer la victime si elle est morte apres l'attaque
    if (victime->estMort()) {
        equipe2.supprimerGuerrier(*victime);
        std::cout << "" << std::endl;
        std::cout << "=> Un soldat a ete tue dans cette attaque" << std::endl;
    }
}


// le destructeur
Equipe::~Equipe()
{
    for (int i = 0; i < this->nombreGuerriers; i++) {
        delete this->guerriers[i];
        this->guerriers[i] = nullptr;
    }

    delete[] this->guerriers;
    this->guerriers = nullptr;
}

