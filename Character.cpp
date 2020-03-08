#include "Character.h"
#include <iostream>
#include <vector>
#include <math.h> 

#include "DefensiveItem.h"
#include "HelpfulItem.h"

Character::Character(int hp, int armor_, int attackDamage_ ) :
    hitPoints(hp),
    armor(armor_),
    attackDamage(attackDamage_)
{
    initialHitPoints.reset( new int(hitPoints) );
    initialArmorLevel.reset( new int( armor) );
    initialAttackDamage.reset( new int( attackDamage) );
}

void Character::attack( Character& other )
{
    if( hitPoints <= 0 )
    {
        std::cout << getName() << " can't attack. " << getName() << " is dead." << std::endl;
        std::cout << "make another party member use an item to revive them" << std::endl << std::endl;
        return;
    }
        
    isDefending = false;
    std::cout << getName() << " has attacked " << other.getName() << std::endl;
    //subtract attackDamage from other->hitPoints
    if( other.takeDamage(attackDamage) <= 0 )
    {
        //if you kill other, you get a boost in hit points and armor.
        attackInternal(other);
    }
}

void Character::defend()
{
    std::cout << getName() << " is defending!!" << std::endl;
    for( auto& item : defensiveItems )
    {
        if( auto* defensiveItem = dynamic_cast<DefensiveItem*>(item.get()) )
        {
            defensiveItem->use(this);
            item.reset(); //can only be used once!
            break;
        }
    }
    isDefending = true;
}

void Character::help(Character& other)
{
    std::cout << getName() << " is going to help " << other.getName() << std::endl;
    for( auto& item : helpfulItems )
    {
        if( auto* helpfulItem = dynamic_cast<HelpfulItem*>(item.get()) )
        {
            helpfulItem->use(&other);
            item.reset(); //can only be used once!
            break;
        }
    }
}

int Character::takeDamage(int damage)
{
    std::cout << getName() << " is taking " << damage << " damage!" << std::endl;
    if( damage < armor )
    {
        armor -= damage;
    }
    else
    {
        damage -= armor;
        armor = 0;
        
        hitPoints -= damage;
        if( hitPoints < 0 )
        {
            std::cout << getName() << " has died in battle!" << std::endl;
            hitPoints = 0;
        }
    }
    printStats();
    return hitPoints;
}


// #include <assert>
void Character::attackInternal(Character& other)
{
    if( other.hitPoints <= 0 )
    {
        if (hitPoints < *initialHitPoints)
            hitPoints = round(static_cast<double>(*initialHitPoints) * 1.10);
        else 
            hitPoints = round(static_cast<double>(hitPoints) * 1.10);
        if (armor < *initialArmorLevel)
            armor = round(static_cast<double>(*initialArmorLevel) * 1.10);
        else
            armor = round(static_cast<double>(armor) * 1.10);
        if (attackDamage < *initialAttackDamage)            
            attackDamage = round(static_cast<double>(*initialAttackDamage) * 1.10);
        else
            attackDamage = round(static_cast<double>(attackDamage) * 1.10);
        *initialHitPoints = hitPoints;
        *initialArmorLevel = armor;
        *initialAttackDamage = attackDamage;
        /*
        When you defeat another Character: 
            a) your stats are restored to their initial value if they are lower than it.
            b) your stats are boosted 10%
            c) the initial value of your stats is updated to reflect this boosted stat for the next time you defeat another character.
      */
        // assert(false);
        std::cout << getName() << " defeated " << other.getName() << " and leveled up!" << std::endl;    
        printStats();    
    }
}
