#pragma once
#include "NPC.h"

class Orc : public NPC {
public:
    Orc(const std::string& name, int x, int y);
    std::string getType() const override;
}; 