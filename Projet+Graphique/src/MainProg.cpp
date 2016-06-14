#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
#include "Jeu.hpp"
#include "Joueur.hpp"
#include "Cartes.hpp"
#include "Textes.hpp"
#include "Carte.hpp"



#define rouge Color(255,0,0)
#define bleu Color(0,0,255)
#define vert Color(0,255,0)
#define jaune Color(255,255,0)
#define X 800 //largeur de la fenetre
#define Y 500 //hauteur de la fenetre
#define Z X/30 //Taille de la police



int main(){
  
  // Create the main window
  RenderWindow window(VideoMode(X,Y), "UNO");
  
  Font font;
  if (!font.loadFromFile("arial.ttf")){
    return EXIT_FAILURE;
  }
  
  Texture texture;
  if (!texture.loadFromFile("fond-carte.png")) {
    return EXIT_FAILURE;
  }
  
  
  
  Cartes pioches(Y/10,X/10,255,255,255);
  pioches.setPosition(3*X/5,2*Y/5);
  pioches.rect.setTexture(&texture);
  
  
  Cartes jHaut(Y/10,X/10,255,255,255);
  jHaut.setPosition(X/2,5);
  jHaut.rect.setTexture(&texture);
  
  Cartes jGauche(X/10,Y/10,255,255,255);
  jGauche.setPosition(5,Y/2);
  jGauche.rect.setTexture(&texture);
  
  Cartes jDroite(X/10,Y/10,255,255,255);
  jDroite.setPosition(9*X/10,Y/2);
  jDroite.rect.setTexture(&texture);
  
  Cartes tas(Y/10,X/10,0,200,0);
  tas.setPosition(X/2,2*Y/5);
  
  Sprite sprite(texture);
  sprite.setTextureRect(IntRect(0, 0, Y/10, X/10));

  
  
  Text leftTxt("1",font,Z);
  leftTxt.setColor(Color::White);
  leftTxt.move(10,Y/2);
  
  Text rightTxt("9",font,Z);
  rightTxt.setColor(Color::White);
  rightTxt.move(9*X/10,Y/2);
  
  Text upTxt("3",font,Z);
  upTxt.setColor(Color::White);
  upTxt.move(X/2,5);
  
  
  Text piocheTxt("Pioche", font, Z);
  piocheTxt.setColor(Color::White);
  piocheTxt.move(3*X/5,Y/3);
  
  Text tasTxt("Tas", font, Z);
  tasTxt.setColor(Color::White);
  tasTxt.move(X/2,(2*Y/5)-5);
  
  ;
  
  // Start the game loop
  while (window.isOpen()){
    
    
    // Process events
    Event event;
    while (window.pollEvent(event)){

      // Close window: exit
      if (event.type == Event::Closed){
	window.close();
      }
      // Escape pressed: exit
      if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape){
	window.close();
      }

      if(Mouse::isButtonPressed(Mouse::Left)){
	  window.close();
      }
      
      Jeu j;
      Carte c;
      c=j.carteCourante();
      j.creerJoueur();
      std::cout << "carte courante est : "<< c.getValeur() << c.getCouleur() << std::endl;
      j.afficher();
      j.jouer();
    }
    
    window.clear(Color(0,200,0,150));

    //update des cartes
    pioches.update();
    jHaut.update();
    jDroite.update();
    jGauche.update();
    tas.update();

    int x=5;
    int y=Y-2*(Y*10/100);
    for(int i=0;i<10;i++){
      RectangleShape carte(Vector2f(Y/10,X/10));
      carte.setFillColor(Color::White);
      carte.setOutlineThickness(1);
      carte.setOutlineColor(Color::White);
      carte.move(x,y);
      window.draw(carte);
      x=x+X/10;
      
    }
        
    //Affichage des cartes
    window.draw(pioches.rect);
    window.draw(pioches.sprite);
    window.draw(jHaut.rect);
    window.draw(jHaut.sprite);
    window.draw(jDroite.rect);
    window.draw(jDroite.sprite);
    window.draw(jGauche.rect);
    window.draw(jGauche.sprite);
    window.draw(tas.sprite);
    window.draw(tas.rect);
    
    // window.draw(joueur.sprite);
    // window.draw(joueur.rect);
    window.draw(piocheTxt);
    window.draw(tasTxt);
    window.draw(leftTxt);
    window.draw(rightTxt);
    window.draw(upTxt);
    
    window.display();
  }
  return 0;
}



