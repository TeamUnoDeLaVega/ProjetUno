#include "Client.hpp"
#include "PacketType.h"
#include "Joueur.hpp"
#include <iostream>
Joueur j;
Client::Client(const std::string & name_):name(name_)
{
	
}


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
	std::string carte= c.CarteToString();
	send(CARTE_MSG,carte);
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
		j._cartesJoueur.push_back(c);
		if(j._cartesJoueur.size()>=7) j.afficherJoueur();
	}
	if(type==CARTECOURANTE_MSG){
		Carte c=c.stringToCarte(msg);
		j._carteCourante=c;
	}
	if(type==DEMANDEJOUER_MSG){
		Carte c(1,"v");
		envoyerCarte(c);
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
	type=1000;
	return status;
}
