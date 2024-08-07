#ifndef IMGUI_INIT_H
#define IMGUI_INIT_H
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "glm/glm.hpp"
#include "imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <string>
#include"appConfig.h"
#include "fileDialog.h"
class IMGUI
{
public:
    IMGUI(GLFWwindow* window);
    ~IMGUI();
    void IMGUIStart();
    void IMGUIRender();
    void renderUI(Configuration &config);
    void fileSystemUI(Configuration &config);
    void warningUI(std::string &warning, bool *pOpen);
private:
};
#endif
