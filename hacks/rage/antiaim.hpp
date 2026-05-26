#pragma once
#include "../hacks.hpp"

class AntiAim {
public:
    void run(CUserCmd* cmd);
    bool shouldAA();

private:
    void fakeAngles(CUserCmd* cmd);
    void jitter(CUserCmd* cmd);
    void spin(CUserCmd* cmd);
};

extern AntiAim g_antiaim;