#include "antiaim.hpp"
#include "../../interfaces/interfaces.hpp"
#include "../../math.hpp"

AntiAim g_antiaim;

bool AntiAim::shouldAA() {
    return true; // später mit Menu
}

void AntiAim::fakeAngles(CUserCmd* cmd) {
    cmd->viewangles.y += 180.f;
}

void AntiAim::jitter(CUserCmd* cmd) {
    static bool side = false;
    side = !side;
    cmd->viewangles.y += side ? 90.f : -90.f;
}

void AntiAim::spin(CUserCmd* cmd) {
    static float spin = 0.f;
    spin += 30.f;
    if (spin > 360.f) spin = 0.f;
    cmd->viewangles.y = spin;
}

void AntiAim::run(CUserCmd* cmd) {
    if (!shouldAA() || (cmd->buttons & IN_ATTACK)) return;

    jitter(cmd);
    fakeAngles(cmd);
    cmd->viewangles.Normalize();
}