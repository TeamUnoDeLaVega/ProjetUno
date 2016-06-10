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
  _paquet.push_back(Carte(44,"n")); //44 == +4
  _paquet.push_back(Carte(11,"n")); //11 == joker
    
  nb++;
  }
 
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle ( _paquet.begin(), _paquet.end(),g );
  _sens=1;
  _joueurCourant=1;
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




void Jeu::distribuerCarte(Joueur *j){
    for (int i=0;i<7;i++) {
    Carte c=getCarte(i);
    supprimer(c);
    j->_cartesJoueur.push_back(c);
  }
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
    }

void Jeu::afficher()const{
  for(int i=0;i<(int)_paquet.size();i++){
    std::cout << _paquet[i].getValeur() << _paquet[i].getCouleur() << ";";
  }
  std::cout << "" << std::endl;
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

Carte Jeu::modiferCouleur(Carte c,std::string couleur){
  c.setCouleur(couleur);
  return c;
  }

void Jeu::modifierCarteCourante(Carte c){
  _carteCourante=c;
}

Carte Jeu::getCarteCourante() const{
  return _carteCourante ;
}

// void piocherUneCarte(Joueur *j){
//   Carte 
  


void Jeu::regleDuJeux(Joueur *j){
  Carte c=j->jouerCoup();
  int vrai=coupValide(c);
  if (vrai == 0){

    if (c.getValeur() < 10){
          modifierJoueurCourant();
          modifierCarteCourante(c);
    }
    
    if(c.getValeur() > 10) {
      if(c.getValeur() == 22) {    // si le joueur joue la carte +2 
	 modifierJoueurCourant();
	int id= getJoueurCourant();
	for(int i=0;i<2;i++) ajouterCarte(id);
	modifierCarteCourante(c);
      }

      if(c.getValeur() == 44) {   // si le joueur joue la carte +4
	modifierJoueurCourant();
	int id=getJoueurCourant();
	for(int i=0;i<4;i++) ajouterCarte(id);
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
         nouvelleCarte=modiferCouleur(nouvelleCarte,couleur);
	 modifierCarteCourante(nouvelleCarte);
	
       }
    }

   historique(c);
   j->supprimerCarteJoueur(c);
  }
  else {
    std::cout << "carte invalide" << std::endl;
    regleDuJeux(j);
  }
    
}

void Jeu::ajouterCarte(int id){
  return ;
//   if(j->getIdJoueur() == id ){
//     for(int i=0;i<(int)_paquet.size();i++)
//       j->_cartesJoueur.push_back(_paquet[i]);
//       break;
  }
// }

