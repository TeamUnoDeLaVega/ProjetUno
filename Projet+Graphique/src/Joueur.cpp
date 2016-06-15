#include "Joueur.hpp"
#include <iostream>



Joueur::Joueur(int valeur):_id(valeur){}

void Joueur::setIdJoueur(int valeur){
  _id=valeur;
}

int Joueur::getIdJoueur()const{
  return _id;
}


Carte Joueur::jouerCoup(){
  Carte c ;
  std::string carte;
  std::string val ;
  std::string couleur ;
  std::cout << "Enter une carte a jouer: "; 
  std::cin >> carte;
  if(carte.length() > 2) {
     val = carte.substr(0,2);
     couleur = carte.substr(2,1);
    }
  else {
    val = carte.substr(0,1);
    couleur = carte.substr(1,1);
  }
  c.setCouleur(couleur);
  int valeur=std::stoi(val);
  c.setValeur(valeur);
  return c ;
 }

   
void Joueur::afficherJoueur()const{
  std::cout << "tableau du joueur " << std::endl;
  for(int i=0;i<(int)_cartesJoueur.size();i++){
    std::cout << _cartesJoueur[i].getValeur() << _cartesJoueur[i].getCouleur() << ";" ;
  }
  std::cout << " " << std::endl;
}

void Joueur::supprimerCarteJoueur(Carte c){
   int pos=0;
   int nb=(int)_cartesJoueur.size();
  for(int i=0;i<(int)_cartesJoueur.size();i++){
    if((_cartesJoueur[i].getValeur() == c.getValeur()) && (_cartesJoueur[i].getCouleur() == c.getCouleur())){
      pos=i;
      break;
    }
  }
  std::swap (_cartesJoueur[pos],_cartesJoueur[nb-1]);
    _cartesJoueur.pop_back();

}

std::vector<Carte> Joueur::getCartesJoueur()const {
  return _cartesJoueur;
}

  
