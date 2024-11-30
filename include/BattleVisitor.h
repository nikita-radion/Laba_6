#pragma once
#include "IVisitor.h"
#include "IObserver.h"
#include <vector>

class BattleVisitor : public IVisitor {
private:
    int battleRange;
    std::vector<IObserver*> observers;
    std::pair<bool, bool> lastBattleResult;

public:
    BattleVisitor(int range);
    void addObserver(IObserver* observer);
    void visit(INPC* npc1, INPC* npc2) override;
    std::pair<bool, bool> getLastBattleResult() const { return lastBattleResult; }
}; 