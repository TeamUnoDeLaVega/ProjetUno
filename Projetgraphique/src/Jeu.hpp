
#ifndef JEU_HPP_
#define JEU_HPP_
#include "Carte.hpp"
#include "Joueur.hpp"
#include <vector>


class Jeu {
private:
  std::vector <Carte> _paquet;
  int _joueurCourant;
  int _sens;
  Carte _carteCourante;
  std::vector <Carte> _historique;
public:
  Jeu();
  void distribuerCarte(Joueur *j);
  int coupValide(Carte c) const ;
  void regleDuJeux(Joueur *j);
  Carte carteCourante();
  void supprimer(Carte  c);
  int getSens() const;
  void modifierSens();
  void modifierJoueurCourant();
  int getJoueurCourant() const;
  Carte getCarteCourante() const;
  void modifierCarteCourante(Carte c);
  Carte getCarte(int indice);
  Carte modiferCouleur(Carte c,std::string couleur);
  void historique(Carte c);
  void afficher()const;
  void ajouterCarte(int id);
  int piocherUneCarte();
};

#endif 
