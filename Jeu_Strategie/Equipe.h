#pragma once

#include <vector>
#include "Guerrier.h"
#include "Strategie.h"
#include <memory>

class Equipe {
private:
    std::string nom;// nom de l'equipe
    Guerrier** guerriers; //la liste des guerriers
    int capacite; // capacite maximale d'une equipe
    int nombreGuerriers;// nombre de combattants reels de l'equipe
 

public:
    Equipe(std::string nom);
    // ajouter un combattant a l'equipe
    Guerrier* ajouterGuerrier()const;
    // supprimer un combattant de l'equipe (si celui-ci est mort par exemple)
    void supprimerGuerrier(Guerrier& guerrier);

    
   
    // choisir le combattant qui doit attaquer
    Guerrier* choisirCombattant() const;
    /* annuler les effets d'une strategie
    ( est utile lors du changement de strategie: si l'quipe est rusée)
    */
 
    bool estEpuisee() const;
    void afficherEquipe() const; // afficher
    void attaquerEquipe(Equipe& equipe2) const; // attaquer l'ennemi

    ~Equipe();
};