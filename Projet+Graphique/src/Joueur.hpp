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
  Joueur(int valeur);
  void setIdJoueur(int valeur);
  std::vector<Carte> getCartesJoueur()const;
  int getIdJoueur()const;
  Carte jouerCoup();
  void afficherJoueur()const;
  void supprimerCarteJoueur(Carte c);
};

#endif
  
