#include "VueGraphique.hpp"



int y=Y-2*(Y*10/100);

VueGraphique::VueGraphique() : window(sf::VideoMode(X,Y), "UNO") {}


void VueGraphique::initialiser(){
  Font font;
  if (!font.loadFromFile("arial.ttf")){
    std::cout << "erreur" << std::endl;
  }
  
  Texture texture;
  if (!texture.loadFromFile("fond-carte.png")) {
     std::cout << "erreur" << std::endl;
  }
  
  
  
  Cartes pioches(Y/10,X/10,255,255,255);
  pioches.setPosition(3*X/5,2*Y/5);
  pioches.rect.setTexture(&texture);
  pioches.update();
  window.draw(pioches.rect);
  window.draw(pioches.sprite);

  
  
  Cartes jHaut(Y/10,X/10,255,255,255);
  jHaut.setPosition(X/2,5);
  jHaut.rect.setTexture(&texture);
  jHaut.update();
  window.draw(jHaut.rect);
  window.draw(jHaut.sprite);
  
  Cartes jGauche(X/10,Y/10,255,255,255);
  jGauche.setPosition(5,Y/2);
  jGauche.rect.setTexture(&texture);
  jGauche.update();
  window.draw(jGauche.rect);
  window.draw(jGauche.sprite);
  
  Cartes jDroite(X/10,Y/10,255,255,255);
  jDroite.setPosition(9*X/10,Y/2);
  jDroite.rect.setTexture(&texture);
  jDroite.update();
  window.draw(jDroite.rect);
  window.draw(jDroite.sprite);
  
  Cartes tas(Y/10,X/10,0,0,0);
  tas.setPosition(X/2,2*Y/5);
  tas.update();
  tas.rect.setFillColor(Color::White);
  tas.sprite.setColor(Color::White);
  window.draw(tas.sprite);
  window.draw(tas.rect);
  
  Sprite sprite(texture);
  sprite.setTextureRect(IntRect(0, 0, Y/10, X/10));

  
  
  Text leftTxt("1",font,Z);
  leftTxt.setColor(Color::White);
  leftTxt.move(10,Y/2);
  window.draw(leftTxt);
  
  Text rightTxt("9",font,Z);
  rightTxt.setColor(Color::White);
  rightTxt.move(9*X/10,Y/2);
  window.draw(rightTxt);
  
  Text upTxt("3",font,Z);
  upTxt.setColor(Color::White);
  upTxt.move(X/2,5);
  window.draw(upTxt);
  
  
  Text piocheTxt("Pioche", font, Z);
  piocheTxt.setColor(Color::White);
  piocheTxt.move(3*X/5,Y/3);
  window.draw(piocheTxt);

  
  Text tasTxt("Tas", font, Z);
  tasTxt.setColor(Color::White);
  tasTxt.move(X/2,(2*Y/5)-5);
  window.draw(tasTxt);
 


  }

void VueGraphique::modifierX(){
  x=x+X/10;
}

int VueGraphique::getX(){
  return x ;
}

// void VueGraphique::remplir(){
//   player.setIdJoueur(1);
//   for (int i=0;i<4;i++) player._cartesJoueur.push_back(Carte(i,"b"));
//   for (int i=0;i<3;i++) player._cartesJoueur.push_back(Carte(i,"v"));
  
// }
    

void VueGraphique::ajouterUneCarte(Carte c,int x,int y){
     std::ostringstream convert;
     convert << c.getValeur();
     std::string nomimage=convert.str()+c.getCouleur()+".png";
 
      RectangleShape carte(Vector2f(Y/10,X/10));
      Texture texture1;
      if (!texture1.loadFromFile(nomimage)) {
	std::cout << "erreur" << std::endl;
      }
  
      carte.setTexture(&texture1);   
      carte.setOutlineThickness(1);
      carte.setOutlineColor(Color::White);
      carte.setPosition(x,y);
      window.draw(carte);
      //modifierX();
      // x=x+X/10;
      
   }

// void VueGraphique::setClient(Client c ) {
//   _client=c;
// }


// void VueGraphique::remplir(){
//   std::vector<Carte> pl=_client.envoyerCarteJoueur();
//   for(int i=0;i<(int)pl.size();i++) _joueur._cartesJoueur.push_back(pl[i]);
// }

void VueGraphique::remplirCarteCourante(){
  _joueur._carteCourante=_client.envoyerCarteCourante();
}


void VueGraphique::initialiserClient(){
 
  std::string name;
  std::cout << "your name " << std::endl;
  std::getline(std::cin,name);
  _client.setName(name);
  unsigned short port=5550;
	
  sf::Socket::Status status;
  status=_client.connect(sf::IpAddress::getLocalAddress(), port);
  if(status!=sf::Socket::Done)
    {
      std::cout<<"Sorry we couldn't connect\n";
      return;
	}
  _client.send(INITIAL_NAME_DATA, name);
 

}



