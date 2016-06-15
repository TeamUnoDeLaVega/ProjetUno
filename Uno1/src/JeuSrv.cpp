#include "JeuSrv.hpp"
#include "PacketType.h"
using namespace sf;

// compilation: g++ client.cpp -lsfml-graphics -lsfml-window -lsfml-network -lsfml-system
int i=1;
Jeu j;
JeuSrv::JeuSrv(const unsigned short _PORT):
PORT(_PORT)
{}

void JeuSrv::initServer(){
  
    listener.listen(PORT);
    listener.setBlocking(false);
    std::cout << "Serveur crée" << std::endl;
}



void JeuSrv::envoyerCarte(Joueur *j, Carte c){
	std::string nomJoueur = j->getNom();
    for(Clients::iterator it=clients.begin(); it!=clients.end(); ++it)
	{
		if (it->second == nomJoueur){
			sf::Packet pack;
			PacketType type=CARTE_MSG;
			std::string carte= c.CarteToString();
			std::cout << "carte envoyée :" << carte << std::endl;
			pack<<type<<carte;
			it->first->send(pack);
			return;
		}
	}
	
}

void JeuSrv::envoyerDemande(Joueur *j){
	std::string nomJoueur = j->getNom();
    for(Clients::iterator it=clients.begin(); it!=clients.end(); ++it)
	{
		if (it->second == nomJoueur){
			sf::Packet pack;
			PacketType type=DEMANDEJOUER_MSG;
			pack<<type;
			it->first->send(pack);
			return;
		}
	}
}

void JeuSrv::envoyerJeu(Joueur *joueur){
	for(int k=0;k<7;k++){
		Carte c=j.distribuerCarte(joueur,k);
		envoyerCarte(joueur,c);
	}
}

void JeuSrv::envoyerCarteCourante(){
	Carte c=j.carteCourante();
	std::string carte=c.CarteToString();
	broadCast(CARTECOURANTE_MSG,carte);
}

void JeuSrv::handlePackets()
{
	//handle incoming data
	for(Clients::iterator it=clients.begin(); it!=clients.end();)
	{
		sf::Packet packet;
		sf::Socket::Status status=it->first->receive(packet);
		switch (status)
		{
		case sf::Socket::Done:
			PacketType type;
			packet>>type;
			switch(type)
			{
				
			case(INITIAL_NAME_DATA):
				//store the name
				packet>>it->second;
				std::cout<<it->second<<" has joined\n";
				if(i==1){
					Joueur j1(i,it->second);
					std::cout<<"on passe dans le 1" << std::endl;
					std::string str= j1.getNom()+" as été crée comme joueur ";
					std::cout<<str<<std::endl;
					broadCast(SERVER_MSG, str);
					envoyerJeu(&j1);
					i++;
					//envoyerDemande(&j1);
				}
				else if(i==2){
					Joueur j2(i,it->second);
					std::string str= j2.getNom()+" as été crée comme joueur ";
					std::cout<<str<<std::endl;
					broadCast(SERVER_MSG, str);
					envoyerJeu(&j2);
					i++;
				}else if(i==3){
					Joueur j3(i,it->second);
					std::string str= j3.getNom()+" as été crée comme joueur ";
					std::cout<<str<<std::endl;
					broadCast(SERVER_MSG, str);
					envoyerJeu(&j3);
					i++;
				}else if(i==4){
					Joueur j4(i,it->second);
					std::string str= j4.getNom()+" as été crée comme joueur ";
					std::cout<<str<<std::endl;
					broadCast(SERVER_MSG, str);
					envoyerJeu(&j4);
					envoyerCarteCourante();
					i++;
				}
				
				
			
			case(CARTE_MSG):
				std::cout << "carte recue";
			
		}
			++it;
			break;
		case sf::Socket::Disconnected:
			std::cout<<it->second<<" has been disconnected\n";
			broadCast(GENERAL_MSG, it->second+" has been disconnected\n");
			it=clients.erase(it);
			break;

		default:
			++it;
		}
	//	std::cout<<"wtf\n";
	}
}
















/*void JeuSrv::handlePacketsPlay()
{
	//handle incoming data
	for(Clients::iterator it=clients.begin(); it!=clients.end();)
	{
		sf::Packet packet;
		PacketType type=DEMANDEJOUER_MSG;
		packet<<type<<"";
		it->first->send(packet);
		
		sf::Packet packetReponse;
		sf::Socket::Status status=it->first->receive(packetReponse);
		switch (status)
		{
		case sf::Socket::Done:
			PacketType typeReception;
			packet>>typeReception;
			if(typeReception==CARTE_MSG)
			{
				std::cout << "carte recue par "<< it->second << std::endl;
			}
			
			++it;
			break;

		case sf::Socket::Disconnected:
			std::cout<<it->second<<" has been disconnected\n";
			broadCast(GENERAL_MSG, it->second+" has been disconnected\n");
			it=clients.erase(it);
			break;

		default:
			++it;
		}
	//	std::cout<<"wtf\n";
	}
}*/

void JeuSrv::broadCast(PacketType type, const std::string & msg)
{
	for(Clients::iterator it=clients.begin(); it!=clients.end(); ++it)
	{
		sf::Packet pack;
		pack<<type<<msg;
		it->first->send(pack);
	}
}




void JeuSrv::run()
{

	/*sf::Thread thread([&]()
	{
		while(1)
		{
		std::string s;
		std::getline(std::cin, s);
		broadCast(SERVER_MSG, "SERVER: "+s);
		}
	});
	thread.launch();*/

	sf::TcpSocket * nextClient=nullptr;
	
	while(1)
	{
		//Handle newcoming clients
		if(nextClient==nullptr)
		{
			nextClient=new sf::TcpSocket;
			nextClient->setBlocking(false);
		}
		if(listener.accept(*nextClient) == sf::Socket::Done && clients.size()<=4)
		{
			clients.insert(std::make_pair(nextClient, ""));
			nextClient=nullptr;
		}
		handlePackets();
	
	}
}


