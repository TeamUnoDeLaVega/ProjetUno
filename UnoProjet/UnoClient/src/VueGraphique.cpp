#include "VueGraphique.hpp"

int x=15;
int _pas=X/15;
int y=Y-2*(Y*10/100);

std::string login("");
std::string ip("");

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
  
   Texture background;
  if(!background.loadFromFile("background3.png")){
	  std::cout<<"erreur"<<std::endl;
  }
  
  Sprite bg(background);
  bg.setTexture(background);
   window.draw(bg);
   
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
  
  
  
    
     
}

void VueGraphique::modifierX(){
  x=x+X/10;
}

int VueGraphique::getX(){
  return x ;
}

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
}

void VueGraphique::remplirCarteCourante(){
  _joueur._carteCourante=_client.envoyerCarteCourante();
}

void VueGraphique::initialiserClient(){
 
  std::string name = login;
  _client.setName(name);
  unsigned short port=5550;
  
  sf::Socket::Status status;
  status=_client.connect(ip, port);
  if(status!=sf::Socket::Done)
    {
      std::cout<<"Sorry we couldn't connect\n";
      return;
    }
  _client.send(INITIAL_NAME_DATA, name);
 

}

void VueGraphique::initialiserConnect(){
  
  Texture textureConnect;
  if(!textureConnect.loadFromFile("fond-connect.png")){
    std::cout<<"Pas de texture!!"<<std::endl;
  }
  
  Font font;
  if(!font.loadFromFile("arial.ttf")){
    std::cout<<"Pas de police!!"<<std::endl;
  }
  
  RectangleShape win;
  win.setSize(Vector2f(X,Y));
  win.setPosition(X/100,Y/100);
  win.setTexture(&textureConnect);
  window.draw(win);
  
  Text IP("AdresseIP: ",font,X/15);
  IP.setPosition(10,50);
  IP.setColor(Color::Black);
  window.draw(IP);
  
  Text pseudo("Pseudo: ",font,X/15);
  pseudo.setPosition(10,0);
  pseudo.setColor(Color::Black);
  window.draw(pseudo);
}


void VueGraphique::afficherNbCarteGauche(std::string nbCarte){
	Font font;
	if (!font.loadFromFile("arial.ttf")){
		std::cout << "erreur" << std::endl;
	}
	
	Text leftTxt(nbCarte,font,Z);
	leftTxt.setColor(Color::White);
	leftTxt.move(100,Y/2);
	window.draw(leftTxt);
}

void VueGraphique::afficherNbCarteDroite(std::string nbCarte){
	Font font;
	if (!font.loadFromFile("arial.ttf")){
		std::cout << "erreur" << std::endl;
	}
	Text rightTxt(nbCarte,font,Z);
	rightTxt.setColor(Color::White);
	rightTxt.move(8*X/10+30,Y/2);
	window.draw(rightTxt);
}

void VueGraphique::afficherNbCarteHaut(std::string nbCarte){
	Font font;
	if (!font.loadFromFile("arial.ttf")){
		std::cout << "erreur" << std::endl;
	}
	Text upTxt(nbCarte,font,Z);
	upTxt.setColor(Color::White);
	upTxt.move(X/2-25,5);
	window.draw(upTxt);
}

void VueGraphique::runEnd(){
	
	Texture winner;
	if (!winner.loadFromFile("winner.png")){
		std::cout << "erreur" << std::endl;
    }
    
    Texture looser;
    if(!looser.loadFromFile("looser.png")){
		std::cout<<"erreur"<<std::endl;
	}
      
    RectangleShape fin(Vector2f(2*X/3,2*Y/3));
    fin.move(150,100);
	
	if(_client._vainqueur==login) fin.setTexture(&winner);
	else fin.setTexture(&looser);
	window.draw(fin);
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
    std::vector<Carte> pl=_client.envoyerCarteJoueur();
   for(int i=0;i<(int)pl.size();i++){
     ajouterUneCarte(pl[i],i*_pas+x,8*Y/10);
   }
}

void VueGraphique::carteCourante(Carte c){
  ajouterUneCarte(c,X/2,2*Y/5);
}

