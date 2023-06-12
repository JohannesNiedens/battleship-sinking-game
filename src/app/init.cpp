#include "init.h"

#include <string>
using std::string;
#include <iostream>
using std::getline;
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <climits>

#include "Coordinates.h"
using Sea::Coordinates;
#include "Object.h"
using Sea::Orientation;

#include "Constants.h"
using GameObjects::Ship;
#include "Ship.h"
using GameObjects::Constants;
#include "PlayerSea.h"
using GameObjects::PlayerSea;

unsigned int const Constants::seaSizeX = 3;
unsigned int const Constants::seaSizeY = 3;
vector<unsigned int> const Constants::shipSizes = { 2, 1 };


void initializePlayerSeasWithShips(vector<PlayerSea> & playerSeas)
{
    for (unsigned int playerIdx = 0; playerIdx < 2; ++playerIdx) {
        string playerName = inputPlayerName();
        playerSeas.emplace_back(playerName);
        initializeShips(playerSeas[playerIdx]);
    }
}

string inputPlayerName()
{
    static unsigned int playerCount = 1;
    cout << endl << "Name from player " << playerCount++ << ": ";

    string playerName;
    getline(cin, playerName);
    return playerName;
}

void initializeShips(PlayerSea & playerSea)
{
    cout << "Place your ships in the water (" << PlayerSea::printSeaArea() << ")." << endl;

    for (unsigned int shipIdx = 0; shipIdx < Constants::shipSizes.size(); ++shipIdx) {
        unsigned int size = Constants::shipSizes[shipIdx];

        while (!initializeShip(playerSea, size));
    }
    for (unsigned int i = 0; i < 20; ++i) {
        cout << endl;
    }
}

bool initializeShip(PlayerSea & playerSea, unsigned int size)
{
    Ship ship = inputShip(size);
    bool addResult = playerSea.addShip(ship);
    if (!addResult) {
        cout << "The ship has to be entirely in the designated area and there shouldn't be any conflicts with other ships." << endl;
        return false;
    }
    return true;
}

Ship inputShip(unsigned int size)
{
    cout << endl << "New ship of the size " << size << endl;
    Coordinates coordinates = inputCoordinates();
    Orientation orientation = inputOrientation();

    return Ship(coordinates, size, orientation);
}

Coordinates inputCoordinates()
{
    unsigned int x, y;
    do {
        cout << "  x y:";
        cin >> x >> y;
    } while (checkForInputError());
    return Coordinates(x, y);
}

Orientation inputOrientation()
{
    string orientation;
    do {
        cout << "  Orientation to (r/right oder d/down):";
        cin >> orientation;
    } while (checkForInputError() || (orientation[0] != 'r' && orientation[0] != 'd'));
    return orientation[0] == 'r' ? Orientation::X : Orientation::Y;
}

bool checkForInputError()
{
    bool error = cin.fail();
    if (error) {
        cout << "Wrong input!" << endl;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return error;
}
