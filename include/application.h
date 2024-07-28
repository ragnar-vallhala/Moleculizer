#ifndef APPLICATION_H
#define APPLICATION_H
#include "windowHandler.h"
#include "imgui_init.h"
#include "glad/glad.h"
#include <chrono>
#include <string>
#include "shader.h"
#include "molecule.h"


class Application
{
public:
    Application();
    ~Application();
    void run();
    void putFPS();
    bool loadMolecule(const char* path);
private:
    WindowHandler *m_windowHandler = nullptr;
    IMGUI *m_imgui = nullptr;
    std::chrono::time_point<std::chrono::system_clock> m_lastTime;
    std::string m_graphicsCard;
    Molecule *m_molecule = nullptr;
};
#endif