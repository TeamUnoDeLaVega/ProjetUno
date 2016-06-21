
#ifndef JEU_HPP_
#define JEU_HPP_
#include "Carte.hpp"
#include "Joueur.hpp"
#include <vector>
#include "JeuSrv.hpp"


class Jeu {
public:
  std::vector <Carte> _paquet;
  int _joueurCourant;
  int _sens;
  Carte _carteCourante;
  std::vector <Carte> _historique;
  Jeu();
    std::vector <Joueur> _players; 
  Carte distribuerCarte(Joueur *j, int i);
  void creerJoueur(Joueur j);
  int coupValide(Carte c) const ;
  void regleDuJeux(Joueur *j,  Carte c);
  Carte carteCourante();
  void supprimer(Carte  c);
  int getSens() const;
  void modifierSens();
  void modifierJoueurCourant();
  int getJoueurCourant() const;
  Carte getCarteCourante() const;
  void modifierCarteCourante(Carte c);
  Carte getCarte(int indice);
  Carte modifierCouleur(Carte c,std::string couleur);
  void historique(Carte c);
  void afficher()const;
  void ajouterCarte(Joueur *j);
  int piocherUneCarte();
  void jouer();
  void piocher(Joueur *j);
  void verifier(Joueur *j);
  int vainqueur();
  Joueur* getJoueur1();
  Joueur* getJoueurCourant2() ;
  Carte setCarteCourante(Carte c);
  void supprimerCarteJoueur(Joueur* j,Carte c);
  void remplirPaquet();
};

#endif 
