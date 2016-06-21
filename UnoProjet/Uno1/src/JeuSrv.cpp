#include "JeuSrv.hpp"
#include "PacketType.h"
#include <string>
#include <sstream>
using namespace sf;

// compilation: g++ client.cpp -lsfml-graphics -lsfml-window -lsfml-network -lsfml-system
int i=1;
Jeu j;
std::string nomJoueur1;
std::string nomJoueur2;
std::string nomJoueur3;
std::string nomJoueur4;

JeuSrv::JeuSrv(const unsigned short _PORT):
PORT(_PORT)
{}

void JeuSrv::initServer(){
  
    listener.listen(PORT);
    listener.setBlocking(false);
    std::cout << "Serveur crée" << std::endl;
}



void JeuSrv::envoyerCarte(Joueur *joueur, Carte c){
	std::string nomJoueur = joueur->getNom();
    for(Clients::iterator it=clients.begin(); it!=clients.end(); ++it)
	{
		if (it->second == nomJoueur){
			sf::Packet pack;
			PacketType type=CARTE_MSG;
			std::string carte= c.CarteToString();
			j.supprimer(c);
			std::cout << "carte envoyée :" << carte << std::endl;
			pack<<type<<carte;
			it->first->send(pack);
			return;
		}
	}
	
}


