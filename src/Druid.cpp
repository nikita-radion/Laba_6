#include "../include/Druid.h"

Druid::Druid(const std::string& name, int x, int y) 
    : NPC(name, x, y) {}

std::string Druid::getType() const {
    return "Druid";
} 