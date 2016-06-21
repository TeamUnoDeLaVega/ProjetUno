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


Carte Carte::stringToCarte(std::string str){
	Carte c ;
	std::string val;
	std::string couleur;
  if(str.length() > 2) {
     val = str.substr(0,2);
     int pos=2;
     couleur = str.substr(pos,pos+1);
    }
  else {
    val = str.substr(0,1);
    couleur = str.substr(1,1);
  }
  c.setCouleur(couleur);
  int valeur = atoi(val.c_str());
  c.setValeur(valeur);
  return c ;
}
