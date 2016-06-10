#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cartes.hpp"


Cartes::Cartes(){};
Cartes::Cartes(RectangleShape target, float largeur, float longueur, int x, int y){
  
  Texture tcartes;
  if(!tcartes.loadFromFile("fond-carte.png")){
   std::cout<<"Pas importée"<<std::endl;
  }
  
  RectangleShape target(Vector2f(largeur,longueur));
  target.setFillColor(Color::White);
  target.setOutlineThickness(1);
  target.setOutlineColor(Color(255,255,255));
  target.move(x,y);

  target.setTexture(&tcartes);

};


void Cartes::afficher(RenderWindow &target){
  target.draw(target);
};

