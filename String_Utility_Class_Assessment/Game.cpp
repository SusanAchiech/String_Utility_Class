#include "Game.h"

// Constructor definition
Game::Game() {
    // Initializing rooms and setting currentRoom as starting room
    initializeRooms();
    player = new Player();
    currentRoom = rooms["start"];
}

// Destructor definition
Game::~Game() {
    // Deleting player memory and all rooms
    delete player;
    for (auto& roomPair : rooms) {
        delete roomPair.second;
    }
}

// Run method definition
void Game::Run() {
    std::cout << "Welcome to the Text Adventure Game!\n";
    while (true) {
        currentRoom->Description();
        std::cout << "Enter a command: ";
        String command;
        command.ReadFromConsole().ToLower();

        if (command.EqualTo("quit")) {
            std::cout << "Quitting too soon. Thanks for Playing!\n";
            break;
        }
        // Checking user movement
        else if (command.EqualTo("move north") || command.EqualTo("move south") ||
            command.EqualTo("move east") || command.EqualTo("move west")) {
            move(command);
        }
        // Using item
        else if (command.EqualTo("use item")) {
            useItem();
        }
        else if (command.Find("spell ") == 0) {
            String spells = command.Replace("spell ", "");
            player->FindSpell(spells);
        }
        else {
            std::cout << "Spell not found.\n";
        }
    }
}

// initializeRooms method definition
void Game::initializeRooms() {
    rooms["start"] = new Room("You are in the starting room.");
    rooms["north"] = new Room("You are in the northern room.", new BoxOfDonuts());
    rooms["south"] = new Room("You are in the southern room.", new Lamp());
    rooms["east"] = new Room("You are in the eastern room.", new Cat());
    rooms["west"] = new Room("You are in the western room.");

    exits["start"] = { {"north", "north"}, {"south", "south"}, {"east", "east"}, {"west", "west"} };
    exits["north"] = { {"south", "start"} };
    exits["south"] = { {"north", "start"} };
    exits["east"] = { {"west", "start"} };
    exits["west"] = { {"east", "start"} };
}

// move method definition
void Game::move(const String& movement) {
    String dir = movement.Replace("move ", "");
    auto it = exits[currentRoomDesc()].find(dir.CStr());
    if (it != exits[currentRoomDesc()].end()) {
        currentRoom = rooms[it->second];
    }
    // Checking if the direction is valid
    else {
        std::cout << "You can't move in that direction.\n";
    }
}

// useItem method definition
void Game::useItem() {
    Item* item = currentRoom->Item();
    if (item) {
        item->Use();
    }
    else {
        std::cout << "There is no item to use in this room.\n";
    }
}

// currentRoomDesc method definition
std::string Game::currentRoomDesc() const {
    for (const auto& pair : rooms) {
        if (pair.second == currentRoom) {
            return pair.first;
        }
    }
    return "";
}
