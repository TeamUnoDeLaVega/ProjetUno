#ifndef VUEGRAPHIQUE_HPP_
#define VUEGRAPHIQUE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Cartes.hpp"
#include "Textes.hpp"
#include "Carte.hpp"
#include "Joueur.hpp"
#include "Client.hpp"


#define r Color(Color::Red)
#define b Color(Color::Blue)
#define v Color(Color::Green)
#define j Color(Color::Yellow)
#define n Color(Color::Black)

#define X 800 //largeur de la fenetre
#define Y 500 //hauteur de la fenetre
#define Z X/30 //Taille de la police




class VueGraphique {
private:
  sf::RenderWindow  window;
  sf::RectangleShape _carte;
  Cartes pioches;
  Cartes jHaut;
  Cartes jGauche;
  Cartes jDroite;
  Cartes tas;
  Sprite sprite;
  Text leftTxt;
  Text rightTxt;
  Text upTxt;
  Text piocheTxt;
  Text tasTxt;
  int x=15;
  int _pas=X/15;
  Joueur player;
  Carte carteCouranteGraphique;
  Joueur _joueur;
  Client _client;
public :
  VueGraphique();
  void ajouterUneCarte(Carte c,int x,int y);
  void initialiser();
  void run();
  void modifierX();
  int getX();
  void afficherCartesJoueur();
  void remplir();
  void setCarteCouranteGraphique(Carte c);
  void carteCourante(Carte c);
  void carteJoueur(Carte c);
  void setClient(Client c );
  void afficher();
  void initialiserClient();
  void remplirCarteCourante();
  void choixCouleur();
};

#endif 
