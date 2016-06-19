#pragma once

#include "SFML/System.hpp"

typedef sf::Uint8 PacketType;
const PacketType INITIAL_NAME_DATA=0;
const PacketType GENERAL_MSG=1;
const PacketType SERVER_MSG=2;
const PacketType CARTE_MSG=3;
const PacketType CARTECOURANTE_MSG=4;
const PacketType DEMANDEJOUER_MSG=5;
const PacketType CARTECLIENT_MSG=6;
const PacketType VAINQUEUR_MSG=8;
const PacketType DEMANDEPIOCHE_MSG=9;
const PacketType PASSE_MSG=10;
