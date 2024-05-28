#pragma once
#include "Room.h"
#include "Player.h"
#include <map>
#include <iostream>
#include "BoxOfDonuts.h"
#include "Lamp.h"
#include "Cat.h"
#include "Item.h"


class Game {
public:
    Game() {
        //initializing rooms and setting currentRoom as starting room
        initializeRooms();
        player = new Player();
        currentRoom = rooms["start"];
    }

    ~Game() {
        //deleting player memory in all rooms
        delete player;
        for (auto& roomPair : rooms) {
            delete roomPair.second;
        }
    }

    //reading user commands for processing
    void Run() {
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
            //checking user movement
            else if (command.EqualTo("move north") || command.EqualTo("move south") ||
                command.EqualTo("move east") || command.EqualTo("move west")) {
                move(command);
            }
            //using item
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

private:
    //initializing rooms
    void initializeRooms() {
        
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

    //movement of player in the rooms
    void move(const String& movement) {
        String dir = movement.Replace("move ", "");
        auto it = exits[currentRoomDesc()].find(dir.CStr());
        if (it != exits[currentRoomDesc()].end()) {
            currentRoom = rooms[it->second];
        }
        //checking if the dirrectio is valid
        else {
            std::cout << "You can't move in that direction.\n";
        }
    }

    void useItem() {
        Item* Item = currentRoom->Item();
        if (Item) {
            Item->Use();
        }
        else {
            std::cout << "There is no item to use in this room.\n";
        }
    }

    std::string currentRoomDesc() const {
        for (const auto& pair : rooms) {
            if (pair.second == currentRoom) {
                return pair.first;
            }
        }
        return "";
    }

    Room* currentRoom;
    Player* player;
    std::map<std::string, Room*> rooms;
    std::map<std::string, std::map<std::string, std::string>> exits;
};