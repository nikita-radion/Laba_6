#include "../include/BattleVisitor.h"
#include "../include/Orc.h"
#include "../include/Squirrel.h"
#include "../include/Druid.h"
#include <cmath>

BattleVisitor::BattleVisitor(int range) : battleRange(range) {}

void BattleVisitor::addObserver(IObserver* observer) {
    observers.push_back(observer);
}

void BattleVisitor::visit(INPC* npc1, INPC* npc2) {
    lastBattleResult = {false, false}; 

    int dx = npc1->getX() - npc2->getX();
    int dy = npc1->getY() - npc2->getY();
    double distance = std::sqrt(dx*dx + dy*dy);
    
    if (distance > battleRange) return;

    if (npc1->getType() == "Orc" && npc2->getType() == "Druid") {
        lastBattleResult.second = true; 
    }
    if (npc2->getType() == "Orc" && npc1->getType() == "Druid") {
        lastBattleResult.first = true; 
    }
    if (npc1->getType() == "Druid" && npc2->getType() == "Squirrel") {
        lastBattleResult.second = true; 
    }
    if (npc2->getType() == "Druid" && npc1->getType() == "Squirrel") {
        lastBattleResult.first = true; 
    }

    if (lastBattleResult.first || lastBattleResult.second) {
        std::string message = "Battle result: ";
        if (lastBattleResult.first) 
            message += npc1->getName() + " (" + npc1->getType() + ") died. ";
        if (lastBattleResult.second)
            message += npc2->getName() + " (" + npc2->getType() + ") died. ";
        
        for (auto observer : observers) {
            observer->update(message);
        }
    }
} 