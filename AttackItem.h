#pragma once

#include "Item.h"
#include "Character.h"

struct AttackItem : Item
{
    AttackItem() : Item("attack item", 10) { } // AttackItem has 10 effect
    ~AttackItem() override {}
    void use(Character* character) override;
};
