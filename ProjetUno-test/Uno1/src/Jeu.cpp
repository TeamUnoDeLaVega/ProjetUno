#include "Jeu.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <random>


Jeu::Jeu(){
  int nb=0;
  std::string couleur;
  while(nb < 4){
    if (nb == 0) couleur ="v";
    if (nb == 1) couleur ="b";
    if (nb == 2) couleur ="j";
    if (nb == 3) couleur ="r";
    
  for(int i=0;i<2;i++){
    for(int j=1;j<10;j++){
      _paquet.push_back(Carte(j,couleur));
    }
    _paquet.push_back(Carte(22,couleur)); //22== +2
    _paquet.push_back(Carte(55,couleur)); //55==Passe ton tour 
    _paquet.push_back(Carte(99,couleur));  //99==Inversement de sense
  }

  _paquet.push_back(Carte(0,couleur));
 // _paquet.push_back(Carte(44,"n")); //44 == +4
  //_paquet.push_back(Carte(11,"n")); //11 == joker
    
  nb++;
  }
 
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle ( _paquet.begin(), _paquet.end(),g );
  _sens=1;
  _joueurCourant=1;
  _carteCourante=carteCourante();

}


Carte Jeu::carteCourante(){
  for(int i=0;i<(int)_paquet.size();i++){
    if (_paquet[i].getValeur()<10) {
      _carteCourante=_paquet[i];
      supprimer(_carteCourante);
      historique(_carteCourante);
      return _carteCourante;
			 
    }
  }
}




/*void Jeu::distribuerCarte(Joueur *j){
   for (int i=0;i<7;i++) {
    Carte c=getCarte(i);
    supprimer(c);
    j->_cartesJoueur.push_back(c);
    //envoyerCarte(&j,c);
  }
}*/

Carte Jeu::distribuerCarte(Joueur *j,int i){
    Carte c=getCarte(i);
    j->_cartesJoueur.push_back(c);
    supprimer(c);
    return c;
}

void Jeu::creerJoueur(Joueur j){
  _players.push_back(j);
}



void Jeu::supprimer(Carte  c ){
  int pos=0;
  int nb=(int)_paquet.size();
  for(int i=0;i<(int)_paquet.size();i++){
    if((_paquet[i].getValeur() == c.getValeur()) && (_paquet[i].getCouleur() == c.getCouleur())){
      pos=i;
      break;
    }
  }
  std::swap (_paquet[pos],_paquet[nb-1]);
    _paquet.pop_back();
    historique(c);
    }

void Jeu::afficher()const{
  for(int i=0;i<4;i++){
    std::vector<Carte> pl=_players[i].getCartesJoueur();
     int id=_players[i].getIdJoueur();
       std::cout << id << std::endl;
    for(int j=0;j<(int)pl.size();j++){
      std::cout << pl[j].getValeur() << pl[j].getCouleur() << ";";
  }
  std::cout << "" << std::endl;
}
}

int Jeu::coupValide(Carte c) const {
  if (c.getCouleur() == "n") return 0 ;
  if((_carteCourante.getValeur() == c.getValeur()) || (_carteCourante.getCouleur() == c.getCouleur())) return 0;
  else return 1;
}


 Carte Jeu::getCarte(int indice){
  return _paquet[indice];
 }

void Jeu::modifierSens(){
  if (_sens==1) _sens =-1;
  else _sens=1;
}

int Jeu::getSens()const{
  return _sens ;
}


void Jeu::modifierJoueurCourant(){
  int sens=getSens();
  if (sens==1){
     _joueurCourant++;
    if(_joueurCourant > 4) _joueurCourant = 1;
  }
  if(sens==-1){
     _joueurCourant--;
    if(_joueurCourant <  1) _joueurCourant = 4;
   
  }
    
}

int Jeu::getJoueurCourant() const {
  return _joueurCourant;
}


 void Jeu::historique(Carte c){
  _historique.push_back(c);
 }

Carte Jeu::modifierCouleur(Carte c,std::string couleur){
   c.setCouleur(couleur);
   return c;
   }

void Jeu::modifierCarteCourante(Carte c){
  _carteCourante=c;
}

Carte Jeu::getCarteCourante() const{
  return _carteCourante ;
}

Carte Jeu::setCarteCourante(Carte c) {
  _carteCourante=c ;
}
// // void piocherUneCarte(Joueur *j){
// //   Carte 
  


