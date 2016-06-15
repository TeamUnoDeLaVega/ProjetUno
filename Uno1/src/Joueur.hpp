#ifndef JOUEUR_HPP_
#define JOUEUR_HPP_
#include "Carte.hpp"
#include <string> 
#include <vector>



class Joueur {
public:
  std::vector <Carte> _cartesJoueur;
  int _id;
  std::string _nom;
public:
  Joueur(int valeur, std::string nom);
  void setIdJoueur(int valeur);
  void setNomJoueur(std::string nom);
  std::vector<Carte> getCartesJoueur()const;
  int getIdJoueur()const;
  Carte jouerCoup();
  void afficherJoueur()const;
  void supprimerCarteJoueur(Carte c);
  std::string getNom();
};

#endif
  
