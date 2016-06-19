#include "Carte.hpp"
#include <iostream>
#include <string>
#include <sstream>
Carte::Carte(){}
Carte::Carte(int valeur,std::string couleur):_valeur(valeur),_couleur(couleur){}


int Carte::getValeur() const { return _valeur ; }
std::string Carte::getCouleur() const { return _couleur ; }

void Carte::setCouleur(std::string couleur){
  _couleur=couleur;
}
				    
void Carte::setValeur(int valeur){
  _valeur=valeur;
}

  std::string Carte::CarteToString(){
	  std::string str;
	  std::ostringstream convert; 
	  convert << getValeur();
	  str= convert.str() + getCouleur();
	  return str;
  }
