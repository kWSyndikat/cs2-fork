#include "resolver.hpp"
#include "../../interfaces/interfaces.hpp"

Resolver g_resolver;

float Resolver::getBestYaw(C_CSPlayerPawn* player) {
    float baseYaw = player->m_angEyeAngles().y;
    int stage = bruteStage[player->GetIndex() % 64];
    
    if (stage == 0) return baseYaw + 180.f;
    if (stage == 1) return baseYaw + 90.f;
    if (stage == 2) return baseYaw - 90.f;
    return baseYaw;
}

void Resolver::run(C_CSPlayerPawn* player) {
    if (!player || !player->IsAlive()) return;
    player->m_angEyeAngles().y = getBestYaw(player);
}