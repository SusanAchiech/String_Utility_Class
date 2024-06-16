#pragma once
#include "Room.h"
#include "Player.h"
#include "Item.h"
#include <map>
#include <iostream>
#include "BoxOfDonuts.h"
#include "Lamp.h"
#include "Cat.h"
#include "spell.h"

class Game {
    static std::map<std::string, std::map<std::string, std::string>> exits;
    static std::map<std::string, Room*> rooms;
public:
    Game();
    ~Game();
    void Run();

private:
    void initializeRooms();
    void move(const String& movement);
    void useItem();
    std::string currentRoomDesc() const;

    Room* currentRoom;
    Player* player;
};
