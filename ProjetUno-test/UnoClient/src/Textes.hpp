
#ifndef TEXTES_HPP_
#define TEXTES_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>

class Textes{
public:
    Sprite sprite;
    Text txt;

  Textes(float xPosition, float yPosition, int i, int t){
        sprite.setPosition(xPosition, yPosition);
        sprite.setTextureRect(IntRect(0, 0, 32, 32));

        
	txt.setString((char)(i));
	txt.setCharacterSize(t);
	txt.setColor(Color::White);
  }

void setPosition(float xPosition, float yPosition){
  sprite.setPosition(xPosition, yPosition);
}

void update(){
  txt.setPosition(sprite.getPosition());
}
  
};

#endif
  

  
