#include "application.h"
Application::Application()
{
    this->m_windowHandler = new WindowHandler("Moleculizer");
    this->m_imgui = new IMGUI(m_windowHandler->getWindow());
    this->m_graphicsCard = std::string((char*)glGetString(GL_RENDERER));
}

Application::~Application()
{
    delete m_windowHandler;
    delete m_imgui;
    if (m_molecule)
        delete m_molecule;
}

void Application::run()
{
    auto currentTime = std::chrono::system_clock::now();

    // Variables for file dialog
    bool showDialog = false;
    bool showControl = false;
    bool showFPS = false;
    std::string moleculePath;
    std::string selectedPath;
    bool drawable = false;
    float posX = 0.0;
    float posY = 0.0;
    float posZ = -7.0;
    float radius = 1.3;
    float rotX{},rotY{},rotZ{}; 
    glm::vec4 bgColor{1.0f, 1.0f, 1.0f, 1.0f};

    while (!m_windowHandler->closeWindow())
    {
        glClearColor(bgColor.r,bgColor.g,bgColor.b,bgColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_imgui->IMGUIStart();
        m_windowHandler->processInput();
        m_imgui->fileSystemUI(selectedPath,showDialog,showControl, posX,posY,posZ,rotX,rotY,rotZ, radius,bgColor,showFPS);
        if(drawable)
        {
            m_molecule->render(m_windowHandler->getWindowSize(), glm::vec3(posX,posY,posZ),glm::vec3(rotX,rotY,rotZ), glm::vec1(radius));
        }
        if(selectedPath!="" && selectedPath!=moleculePath)
        {
            if(loadMolecule(selectedPath.c_str()))
            {
                moleculePath=selectedPath;
                std::cout<<moleculePath<<std::endl;
                drawable = true;
            }
            else
            {
                drawable = false;
            }
        }
        m_imgui->IMGUIRender();
        if(showFPS)
            this->putFPS();
        else    glfwSetWindowTitle(m_windowHandler->getWindow(),("Moleculizer"));

        glfwSwapBuffers(m_windowHandler->getWindow());
        glfwPollEvents();

    }
}

void Application::putFPS()
{
    auto diff = std::chrono::system_clock::now() - m_lastTime;
    float fps = 1/ (std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() / 1000.0f);
    m_lastTime = std::chrono::system_clock::now();
    glfwSetWindowTitle(m_windowHandler->getWindow(),("Moleculizer\t" + std::to_string(fps)).c_str());
}

bool Application::loadMolecule(const char *path)
{
    if(((std::string)path).ends_with(".xyz"))
    {
        m_molecule = new Molecule(path);
    }
    else
    {
        std::string message = "Invalid xyz file.";
        bool pOpen = true;
        if (pOpen)
            m_imgui->warningUI(message, &pOpen);
        return !pOpen;
    }
    return true;
}
