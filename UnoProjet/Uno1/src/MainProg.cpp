#include <iostream>
#include <string>
#include "Carte.hpp"
#include "Joueur.hpp" 
#include "JeuSrv.hpp"

int main() {
  JeuSrv s(5550);
  s.initServer();
  s.run();
 
  
  
  
  
  /*Carte c;
  c=j.carteCourante();
  j.creerJoueur();
  std::cout << "carte courrante est : "<< c.getValeur() << c.getCouleur() << std::endl;
  j.afficher();
  j.jouer();*/

   // for(int i=0;i<4;i++){

   //   if(_players[i].getIdJoueur()==j.getJoueurCourant()){
   //    j1.afficherJoueur();
   //    std::cout <<"               "<<j.getJoueurCourant() << std::endl;
   //    j.regleDuJeux(&j1);
   //    j1.afficherJoueur();
   // }
   // if(_player[i].getIdJoueur()==j.getJoueurCourant()){
   //   c=j.getCarteCourante();
   //   std::cout << "carte courrante est : "<< c.getValeur() << c.getCouleur() << std::endl;
   //   j2.afficherJoueur();
   //   std::cout <<"               " <<j.getJoueurCourant() << std::endl;
   //   j.regleDuJeux(&j2);
   //   j2.afficherJoueur();
   // }
   // if(.getIdJoueur()==j.getJoueurCourant()){
   //   c=j.getCarteCourante();
   //   std::cout << "carte courrante est : "<< c.getValeur() << c.getCouleur() << std::endl;
   //   j3.afficherJoueur();
   //   std::cout <<"               " <<j.getJoueurCourant() << std::endl;
   //   j.regleDuJeux(&j3);
   //   j3.afficherJoueur();
   // }
   // if(j4.getIdJoueur()==j.getJoueurCourant()){
   //   c=j.getCarteCourante();
   //   std::cout << "carte courrante est : "<< c.getValeur() << c.getCouleur() << std::endl;
   //   j4.afficherJoueur();
   //   std::cout <<"               " <<j.getJoueurCourant() << std::endl;
   //   j.regleDuJeux(&j4);
   //   j4.afficherJoueur();
   // }
   
   // }  
 
   
   
   
   
  return 0; 

} 

