#ifndef WINDOWHANDLER_H
#define WINDOWHANDLER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "glm/glm.hpp"

class WindowHandler
{
public:
    WindowHandler(const char* window_name);
    friend void framebufferSizeCallback(GLFWwindow* window, int width, int height);
    void processInput(void) const;
    GLFWwindow* getWindow() const;
    glm::vec2 getWindowSize() const;
    bool closeWindow()const;
    ~WindowHandler();

private:
    GLFWwindow* m_window = nullptr;
};
#endif

void framebufferSizeCallback(GLFWwindow* window, int width, int height);
