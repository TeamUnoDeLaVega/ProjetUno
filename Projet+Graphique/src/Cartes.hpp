#ifndef CARTES_HPP_
#define CARTES_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Carte.hpp"
#include "Jeu.hpp"
#include "Joueur.hpp"
#include <iostream>
using namespace sf;


class Cartes{
public:
    Sprite sprite;
    RectangleShape rect;

  Cartes(float xPosition, float yPosition, int rouge, int vert, int bleu){
        sprite.setPosition(xPosition, yPosition);
        
        rect.setSize(Vector2f(xPosition, yPosition));
        rect.setFillColor(Color(rouge, vert, bleu));
	rect.setOutlineThickness(1);
        rect.setOutlineColor(Color::White);
  }

void setPosition(float xPosition, float yPosition){
  sprite.setPosition(xPosition, yPosition);
}

void update(){
  rect.setPosition(sprite.getPosition());
  }
  
void setTexture(Texture texture){
	rect.setTexture(&texture);
}  
};
#endif
  
