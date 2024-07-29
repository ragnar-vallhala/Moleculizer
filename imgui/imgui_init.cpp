#include "imgui_init.h"

IMGUI::IMGUI(GLFWwindow* window)
{
    const char* glsl_version = "#version 130";
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
}

IMGUI::~IMGUI()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void IMGUI::IMGUIStart()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
        
}

void IMGUI::IMGUIRender()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    // #ifdef DEBUG
    // std::cout<<"Rendering UI"<<std::endl;
    // #endif
}

void IMGUI::renderUI(Configuration &config)
{
    ImGui::Begin("Control", &config.m_showControl);

    ImGui::InputFloat3("Position",&config.m_position.x);
    ImGui::SliderFloat("X", &config.m_position.x, -50.0f, 50.0f);
    ImGui::SliderFloat("Y", &config.m_position.y, -50.0f, 50.0f);
    ImGui::SliderFloat("Z", &config.m_position.z, -50.0f, 50.0f);
    
    ImGui::InputFloat3("Rotation",&config.m_rotation.x);
    ImGui::SliderFloat("RotX", &config.m_rotation.x, -180.0f, 180.0f);
    ImGui::SliderFloat("RotY", &config.m_rotation.y, -180.0f, 180.0f);
    ImGui::SliderFloat("RotZ", &config.m_rotation.z, -180.0f, 180.0f);
    
    ImGui::SliderFloat("Radius", &config.m_radius, 0.0f, 25.0f);
    ImGui::ColorEdit3("Pick a color", (float*)&config.m_bgColor);
    ImGui::End();
}

void IMGUI::fileSystemUI(Configuration &config)
{
    if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("Open")) {  config.m_showDialog = true; }
                if (ImGui::MenuItem("Save")) {}
                ImGui::Checkbox("Toggle FPS", &config.m_showFPS);
                if (ImGui::MenuItem("Exit")) { /* Do something */ }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Edit")) {
                if (ImGui::MenuItem("Undo", "Ctrl+Z")) { /* Do something */ }
                if (ImGui::MenuItem("Redo", "Ctrl+Y", false, false)) { /* Disabled item */ }
                ImGui::Separator();
                if (ImGui::MenuItem("Cut", "Ctrl+X")) { /* Do something */ }
                if (ImGui::MenuItem("Copy", "Ctrl+C")) { /* Do something */ }
                if (ImGui::MenuItem("Paste", "Ctrl+V")) { /* Do something */ }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("View"))
            {
                ImGui::Checkbox("Toggle Controls", &config.m_showControl);
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
    if (config.m_showDialog) {
        if (showFileDialog("File Dialog", config.m_selectedPath)) {
            config.m_showDialog = false;
        }
    }
    if(config.m_showControl)
        renderUI(config);
}

void IMGUI::warningUI(std::string &warning, bool *pOpen)
{
    ImGui::Begin("Warning");
    ImGui::Text(warning.c_str());
    ImGui::End();
}
