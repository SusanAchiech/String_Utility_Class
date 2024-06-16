#include "Game.h"
#include <iostream>
#include <map>
#include <string>

// Defining static data members
std::map<std::string, std::map<std::string, std::string>> Game::exits;
std::map<std::string, Room*> Game::rooms;

Game::Game() : currentRoom(nullptr), player(new Player()) {
    initializeRooms();
    currentRoom = rooms["start"];
}

Game::~Game() {
    delete player;
    for (auto& roomPair : rooms) {
        delete roomPair.second;
    }
}

void Game::initializeRooms() {
    // Create and link example rooms
    rooms["start"] = new Room("You are in a dimly lit room. There is a door to the north.");
    rooms["north"] = new Room("You are in a dusty corridor. The walls are lined with old paintings.");
    rooms["south"] = new Room("You are in a small library. Books line the walls.");
    rooms["east"] = new Room("You are in a grand hall. A chandelier hangs from the ceiling.");
    rooms["west"] = new Room("You are in a garden. Flowers bloom all around you.");

    // Link the rooms
    exits["start"]["north"] = "north";
    exits["start"]["south"] = "south";
    exits["start"]["east"] = "east";
    exits["start"]["west"] = "west";

    exits["north"]["south"] = "start";
    exits["south"]["north"] = "start";
    exits["east"]["west"] = "start";
    exits["west"]["east"] = "start";
}

void Game::Run() {
    std::cout << "Welcome to the Text Adventure Game!\n";
    while (true) {
        currentRoom->Description();
        std::cout << "Enter a command: ";
        std::string command;
        std::getline(std::cin, command);

        if (command == "quit") {
            std::cout << "Quitting. Thanks for playing!\n";
            break;
        }
        else if (command.substr(0, 5) == "move ") {
            String direction(command.substr(5).c_str());
            move(direction);
        }
        else {
            std::cout << "Invalid command. Try again.\n";
        }
    }
}

void Game::move(const String& direction) {
    std::string currentRoomDescription = currentRoomDesc().substr();
    auto it = exits[currentRoomDescription].find(direction.CStr());
    if (it != exits[currentRoomDescription].end()) {
        currentRoom = rooms[it->second];
    }
    else {
        std::cout << "You can't move in that direction.\n";
    }
}

std::string Game::currentRoomDesc() const {
    for (const auto& pair : rooms) {
        if (pair.second == currentRoom) {
            return pair.first;
        }
    }
    return "";
}
