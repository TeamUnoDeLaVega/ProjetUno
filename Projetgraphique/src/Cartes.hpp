#ifndef CARTES_HPP_
#define CARTES_HPP_
#include <string.h>
using namespace sf;

class Cartes{
private:
  RectangleShape target;
public:
  //Cartes();
  Cartes(RectangleShape &target, float largeur, float longueur, int x, int y);
  void afficher(RenderWindow &target);
  

};

#endif
