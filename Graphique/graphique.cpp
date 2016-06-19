#include "graphique.hpp"
#include 
Texture cartes;

if(!cartes.loadFromFile("fond-carte.png")){
   std::cout<<"Pas importée"<<std::endl;
   return 0;
  }


void dessinerCartes(float largeur,float longueur, int x, int y){
  RectangleShape tmp;
  tmp.setSize(Vector2f(largeur,longueur));
  tmp.setFillColor(Color(255,255,255));
  tmp.setOutlineThickness(1);
  tmp.setOutlineColor(Color::White);
  tmp.move(x,y);
  tmp.setTexture(&cartes);
};
