#ifndef BLATT3_GAME_H
#define BLATT3_GAME_H


#include <vector>

#include "Coordinates.h"

#include "PlayerSea.h"


void gameLoop(std::vector<GameObjects::PlayerSea> & playerSeas);

void gameTurn(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea);

bool checkGameFinished(GameObjects::PlayerSea & currentPlayerSea, GameObjects::PlayerSea & otherPlayerSea);


Sea::Coordinates inputMissileTargetCoordinates(GameObjects::PlayerSea const & currentPlayerSea);


#endif