void JeuSrv::piocher(Joueur *joueur){
	std::string nomJoueur = joueur->getNom();
	Carte c = j._paquet.back();
	joueur->_cartesJoueur.push_back(c);
	j.supprimer(c);
	 if(j._paquet.size()==1){
      j.remplirPaquet();
    }
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

void JeuSrv::envoyerJoueurCourant(int idJoueurCourant){
	 std::string str;
	  std::ostringstream convert; 
	  convert << idJoueurCourant;
	  str= convert.str();
	  std::cout << "id joueur couraaaaaaaaaniufherufneri: " << str << std::endl;
	broadCast(IDJOUEURCOURANT_MSG,str);
}

void JeuSrv::envoyerDemande(Joueur *j){
	std::string nomJoueur = j->getNom();
    for(Clients::iterator it=clients.begin(); it!=clients.end(); ++it)
	{
		if (it->second == nomJoueur){
			sf::Packet pack;
			PacketType type=DEMANDEJOUER_MSG;
			pack<<type;
			std::cout << "on va envoyer la demande au joueur: " << nomJoueur << std::endl;
			it->first->send(pack);
			return;
		}
	}
}

void JeuSrv::envoyerId(Joueur *j,int id){
	std::string nomJoueur = j->getNom();
    for(Clients::iterator it=clients.begin(); it!=clients.end(); ++it)
	{
		if (it->second == nomJoueur){
			sf::Packet pack;
			PacketType type=IDJOUEUR_MSG;
			 std::string str;
			 std::ostringstream convert; 
			 convert << id;
			 str= convert.str();
			pack<<type<<str;
			it->first->send(pack);
			return;
		}
	}
}

void JeuSrv::envoyerNbCartes(){
	for(int i=0;i<4;i++){
			 std::string str;
			 std::ostringstream convert; 
			 convert << j._players[i]._cartesJoueur.size();
			 str= convert.str();
			 if(i==0) broadCast(NBJ1_MSG,str);
			 if(i==1) broadCast(NBJ2_MSG,str);
			 if(i==2) broadCast(NBJ3_MSG,str);
			 if(i==3) broadCast(NBJ4_MSG,str);
			 std::cout << "nb carte du joueur :" << i+1 << "  " << str << std::endl;
		}
}

void JeuSrv::envoyerVainqueur(std::string nomVainqueur){
	broadCast(VAINQUEUR_MSG,nomVainqueur);
}


void JeuSrv::envoyerJeu(Joueur *joueur){
	for(int k=0;k<7;k++){
		//Carte c=j.distribuerCarte(joueur,k);
		piocher(joueur);
	}
}

void JeuSrv::envoyerCarteCourante(){
	Carte c=j.getCarteCourante();
	std::string carte=c.CarteToString();
	j.supprimer(c);
	broadCast(CARTECOURANTE_MSG,carte);
}


int JeuSrv::peutJouer(Carte c){
		if((j._carteCourante.getValeur() == c.getValeur() || j._carteCourante.getCouleur() == c.getCouleur()) || c.getCouleur() == "n"){
			return 0;
		}
	return 1;
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
					j.creerJoueur(Joueur(i,it->second));
					nomJoueur1=it->second;
					std::cout<<"on passe dans le 1" << std::endl;
					std::string str= j._players[0].getNom()+" as été crée comme joueur ";
					std::cout<<str<<std::endl;
					broadCast(SERVER_MSG, str);
					envoyerId(&j._players[0],1);
					envoyerJeu(&j._players[0]);
					j._players[0].afficherJoueur();
					i++;
					break;
				}
				else if(i==2){
					j.creerJoueur(Joueur(i,it->second));
					nomJoueur2=it->second;
					std::string str= j._players[1].getNom()+" as été crée comme joueur ";
					std::cout<<str<<std::endl;
					broadCast(SERVER_MSG, str);
					envoyerId(&j._players[1],2);
					envoyerJeu(&j._players[1]);
					j._players[1].afficherJoueur();
					i++;
					break;
				}else if(i==3){
					j.creerJoueur(Joueur(i,it->second));
					nomJoueur3=it->second;
					std::string str= j._players[2].getNom()+" as été crée comme joueur ";
					std::cout<<str<<std::endl;
					broadCast(SERVER_MSG, str);
					envoyerId(&j._players[2],3);
					envoyerJeu(&j._players[2]);
					j._players[2].afficherJoueur();
					i++;
					break;
				}else if(i==4){
					j.creerJoueur(Joueur(i,it->second));
					nomJoueur4=it->second;
					std::string str= j._players[3].getNom()+" as été crée comme joueur ";
					std::cout<<str<<std::endl;
					broadCast(SERVER_MSG, str);
					envoyerId(&j._players[3],4);
					envoyerJeu(&j._players[3]);
					j._players[3].afficherJoueur();
					envoyerCarteCourante();
					i++;
					j._joueurCourant=1;
					envoyerDemande(&j._players[0]);
					envoyerNbCartes();
					break;
				}
				
				
			
			case(CARTECLIENT_MSG):
			{
				packet>>it->second;
				std::cout << "carte recue: " << it->second << std::endl;
				std::cout << "vecteur de " << j._players[j._joueurCourant-1].getNom() << std::endl;
				j._players[j._joueurCourant-1].afficherJoueur();
				Carte tmp;
				Carte c = tmp.stringToCarte(it->second);
				if(j._joueurCourant==1) it->second = nomJoueur1;
				if(j._joueurCourant==2) it->second = nomJoueur2;
				if(j._joueurCourant==3) it->second = nomJoueur3;
				if(j._joueurCourant==4) it->second = nomJoueur4;
				
				
				if(j._players[j._joueurCourant-1]._cartesJoueur.size()==1 && peutJouer(c)==0){
					j.regleDuJeux(&j._players[j._joueurCourant-1],c);
					std::cout << "Il y a un vainqueur " << it->second << std::endl;
					j._carteCourante=c;
					envoyerVainqueur(it->second);
					envoyerCarteCourante();
					return;
				  }
				  
				if(c.getValeur()==99){
					j.modifierSens();
				}
				
				j.regleDuJeux(&j._players[j._joueurCourant-1],c);
				
				if(c.getValeur()==22){
					piocher(&j._players[j._joueurCourant-1]);
					piocher(&j._players[j._joueurCourant-1]);
				}
				if(c.getValeur()==44){

				  for(int i=0;i<4;i++)
						piocher(&j._players[j._joueurCourant-1]);
				}
				if(c.getValeur()==55){
					j.modifierJoueurCourant();	
				}
				
				envoyerCarteCourante();
				envoyerJoueurCourant(j._joueurCourant);
				envoyerNbCartes();
				
				std::cout << "plus que " << j._paquet.size() << " cartes dans le paquet" << std::endl;
				envoyerDemande(&j._players[j._joueurCourant-1]);
				
				break;
			}
				
				case(DEMANDEPIOCHE_MSG):
				{
				packet>>it->second;
					if(it->second==j._players[j._joueurCourant-1].getNom()){
						if(peutJouer(j._paquet.back())==0){
						  //if(j._paquet.back()).getCouleur=="n"){
						 
						  piocher(&j._players[j._joueurCourant-1]);
						   envoyerDemande(&j._players[j._joueurCourant-1]);
						  /*}else{
							j._carteCourante=j._paquet.back();
							envoyerCarteCourante();
							j.modifierJoueurCourant();
							envoyerDemande(&j._players[j._joueurCourant-1]);
							}*/
						}else{
							piocher(&j._players[j._joueurCourant-1]);
							j.modifierJoueurCourant();
							envoyerDemande(&j._players[j._joueurCourant-1]);
						}
					}
				envoyerJoueurCourant(j._joueurCourant);
				envoyerNbCartes();
				
				break;
			}
			
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
{	std::cout << "paquet" << std::endl;
	for(int i=0;i<(int)j._paquet.size();i++)
	std::cout << j._paquet[i].getValeur() << j._paquet[i].getCouleur() << " "  ;
	std::cout << j._paquet.size() << std::endl;

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

