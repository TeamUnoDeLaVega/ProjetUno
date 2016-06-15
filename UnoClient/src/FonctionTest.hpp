#include "Carte.hpp"
#include "Joueur.hpp"
BOOST_AUTO_TEST_CASE(Module1_test1) { // test unitaire
	std::string msg="44j";
	Carte c=c.stringToCarte(msg);
	int val=c.getValeur();
	std::string couleur=c.getCouleur();
	BOOST_CHECK_EQUAL(val, 44);
}
