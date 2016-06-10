#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
using namespace sf;



#define R Color(255,0,0)
#define B Color(0,0,255)
#define G Color(0,255,0)
#define J Color(255,255,0)




// void cartes(std::string nom,int largeur,int longueur, int x, int y){
//   //std::string tmp;
//   //tmp=nom;
//   RectangleShape tmp;
//   tmp.setSize(Vector2f(largeur,longueur));
//   tmp.setFillColor(Color(255,255,255));
//   tmp.setOutlineThickness(1);
//   tmp.setOutlineColor(Color::White);
//   tmp.move(x,y);
//   tmp.setTexture(&cartes);
// }

	  
int main(){

  Texture cartes;

if(!cartes.loadFromFile("fond-carte.png")){
   std::cout<<"Pas importée"<<std::endl;
   return 0;
  }
    
  RenderWindow window(VideoMode(1000, 800), "SFML works!",Style::Default);
  
   RectangleShape pioche(Vector2f(80.0,140.0));
   pioche.setFillColor(Color(255,255,255));
   pioche.setOutlineThickness(1);
   pioche.setOutlineColor(Color(255,255,255));
   pioche.move(600,350);
   pioche.setTexture(&cartes);
  
    
     RectangleShape shapeUp(Vector2f(90,135));
     shapeUp.setFillColor(Color(255,255,255));
     //shapeUp.setOutlineThickness(2);
     //shapeUp.setOutlineColor(Color(250, 250, 250));
     shapeUp.move(500,5);
     shapeUp.setTexture(&cartes);
   
    
    
     RectangleShape shapeLeft(Vector2f(90,135));
     shapeLeft.setFillColor(Color(255,255,255));
     //shapeLeft.setOutlineThickness(2);
     //shapeLeft.setOutlineColor(Color(250, 250, 250));
     shapeLeft.move(5,475);
     shapeLeft.rotate(-90);
     shapeLeft.setTexture(&cartes);
    
     RectangleShape shapeRight(Vector2f(90,135));
     shapeRight.setFillColor(Color(255,255,255));
     //shapeRight.setOutlineThickness(2);
     //shapeRight.setOutlineColor(Color(250, 250, 250));
     shapeRight.move(965,395);
     shapeRight.rotate(90);
     shapeRight.setTexture(&cartes);

     RectangleShape shapeTas(Vector2f(90,135));
     shapeTas.setFillColor(Color(0,200,0));
     shapeTas.setOutlineThickness(2);
     shapeTas.setOutlineColor(Color::White);
     shapeTas.move(500,350);
    
    
    
    Font font;
    font.loadFromFile("arial.ttf");
    
    
    Text p;
    p.setFont(font);
    p.setString("Pioche");
    p.setCharacterSize(24);
    p.setColor(Color::White);
    p.move(600,300);
    
    Text l;
    l.setFont(font);
    l.setString("(Nb carte jl)");
    l.setCharacterSize(24);
    l.setColor(Color::White);
    l.move(5,350);

    Text r;
    r.setFont(font);
    r.setString("(Nb carte jr)");
    r.setCharacterSize(24);
    r.setColor(Color::White);
    r.move(850,350);

    Text u;
    u.setFont(font);
    u.setString("(Nb carte ju)");
    u.setCharacterSize(24);
    u.setColor(Color::White);
    u.move(500,140);

    Text test;
    test.setFont(font);
    test.setString("TEST !!");
    test.setCharacterSize(24);
    test.setColor(Color::White);

    Text tas;
    tas.setFont(font);
    tas.setString("Tas");
    tas.setCharacterSize(24);
    tas.setColor(Color::White);
    tas.move(510,300);
   
 
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)
                window.close();
        }
	window.clear (Color(0,200,0,150));
	window.draw(pioche);
    window.draw(shapeUp);
	window.draw(shapeLeft);
    window.draw(shapeRight);
	window.draw(shapeTas);
	
	if (Mouse::isButtonPressed(Mouse::Left)){
	// float x,y;
	//Vector2f positionSouris = static_cast<Vector2f>(Mouse::getPosition(window));
	//Vector2f positionPioche = pioche.getPosition();
	//if(positionSouris.xpositionPioche){
		window.draw(test);
		//}
	 }
	//dessinerCarte(80.0,135.0,100,100);
	
	int x=5;
	int y=700;
	for(int i=0;i<10;i++){
	  RectangleShape carte(Vector2f(80,135));
	  carte.setFillColor(B);
	  carte.setOutlineThickness(1);
	  carte.setOutlineColor(Color::White);
	  carte.move(x,y);
	  x=x+95;
	  window.draw(carte);
	}
       	window.draw(p);
	window.draw(l);
	window.draw(r);
	window.draw(u);
	window.draw(tas);
	window.display();
	
}    

    return 0;


}