void VueGraphique::run(){
	
  initialiserClient();
  std::vector<Carte> pl;
  int indice;
  int noire=0;
  
 
  
  CircleShape jeton(10);
  jeton.setFillColor(sf::Color(150, 50, 250));
  jeton.setOutlineThickness(10);
  jeton.setOutlineColor(Color(250, 150, 100));
  
    int position;
    while (window.isOpen()){
     // Process events
    Event event;
    while (window.pollEvent(event)){
		int id=_client._idJoueurCourant;
		if(_client.envoyerCarteCourante().getValeur()==100) 
		{
			if(_client._id==1) jeton.setPosition(X/2,y-50);
			if(_client._id==2) jeton.setPosition(9*X/10,2*Y/5);
			if(_client._id==3) jeton.setPosition(3*X/5,Y/10);
			if(_client._id==4) jeton.setPosition(5,2*Y/5);
			
		}
	

	
	if(_client._id==1){
		
		if(id==1) jeton.setPosition(X/2,y-50);
		if(id==2) jeton.setPosition(5,2*Y/5);
		if(id==3) jeton.setPosition(3*X/5,Y/10);
		if(id==4) jeton.setPosition(9*X/10,2*Y/5);
		afficherNbCarteDroite(_client.nbCartesJoueur4);
		afficherNbCarteGauche(_client.nbCartesJoueur2);
		afficherNbCarteHaut(_client.nbCartesJoueur3);
	}
	
	if(_client._id==2){
		
		if(id==2) jeton.setPosition(X/2,y-50);
		if(id==3) jeton.setPosition(5,2*Y/5);
		if(id==4) jeton.setPosition(3*X/5,Y/10);
		if(id==1) jeton.setPosition(9*X/10,2*Y/5);
		//afficherNbCarteDroite(_client.nbCartesJoueur1);
		//afficherNbCarteGauche(_client.nbCartesJoueur3);
		//afficherNbCarteHaut(_client.nbCartesJoueur4);
	}
	
	if(_client._id==3){
		
		if(id==3) jeton.setPosition(X/2,y-50);
		if(id==4) jeton.setPosition(5,2*Y/5);
		if(id==1) jeton.setPosition(3*X/5,Y/10);
		if(id==2) jeton.setPosition(9*X/10,2*Y/5);
		//afficherNbCarteDroite(_client.nbCartesJoueur2);
		//afficherNbCarteGauche(_client.nbCartesJoueur4);
		//afficherNbCarteHaut(_client.nbCartesJoueur1);
	}
	
	if(_client._id==4){
		
		if(id==4) jeton.setPosition(X/2,y-50);
		if(id==1) jeton.setPosition(5,2*Y/5);
		if(id==2) jeton.setPosition(3*X/5,Y/10);
		if(id==3) jeton.setPosition(9*X/10,2*Y/5);
		//afficherNbCarteDroite(_client.nbCartesJoueur3);
		//afficherNbCarteGauche(_client.nbCartesJoueur1);
		//afficherNbCarteHaut(_client.nbCartesJoueur2);
	}	
	
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
	 if(noire==1){
	    RectangleShape rouge(Vector2f(Y/10,Y/10));
	    rouge.move(100,300);
	    FloatRect positionrouge = rouge.getGlobalBounds();
	    if(positionrouge.contains((Vector2f)positionSouris)){
	      _client.envoyerCarte(Carte(pl[indice].getValeur(),"r"));
	      noire=0;
	      break;
	     
	    }
	   
	    RectangleShape bleu(Vector2f(Y/10,Y/10));
	     bleu.move(150,300);
	    FloatRect positionbleu = bleu.getGlobalBounds();
	    if(positionbleu.contains((Vector2f)positionSouris)){
	    _client.envoyerCarte(Carte(pl[indice].getValeur(),"b"));
	    noire=0;
	    break;
	    }
             RectangleShape vert(Vector2f(Y/10,Y/10));
	    vert.move(100,350);
	    FloatRect positionvert = vert.getGlobalBounds();
	    if(positionvert.contains((Vector2f)positionSouris)){
	    _client.envoyerCarte(Carte(pl[indice].getValeur(),"v"));
	    noire=0;
	    break;}
	   RectangleShape jaune(Vector2f(Y/10,Y/10));
	   jaune.move(150,350);
	    FloatRect positionjaune = jaune.getGlobalBounds();
	    if(positionjaune.contains((Vector2f)positionSouris)){
	    _client.envoyerCarte(Carte(pl[indice].getValeur(),"j"));
	    noire=0;
	    break;}
	  }
    	for(int i=0;i<(int)pl.size();i++){
    	  int position=i*_pas+x;
    	  RectangleShape pCarte(Vector2f(Y/10,X/10));
    	  pCarte.setPosition(position,8*Y/10);
    	  FloatRect positionCarte = pCarte.getGlobalBounds();
	  
	  
    	  //std::cout<<positionSouris.x<<";"<<positionSouris.y<<std::endl;
    	if(positionCarte.contains((Vector2f)positionSouris)){
    	  if (_client.getFlag()==1){
	    Carte c=_client.envoyerCarteCourante();
	    if((pl[i].getValeur() == c.getValeur()) || (pl[i].getCouleur() == c.getCouleur()) || (pl[i].getCouleur()=="n")){
	      if(pl[i].getCouleur() == "n") {noire=1; indice=i;_client.setFlag(0);}
	      else {
		_client.envoyerCarte(pl[i]);
		std::cout<<"============="<<std::endl;
		std::cout<<"Carte: "<< pl[i].getValeur()<<pl[i].getCouleur() <<std::endl;
		_client.setFlag(0);
	      }
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
    
  
    window.clear();
    initialiser();
    
   
    window.draw(jeton);
    std::string msg;
    _client.receive(msg);
  
    remplirCarteCourante();
    carteCourante(_client.envoyerCarteCourante());
    afficherCartesJoueur();
    if(noire ==1) choixCouleur();
    if(_client._id==1){
		afficherNbCarteDroite(_client.nbCartesJoueur4);
		afficherNbCarteGauche(_client.nbCartesJoueur2);
		afficherNbCarteHaut(_client.nbCartesJoueur3);
	}
	if(_client._id==2){
		afficherNbCarteDroite(_client.nbCartesJoueur1);
		afficherNbCarteGauche(_client.nbCartesJoueur3);
		afficherNbCarteHaut(_client.nbCartesJoueur4);
	}
	if(_client._id==3){
		afficherNbCarteDroite(_client.nbCartesJoueur2);
		afficherNbCarteGauche(_client.nbCartesJoueur4);
		afficherNbCarteHaut(_client.nbCartesJoueur1);
	}
	if(_client._id==4){
		afficherNbCarteDroite(_client.nbCartesJoueur3);
		afficherNbCarteGauche(_client.nbCartesJoueur1);
		afficherNbCarteHaut(_client.nbCartesJoueur2);
	}
    if(_client._vainqueur!="") runEnd();
   
    window.display();
  }
   
}

  void VueGraphique::runConnect(){
  window.setSize(Vector2u(2*X/3,2*Y/3));
  
  Font font;
  if(!font.loadFromFile("arial.ttf")){
    std::cout<<"Pas de police!!"<<std::endl;
  }
  
  int entre = 0;
  
  //Zone de saisie du pseudo
  RectangleShape zoneSaisiePseudo(Vector2f(X/2,Y/10));
  zoneSaisiePseudo.setOutlineThickness(2);
  zoneSaisiePseudo.setOutlineColor(Color::Black);
  zoneSaisiePseudo.setPosition(X/4+10,5);
  FloatRect posPseudo = zoneSaisiePseudo.getLocalBounds();
  
  //Zone de saisie de l'adresse IP
  RectangleShape zoneSaisieIp(Vector2f(X/2,Y/10));
  zoneSaisieIp.setOutlineThickness(2);
  zoneSaisieIp.setOutlineColor(Color::Black);
  zoneSaisieIp.setPosition(X/3+10,Y/10+7);
  FloatRect posIp = zoneSaisieIp.getLocalBounds();
  
  RectangleShape boutonConnect(Vector2f(Y/2+5,X/10));
  boutonConnect.setOutlineThickness(2);
  boutonConnect.setOutlineColor(Color(125,125,125));
  boutonConnect.move(2*X/3,3*Y/4);
  boutonConnect.setFillColor(Color::White);
  FloatRect posBouton = boutonConnect.getGlobalBounds();
  
  Text connect("Connexion",font,X/15);
  connect.setColor(Color::Black);
  connect.move(2*X/3+5,3*Y/4+5);
  
  while (window.isOpen()){
    // Process event
    Vector2i positionSouris = Mouse::getPosition(window); 
    Event event;
    while (window.pollEvent(event)){
      
      if(entre == 0){
	zoneSaisiePseudo.setOutlineThickness(5);
	zoneSaisiePseudo.setFillColor(Color(125,125,125));
	zoneSaisieIp.setOutlineThickness(2);
	zoneSaisieIp.setFillColor(Color::White);
      }
      
      if (entre == 1){
	zoneSaisiePseudo.setOutlineThickness(2);
	zoneSaisiePseudo.setFillColor(Color::White);
	zoneSaisieIp.setOutlineThickness(5);
	zoneSaisieIp.setFillColor(Color(125,125,125));	
      }
      
      if(login.size() != 0){
		boutonConnect.setFillColor(Color::Green);
      }else{
	boutonConnect.setFillColor(Color::White);
      }
      
      // Close window: exit
      if (event.type == Event::Closed){
	window.close();
      }
      
      // Escape pressed: exit
      if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape){
	window.close();
      } 
      
      switch (event.type){
	
	//Gestion du clavier
      case Event::TextEntered:
	
	//login
	if(entre==0 && login.size()<8){
	  if((event.text.unicode >64 && event.text.unicode <91) || (event.text.unicode>96 && event.text.unicode)){
	    login+=static_cast<char>(event.text.unicode);	
	  }
	}
	
	//Efface le dernier caractere du pseudo
	if(entre == 0 && event.text.unicode == 8){
	  login = login.substr(0,login.size()-1);
	}
	
	//passage à la saisie del'IP
	if(entre == 0 && (event.text.unicode == 10 || event.text.unicode == 13 || event.text.unicode == 9)){
	  entre=1;
	  std::cout<<entre<<std::endl;
	  break;	
	}
	
	//IP
	if(entre==1 && ip.size()<16){
	  if((event.text.unicode > 47 && event.text.unicode < 58 ) || (event.text.unicode == 46)){
	    ip+=static_cast<char>(event.text.unicode);
	    break;
	  }
	}
	
	//Efface le dernier caractere de l'IP
	if(entre == 1 && event.text.unicode == 8){
	  ip = ip.substr(0,ip.size()-1);
	  break;
	}
	
	//Si backspace retour à la saisie du pseudo
	if(entre == 1 && (event.text.unicode == 32 || event.text.unicode == 9)){
	  entre=0;
	  break;
	}
	
	if(entre == 2 && event.text.unicode == 9){
	  entre = 1;
	  break;
	}
	
	if(entre == 1 && (event.text.unicode == 10 || event.text.unicode == 13)){
	  entre = 2;
	  window.close();
	  break;
	  //return login;
	  //return ip;
	}
	
      case Event::MouseButtonPressed:
	
	
	switch(event.key.code){  
	  
	case Mouse::Left:
	  
	  std::cout<<positionSouris.x<<":"<<positionSouris.y<<std::endl;
	  
	  if((posPseudo.contains((Vector2f)positionSouris)) && entre == 1){
		  entre = 0;
		  break;	
	  }
	  
	  if((posIp.contains((Vector2f)positionSouris)) && entre == 0){
	    entre = 1;
	   break;
	  }
	  
	  if(posBouton.contains((Vector2f)positionSouris)){
	    //window.close();
	    std::cout<<"bonjour"<<std::endl;
	    std::cout<<posBouton.top<<":"<<posBouton.left<<std::endl;
	    //initialiserClient();
	    break;
	  }
	  
	  
	default:
	  break;
	}
	
      default:
	break;
      }
      
    }
    
    Text inputPseudo(login,font,X/15);
    inputPseudo.move(X/4+20,0);
    inputPseudo.setColor(Color::Black);
    
    Text adresseIP(ip,font,X/15);
    adresseIP.move(X/3+10,Y/10);
    adresseIP.setColor(Color::Black);
    
    
    window.clear();
    initialiserConnect();
    window.draw(zoneSaisiePseudo);
    window.draw(zoneSaisieIp);
    
    window.draw(boutonConnect);
    window.draw(connect);
    
    window.draw(inputPseudo);
    window.draw(adresseIP);
    
    window.display();
  }
}
