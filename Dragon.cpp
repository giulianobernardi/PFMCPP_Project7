#include "Dragon.h"
#include "DragonSlayer.h"
#include "Utility.h"

Dragon::Dragon(std::string name_, int hp_, int armor_) : 
    Character(hp_, armor_, 80), // Attack for Dragon is 80
    name(name_) // Name not included in Character class
    {}

const std::string& Dragon::getName() 
{
    return name;
}

std::string Dragon::getStats() 
{
    return getCharacterStats(this); // Function defined in Utility.h
}


void Dragon::attack(Character &other)
{
    std::cout << name << " is attacking " << other.getName() << "!!!" << std::endl;
    if( auto* slayer = dynamic_cast<DragonSlayer*>(&other) )
    {
        //dragons can't attack dragon slayers
        slayer->defend();
    }
    else
    {
        Character::attack(other);
    }
}

//Dragon::getName

//Dragon::getStats
