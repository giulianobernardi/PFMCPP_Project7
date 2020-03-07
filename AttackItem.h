#pragma once

#include "Item.h"
#include "Character.h"

struct AttackItem : Item
{
    AttackItem() : Item("attack item", 3) { }
    ~AttackItem() override {}
    void use(Character* character) override;
};
