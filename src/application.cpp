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
    Configuration config{};
    while (!m_windowHandler->closeWindow())
    {
        glClearColor(config.m_bgColor.r,config.m_bgColor.g,config.m_bgColor.b,config.m_bgColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_imgui->IMGUIStart();
        m_windowHandler->processInput();
        m_imgui->fileSystemUI(config);


        if(m_molecule)
        {
            m_molecule->render(m_windowHandler->getWindowSize(), config.m_position,config.m_rotation, glm::vec1(config.m_radius));

        }
        if(m_molecule==nullptr || config.m_selectedPath!=config.m_moleculePath)
        {
            if(loadMolecule(config.m_selectedPath.c_str()))
            {
                config.m_moleculePath=config.m_selectedPath;
                std::cout<<config.m_moleculePath<<std::endl;
            }
        }
        m_imgui->IMGUIRender();
        if(config.m_showFPS)
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
    
    if(Utils::ends_with(path,".xyz"))
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
