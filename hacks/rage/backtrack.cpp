#include "backtrack.hpp"
#include "../../interfaces/interfaces.hpp"

Backtrack g_backtrack;

void Backtrack::update() {
    for (int i = 1; i <= 64; i++) {
        C_CSPlayerPawn* player = interfaces::entityList->GetEntityByIndex<C_CSPlayerPawn>(i);
        if (!player || !player->IsAlive() || player->IsDormant()) continue;

        BacktrackRecord rec;
        rec.simtime = player->m_flSimulationTime();
        rec.origin = player->m_vOldOrigin();
        rec.angles = player->m_angEyeAngles();

        records[i].push_back(rec);
        if (records[i].size() > 12) records[i].erase(records[i].begin());
    }
}

BacktrackRecord* Backtrack::getBestRecord(C_CSPlayerPawn* player) {
    if (!player) return nullptr;
    int idx = player->GetIndex();
    if (records[idx].empty()) return nullptr;
    return &records[idx].back();
}