#ifndef JOUEUR_HPP_
#define JOUEUR_HPP_
#include "Carte.hpp"
#include <string> 
#include <vector>



class Joueur {
public:
  std::vector <Carte> _cartesJoueur;
  Carte _carteCourante;
public:
  Joueur();
  std::vector<Carte> getCartesJoueur()const;
  Carte jouerCoup();
  void afficherJoueur()const;
  void supprimerCarteJoueur(Carte c);


};

#endif
  
