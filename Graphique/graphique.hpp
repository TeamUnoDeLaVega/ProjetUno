#ifndef GRAPHIQUE_HPP_
#define GRAPHIQUE_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <string.h>
#include <iostream>


using namespace sf;

class graphique{
public:
  void dessinerCarte(float largeur, float longueur,int x, int y);
  //void cartes(std::string nom, int largeur, int longueur, int x, int y);

#endif