void VueGraphique::choixCouleur(){
  sf::RectangleShape rouge(sf::Vector2f(Y/10,Y/10));
  rouge.setFillColor(sf::Color(250,0,0));
  rouge.move(100,300);
  sf::RectangleShape bleu(sf::Vector2f(Y/10,Y/10));
  bleu.setFillColor(sf::Color(0,0,250));
  bleu.move(150,300);
  sf::RectangleShape vert(sf::Vector2f(Y/10,Y/10));
  vert.setFillColor(sf::Color(0,250,0));
  vert.move(100,350);
  sf::RectangleShape jaune(sf::Vector2f(Y/10,Y/10));
  jaune.setFillColor(sf::Color(250,250,0));
  jaune.move(150,350);
  window.draw(rouge);
  window.draw(bleu);
  window.draw(vert);
  window.draw(jaune);
}
  




void VueGraphique::afficher(){
  std::cout << "tableau du joueur " << std::endl;
  for(int i=0;i<(int)_joueur._cartesJoueur.size();i++){
    std::cout << _joueur._cartesJoueur[i].getValeur() <<_joueur. _cartesJoueur[i].getCouleur() << ";" ;
  }
  std::cout << " " << std::endl;
}

 void VueGraphique::afficherCartesJoueur(){
   //  remplir();
    std::vector<Carte> pl=_client.envoyerCarteJoueur();
   for(int i=0;i<(int)pl.size();i++){
     ajouterUneCarte(pl[i],i*_pas+x,8*Y/10);
   }
}




// void VueGraphique::setCarteCouranteGraphique(Carte c ){
//   carteCouranteGraphique.setCouleur(c.getCouleur());
//   carteCouranteGraphique.setValeur(c.getValeur());
  
// }
  

void VueGraphique::carteCourante(Carte c){
  // FloatRect positionTas = tas.rect.getLocalBounds();
  ajouterUneCarte(c,X/2,2*Y/5);
}



// void VueGraphique::carteJoueur(Carte c){
//   // FloatRect positionTas = tas.rect.getLocalBounds();
//   ajouterUneCarte(c,x,410);
//   modifierX();

// }
  


void VueGraphique::run(){
  initialiserClient();
  std::vector<Carte> pl;
  int noire=0;
    int position;
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
      
    
  
      
    Vector2i positionSouris = Mouse::getPosition(window);
    
    switch(event.type){
    case Event::MouseButtonPressed:
      
      //FloatRect positionCarte = carte.getGlobalbounds();
      switch(event.key.code){
      case Mouse::Left:
    	 pl=_client.envoyerCarteJoueur();
    	for(int i=0;i<(int)pl.size();i++){
    	  int position=i*_pas+x;
    	  RectangleShape pCarte(Vector2f(Y/10,X/10));
    	  pCarte.setPosition(position,8*Y/10);
    	  FloatRect positionCarte = pCarte.getGlobalBounds();
	  if(noire==1){
	   RectangleShape rouge(Vector2f(Y/10,Y/10));
	   rouge.move(100,300);
	    FloatRect positionrouge = rouge.getGlobalBounds();
	    std::cout << "rouge" << std::endl;
	    noire=0;
	  }
	  
    	  //std::cout<<positionSouris.x<<";"<<positionSouris.y<<std::endl;
    	if(positionCarte.contains((Vector2f)positionSouris)){
    	  if (_client.getFlag()==1){
	    Carte c=_client.envoyerCarteCourante();
	    if((pl[i].getValeur() == c.getValeur()) || (pl[i].getCouleur() == c.getCouleur()) || (pl[i].getCouleur()=="n")){
	      if(pl[i].getCouleur() == "n") noire=1;
	      _client.envoyerCarte(pl[i]);
	      std::cout<<"============="<<std::endl;
	      std::cout<<"Carte: "<< pl[i].getValeur()<<pl[i].getCouleur() <<std::endl;
	      _client.setFlag(0);
	    }
	  }
    	  break;
    	}
    	}
    	    default:
    	     break;
    	}
    default:
      break;
      }
      
      
    
    }
    
  
    window.clear(Color(0,200,0,150));
    initialiser();
    std::string msg;
    _client.receive(msg);
    // std::cout << _client.getFlag() << std::endl;
    remplirCarteCourante();
    carteCourante(_client.envoyerCarteCourante());
    afficherCartesJoueur();
    if(noire ==1) choixCouleur();
   // afficherCartesJoueur(player);
    // ajouterUneCarte(Carte(8,"j"),5,Y);
    // ajouterUneCarte(Carte(8,"r"),5+X/15,Y);
    window.display();
  }
   
}

  
