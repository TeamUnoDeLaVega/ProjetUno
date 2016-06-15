#ifndef JEUSRV_HPP_
#define JEUSRV_HPP_
#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include "Jeu.hpp"
#include "PacketType.h"
#include <list>
#include <unordered_map>
#include "Joueur.hpp"
#include "Carte.hpp"

using namespace sf;
class JeuSrv{
public:
	const unsigned short PORT;
	typedef std::unordered_map<sf::TcpSocket *, std::string> Clients;
	Clients clients;
	//sf::Mutex mutex;
  sf::TcpListener listener;
		sf::TcpSocket socket;
		JeuSrv(const unsigned short _PORT);
		void initServer();
		void run();
		void handlePackets();
		void broadCast(PacketType type, const std::string & msg);
		void envoyerCarte(Joueur *j, Carte c);
		void envoyerJeu(Joueur *joueur);
		void envoyerCarteCourante();
		void envoyerDemande(Joueur *j);
		void handlePacketsPlay();



};

#endif
