#pragma once
#include "../../classes/entity.hpp"

class Resolver {
public:
    void run(C_CSPlayerPawn* player);
    float getBestYaw(C_CSPlayerPawn* player);

private:
    int bruteStage[64] = {0};
};

extern Resolver g_resolver;