void Jeu::regleDuJeux(Joueur *j, Carte c){
  //int vrai=coupValide(c);
  //if (vrai == 0){
    //if (c.getValeur() < 10){
          modifierJoueurCourant();
          modifierCarteCourante(c);
          supprimerCarteJoueur(j,c);
    //}
    
   /* if(c.getValeur() > 10) {
      if(c.getValeur() == 22) {    // si le joueur joue la carte +2 
	 modifierJoueurCourant();
	int id= getJoueurCourant();
	for(int i=0;i<2;i++) ajouterCarte(&_players[id-1]);
	modifierCarteCourante(c);
      }

      if(c.getValeur() == 44) {   // si le joueur joue la carte +4
	modifierJoueurCourant();
	int id=getJoueurCourant();
	for(int i=0;i<4;i++) ajouterCarte(&_players[id-1]);
      }

      if(c.getValeur() == 55) {   // si le joueur joue la carte passe ton tour
	modifierJoueurCourant();
	modifierJoueurCourant();
	modifierCarteCourante(c);
      }

      if(c.getValeur() == 99) {   // si le joueur joue la carte inverser sens 
	 modifierSens();
	 modifierJoueurCourant();
	 modifierCarteCourante(c);
        }
      
      if(c.getValeur() == 11){   // si le joueur joue la carte joker
	 std::string couleur ;
	 Carte nouvelleCarte;
	 std::cout << "Enter une couleur: "; 
	 std::cin >> couleur;
	 nouvelleCarte=getCarteCourante();
	 modifierJoueurCourant();
         nouvelleCarte=modifierCouleur(nouvelleCarte,couleur);
	 modifierCarteCourante(nouvelleCarte);
	
       }
    }

   historique(c);
   j->supprimerCarteJoueur(c);
  }*/
  //else {
    //std::cout << "carte invalide" << std::endl;
    //regleDuJeux(j);
  //}
    
}



void Jeu::jouer(){
  Carte c ;
  while(vainqueur()==0){

   for(int i=0;i<4;i++){
      if(_players[i].getIdJoueur()==getJoueurCourant()){
	piocher(&_players[i]);
	verifier(&_players[i]);
      }
     
      if(_players[i].getIdJoueur()==getJoueurCourant()){
	c=getCarteCourante();
	std::cout << "carte courrante est : "<< c.getValeur() << c.getCouleur() << std::endl;
	_players[i].afficherJoueur();
	std::cout <<"               " <<getJoueurCourant() << std::endl;
	regleDuJeux(&_players[i],c);
	_players[i].afficherJoueur();
      }
    }
  }
  if(vainqueur()!=0) std::cout << "joueur " << vainqueur() << "a gagné "<<std::endl;
}
 
void Jeu::ajouterCarte(Joueur *j){
        Carte c=getCarte(0);
        supprimer(c);
	j->_cartesJoueur.push_back(c);
    
   
 }

void Jeu::piocher(Joueur *j){
  Carte c=getCarteCourante();
  std::vector<Carte> pl=j->getCartesJoueur();
  for (int i=0;i<(int)pl.size();i++){
    if(coupValide(pl[i])==0) return;
  }
  ajouterCarte(j);
  std::cout << "nouveau tableau avec une carte piocher" << std::endl;
   j->afficherJoueur();
}

void Jeu::verifier(Joueur *j){
  std::vector<Carte> pl=j->getCartesJoueur();
  for (int i=0;i<(int)pl.size();i++){
    if(coupValide(pl[i])==0) return ;
  }
  modifierJoueurCourant();
}

int Jeu::vainqueur(){
  for(int i=0;i<(int)_players.size();i++){
    std::vector<Carte> pl=_players[i].getCartesJoueur();
    if(pl.size()==0) return _players[i].getIdJoueur();
  }
  return 0;
}

Joueur* Jeu::getJoueurCourant2() {
	int indice=getJoueurCourant();
	indice--;
	return &_players[indice];
}

void Jeu::supprimerCarteJoueur(Joueur* j,Carte c){
   int pos=0;
   std::cout << "on veut supprimer la carte: " << c.CarteToString() << std::endl;
   int nb=(int)j->_cartesJoueur.size();
  for(int i=0;i<nb;i++){
	  std::cout << "test sur la carte: "<< j->_cartesJoueur[i].getValeur() << j->_cartesJoueur[i].getCouleur() << std::endl;
    if((j->_cartesJoueur[i].getValeur() == c.getValeur()) && (j->_cartesJoueur[i].getCouleur() == c.getCouleur())){
      pos=i;
      break;
    }
  }
  std::swap (j->_cartesJoueur[pos],j->_cartesJoueur[nb-1]);
    j->_cartesJoueur.pop_back();

}

