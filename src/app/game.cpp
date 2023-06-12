#include "game.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include "Coordinates.h"
using Sea::Coordinates;

#include "PlayerSea.h"
using GameObjects::PlayerSea;

#include "init.h"


void gameLoop(vector<PlayerSea> & playerSeas)
{
    cout << endl << "Let's start!" << endl;
    for (unsigned int round = 0;; ++round) {
        PlayerSea & currentPlayerSea = playerSeas[round % 2];
        PlayerSea & otherPlayerSea = playerSeas[(round + 1) % 2];

        gameTurn(currentPlayerSea, otherPlayerSea);

        if (checkGameFinished(currentPlayerSea, otherPlayerSea)) {
            break;
        }
    }
}

void gameTurn(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea)
{
    Coordinates targetCoordinates = inputMissileTargetCoordinates(currentPlayerSea);
    bool hit = currentPlayerSea.sendMissileTo(otherPlayerSea, targetCoordinates);

    if (hit) {
        cout << "Hit!" << endl;
    } else {
        cout << "Miss!" << endl;
    }
}

bool checkGameFinished(PlayerSea & currentPlayerSea, PlayerSea & otherPlayerSea)
{
    if (otherPlayerSea.allShipsDestroyed()) {
        cout << "THe last ship from " << otherPlayerSea.getPlayerName() << "is sunken. "
             << currentPlayerSea.getPlayerName() << "has won." << endl;
        return true;
    }
    return false;
}

Coordinates inputMissileTargetCoordinates(PlayerSea const & currentPlayerSea)
{
    while (true) {
        cout << endl << currentPlayerSea.getPlayerName() << " aims to " << endl;
        Coordinates targetCoordinates = inputCoordinates();

        if (currentPlayerSea.missileAlreadySentTo(targetCoordinates)) {
            cout << "You already tried this Coordinate." << endl;
            continue;
        }
        return targetCoordinates;
    }
}
