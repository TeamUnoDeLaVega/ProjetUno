#ifndef JOUEUR_HPP_
#define JOUEUR_HPP_
#include "Carte.hpp"
#include <string> 
#include <vector>



class Joueur {
public:
  std::vector <Carte> _cartesJoueur;
  int _id;
public:
  Joueur();
  void setIdJoueur(int valeur);
  int  getIdJoueur();
  Carte jouerCoup();
  void afficherJoueur()const;
  void supprimerCarteJoueur(Carte c);
};

#endif
  
