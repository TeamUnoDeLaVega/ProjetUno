#include <iostream>
#include "Client.hpp"
#include "PacketType.h"
#include "Carte.hpp"
#include "Joueur.hpp"


int main()
{
	std::string name;
	std::cout<<"What's your name: ";
	std::getline(std::cin, name);
	std::cout<<"\n";
	Client client(name);

	unsigned short port;
	std::cout<<"What port? ";
	std::cin>>port;
	std::cin.get();
	
	sf::Socket::Status status;
	status=client.connect(sf::IpAddress::getLocalAddress(), port);
	if(status!=sf::Socket::Done)
	{
		std::cout<<"Sorry we couldn't connect\n";
		return -1;
	}
	client.send(INITIAL_NAME_DATA, name);
	std::string msg;
	sf::Thread thread([&]()
	{
		while(1)
		{
			client.receive(msg);
		}
	});
	thread.launch();
	
}
