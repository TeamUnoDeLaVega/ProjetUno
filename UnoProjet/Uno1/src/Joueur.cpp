#include "Joueur.hpp"
#include <iostream>



Joueur::Joueur(int valeur, std::string nom):_id(valeur),_nom(nom){}

void Joueur::setIdJoueur(int valeur){
  _id=valeur;
}

void Joueur::setNomJoueur(std::string nom){
  _nom=nom;
}

int Joueur::getIdJoueur()const{
  return _id;
}

  std::string Joueur::getNom(){
	  return _nom;
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



std::vector<Carte> Joueur::getCartesJoueur()const {
  return _cartesJoueur;
}

  
