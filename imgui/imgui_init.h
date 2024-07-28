#ifndef IMGUI_INIT_H
#define IMGUI_INIT_H
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "glm/glm.hpp"
#include "imgui_impl_opengl3.h"
#include "glfw/glfw3.h"
#include <iostream>
#include <string>
#include "fileDialog.h"
class IMGUI
{
public:
    IMGUI(GLFWwindow* window);
    ~IMGUI();
    void IMGUIStart();
    void IMGUIRender();
    void renderUI(float &x,float &y,float &z,float &rotX,float &rotY,float &rotZ, float &r, bool& showControl,  glm::vec4 &bgColor);
    void fileSystemUI(std::string &path, bool &showDialog,  bool &showControl, float &x,float &y,float &z,float &rotX,float &rotY,float &rotZ, float &r, glm::vec4 &bgColor, bool &showFPS);
    void warningUI(std::string &warning, bool *pOpen);
private:
};
#endif