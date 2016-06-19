#pragma once
#include "SFML/Network.hpp"
#include "PacketType.h"
#include "Joueur.hpp"
#include "Carte.hpp"
#include <vector>

class Client 
{
private:
  std::string name;
  sf::TcpSocket me;
  Joueur _joueur;
  int _flag;
  
public:
  Client(){};
  Client(const std::string & name);
  ~Client();
  void setName(std::string name_);

  
  sf::Socket::Status connect(const sf::IpAddress & IP, unsigned short port);
  sf::Socket::Status send (PacketType type, const std::string & msg);
  sf::Socket::Status receive(std::string & msg);
  void envoyerCarte(Carte c);
  std::vector<Carte> envoyerCarteJoueur();
  Carte envoyerCarteCourante();
  void setFlag(int i);
  int getFlag();
int verifierJouer();



 
  
};

