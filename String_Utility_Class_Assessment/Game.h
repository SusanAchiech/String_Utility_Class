#pragma once
#include "Room.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
	void Run();
private:
	Room** room;
	Player* player;
};