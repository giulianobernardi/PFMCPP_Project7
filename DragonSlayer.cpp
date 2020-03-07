#include "DragonSlayer.h"
#include "Dragon.h"
#include "Utility.h"
#include <random>

DragonSlayer::DragonSlayer(std::string name_, int hp_, int armor_) : 
    Character(hp_, armor_, 4), // Attack for DragonSlayer is 4
    name(name_) // Name not included in Character class
    {
        helpfulItems = makeHelpfulItems(random() % 10);
        defensiveItems = makeDefensiveItems(random() % 10);
    }

const std::string& DragonSlayer::getName() 
{
    return name;
}

std::string DragonSlayer::getStats() 
{
    return getCharacterStats(this); // Function defined in Utility.h
}

void DragonSlayer::attack(Character& other)
{
    std::cout << name << " is attacking " << other.getName() << " !!" << std::endl;
    if( auto* dragon = dynamic_cast<Dragon*>(&other) )
    {
        // assert(false);
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.
        //so they should USE their attack item before attacking the dragon... 
        //
        // attackItem->use(this);
        // attackItem.reset();

        while( dragon->getHP() > 0 )
        {
          dragon->takeDamage(attackDamage);
        }
    }
        
    Character::attack(other);
        
}
