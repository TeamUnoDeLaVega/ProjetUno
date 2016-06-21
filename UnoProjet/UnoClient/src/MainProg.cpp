#include <iostream>
#include "Client.hpp"
#include "VueGraphique.hpp"
#include "PacketType.h"
#include "Carte.hpp"
#include "Joueur.hpp"


int main()
{     
      
	/*std::string msg;
	sf::Thread thread([&]()
	{
		while(1)
		{
			client.receive(msg); // ligne a recuperer dans vueGraphique
		}
	});
	thread.launch();*/
	VueGraphique vueConnect;
	VueGraphique vue;
	//vue.initialiserClient(client);
	vueConnect.runConnect();
	vue.run();
	
}
