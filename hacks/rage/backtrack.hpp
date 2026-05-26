#pragma once
#include "../../classes/entity.hpp"
#include <vector>

struct BacktrackRecord {
    float simtime;
    Vector origin;
    Vector angles;
};

class Backtrack {
public:
    void update();
    BacktrackRecord* getBestRecord(C_CSPlayerPawn* player);

private:
    std::vector<BacktrackRecord> records[64];
};

extern Backtrack g_backtrack;