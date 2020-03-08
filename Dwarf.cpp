#include "Dwarf.h"
#include "Utility.h"

Dwarf::Dwarf(std::string name_, int hp_, int armor_) : 
    Character(hp_, armor_, 4), // Attack for Dwarf is 4
    name(name_) // Name not included in Character class
    {
        helpfulItems = makeHelpfulItems(rand() % 10 + 1);
        defensiveItems = makeDefensiveItems(rand() % 10 + 1);
    }

const std::string& Dwarf::getName() 
{
    return name;
}

std::string Dwarf::getStats() 
{
    return getCharacterStats(this); // Function defined in Utility.h
}

void Dwarf::attack(Character& other)
{
    std::cout << name << " is attacking " << other.getName() << " !!" << std::endl;
    Character::attack(other);  
}
