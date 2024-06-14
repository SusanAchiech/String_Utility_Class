#include "Player.h"

// Constructor definition
Player::Player() {
    // Creating an array of spell names
    spells = { "Eclipse", "Frostbite", "Levitate", "Mirage", "Petrify", "Teleport", "Thunderwave", "Vortex" };
    std::sort(spells.begin(), spells.end());
}

// Destructor definition
Player::~Player() {}

// FindSpell method definition
bool Player::FindSpell(String spellName) {
    auto it = std::lower_bound(spells.begin(), spells.end(), spellName);

    // Checking if the player knows the spell
    if (it != spells.end() && *it == spellName) {
        std::cout << "You know the spell '" << spellName.getString() << "'." << std::endl;
        return true;
    }
    else {
        std::cout << "You do not know the spell '" << spellName.getString() << "'." << std::endl;
        return false;
    }
}
