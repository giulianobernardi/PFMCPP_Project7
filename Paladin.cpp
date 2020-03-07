#include "Paladin.h"
#include "Utility.h"

Paladin::Paladin(std::string name_, int hp_, int armor_) : 
    Character(hp_, armor_, 10), // Attack for Paladin is 10
    name(name_) // Name not included in Character class
    {
        helpfulItems = makeHelpfulItems(random() % 10);
        defensiveItems = makeDefensiveItems(random() % 10);
    }

const std::string& Paladin::getName() 
{
    return name;
}

std::string Paladin::getStats() 
{
    return getCharacterStats(this); // Function defined in Utility.h
}

void Paladin::attack(Character& other)
{
    std::cout << name << " is attacking " << other.getName() << " !!" << std::endl;
    Character::attack(other);  
}
