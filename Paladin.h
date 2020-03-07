#pragma once
#include "Character.h"

struct Paladin : Character
{
    Paladin(std::string name_, int hp_, int armor_);
    ~Paladin() override {}
    const std::string& getName() override;
    std::string getStats() override;
    void attack(Character& other) override;
private:
    const std::string name;
};
