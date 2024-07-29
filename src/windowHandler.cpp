#include "windowHandler.h"


WindowHandler::WindowHandler(const char* window_name)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_SAMPLES, 8); 

    m_window = glfwCreateWindow(800,600, window_name, NULL, NULL);
    if(m_window==nullptr)
    {
        std::cerr<<"Can't Create Window!"<<std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(m_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr<<"Failed to initialize GLAD"<<std::endl;
    }
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void WindowHandler::processInput(void) const
{
    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
        glfwSetWindowShouldClose(m_window, true);
}

WindowHandler::~WindowHandler()
{
    glfwTerminate();
}

GLFWwindow *WindowHandler::getWindow() const
{
    return m_window;
}

glm::vec2 WindowHandler::getWindowSize() const
{
    int x,y;
    glfwGetWindowSize(m_window, &x, &y);
    return glm::vec2(x,y);
}

bool WindowHandler::closeWindow() const
{
    return glfwWindowShouldClose(m_window);
}
