#ifndef CARTE_HPP_
#define CARTE_HPP_
#include <string>
class Carte {
private:
  int _valeur;
  std::string _couleur;
public:
  Carte();
  Carte(int valeur,std::string couleur);
  void setValeur(int valeur);
  int getValeur() const ;
  std::string getCouleur() const;
  void setCouleur(std::string couleur);
};

 

#endif 
