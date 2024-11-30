#include "../include/NPC.h"
#include <stdexcept>

NPC::NPC(const std::string& name, int x, int y) 
    : name(name), x(x), y(y) {
    if (x < 0 || x > 500 || y < 0 || y > 500) {
        throw std::invalid_argument("Coordinates must be between 0 and 500");
    }
}

std::string NPC::getName() const { return name; }
int NPC::getX() const { return x; }
int NPC::getY() const { return y; } 