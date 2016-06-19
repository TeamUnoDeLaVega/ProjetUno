#include "Client.hpp"
#include "PacketType.h"
#include "Joueur.hpp"
#include <iostream>
#include <vector>
Client::Client(const std::string & name_):name(name_)
{}

void Client::setName(std::string name_) { name=name_ ;}

Client::~Client(void)
{
}



sf::Socket::Status Client::connect(const sf::IpAddress & IP, unsigned short port)
{
	//connect to server
	sf::Socket::Status stat= me.connect(IP, port);
	me.setBlocking(false);
	return stat;
}

sf::Socket::Status Client::send (PacketType type, const std::string & msg)
{
	sf::Packet packet;
	packet<<type<<msg;
	return me.send(packet);
}


void Client::envoyerCarte(Carte c){
  sf::Packet packet;
	PacketType type=CARTECLIENT_MSG;
	std::string carte= c.CarteToString();
	packet<<type<<carte;
	std::cout << "envoie de la carte vers le serveur" << std::endl;
	_joueur.supprimerCarteJoueur(c);
	me.send(packet);
}


sf::Socket::Status Client::receive(std::string & msg)
{
	sf::Packet packet;
	sf::Socket::Status status=me.receive(packet);
	PacketType type;
	packet>>type;
	packet>>msg;
	if(type==CARTE_MSG){
		Carte c=c.stringToCarte(msg);
		_joueur._cartesJoueur.push_back(c);

		if(_joueur._cartesJoueur.size()>=7) _joueur.afficherJoueur();
		   
	}
	if(type==VAINQUEUR_MSG){
	  std::cout << "le vainqueur est: " << msg << std::endl;
	}
	if(type==CARTECOURANTE_MSG){
		Carte c=c.stringToCarte(msg);
		_joueur._carteCourante=c;
	}
	if(type==DEMANDEJOUER_MSG){
		int peutJouer = verifierJouer();
		if(peutJouer==0){
			std::cout << "je peux jouer" << std::endl;
			setFlag(1);
		}else{
			send(DEMANDEPIOCHE_MSG,name);
			std::cout << "demande de pioche" << std::endl;
			//envoyerCarte(_jouer);
		}
		std::cout << "demande de jouer recue" << msg << std::endl;
	}

	if(status==sf::Socket::Done)
	{
		//std::cout<<msg<<"\n";
		//packet>>msg;
	}
	if(status==sf::Socket::Done && type==CARTECOURANTE_MSG)
	{
		std::cout << "carte courante:" << msg << std::endl;
		
	}
	type=50;
	return status;
}

int Client::verifierJouer(){
	int nb=(int)_joueur._cartesJoueur.size();
	for(int i=0;i<nb;i++){
		 if((_joueur._carteCourante.getValeur() == _joueur._cartesJoueur[i].getValeur() || _joueur._carteCourante.getCouleur() == _joueur._cartesJoueur[i].getCouleur()) || _joueur._carteCourante.getCouleur() == "n") return 0;
    }
    return 1;
}
std::vector<Carte> Client::envoyerCarteJoueur(){
  return _joueur._cartesJoueur;
}

Carte  Client::envoyerCarteCourante(){
  return _joueur._carteCourante;
}

/*int  Client::demandePiocher(){
  for(int i; i < (int)_joueur._cartesJoueur.size() ; i++){
    if((_joueur._carteCourante.getValeur() == _joueur._cartesJoueur[i].getValeur() || _joueur._carteCourante.getCouleur() == _joueur._cartesJoueur[i].getCouleur()) || _joueur._carteCourante.getCouleur() == "n") return 0;
    else{
      send(DEMANDEPIOCHE_MSG,name);
      std::cout 
      return 1;
    }
    }*/
  

void Client::setFlag(int i){
 _flag=i;
}

int Client::getFlag(){
  return _flag;

}
