#ifndef APPCONFIG_H
#define APPCONFIG_H
//Configures the app data

#include <string>
#include <sstream>
#include "glm/glm.hpp"
#include <fstream>
#include <iostream>

typedef struct Configuration
{

    glm::vec3 m_position{0,0,-7};
    glm::vec3 m_rotation{0};
    float m_radius{1.3f};

    glm::vec4 m_bgColor{1.0f, 1.0f, 1.0f, 1.0f};

    std::string m_moleculePath{};
    std::string m_selectedPath{};

    bool m_showDialog{false};
    bool m_showControl{true};
    bool m_showFPS{false};
    Configuration();
    ~Configuration();
}Configuration;

#endif