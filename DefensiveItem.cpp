#include "DefensiveItem.h"
// #include "Dwarf.h"
// #include "Paladin.h"
// #include "DragonSlayer.h"
// #include "Dragon.h"
#include "Utility.h"
// #include <assert>

void DefensiveItem::use(Character* character)
{
    // assert(false); 
    //make your defensive item use the appropriate Utility helper functions
    useDefensiveItem(character, *this);  // From Utility.h
}
