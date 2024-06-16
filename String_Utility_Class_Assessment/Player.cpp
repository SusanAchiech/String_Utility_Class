#include "player.h"

Player::Player() {}
Player::~Player() {}

bool Player::FindSpell(String spellName) {
    return std::find(spells.begin(), spells.end(), spellName) != spells.end();
}
