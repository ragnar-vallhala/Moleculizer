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

void IMGUI::renderUI(float &x,float &y,float &z,float &rotX,float &rotY,float &rotZ, float &r, bool &showControl,  glm::vec4 &bgColor)
{
    ImGui::Begin("Control", &showControl);
    ImGui::SliderFloat("X", &x, -10.0f, 10.0f);
    ImGui::SliderFloat("Y", &y, -10.0f, 10.0f);
    ImGui::SliderFloat("Z", &z, -10.0f, 10.0f);
    ImGui::SliderFloat("RotY", &rotX, -180.0f, 180.0f);
    ImGui::SliderFloat("RotX", &rotY, -180.0f, 180.0f);
    ImGui::SliderFloat("RotZ", &rotZ, -180.0f, 180.0f);
    ImGui::SliderFloat("radius", &r, 0.0f, 5.0f);
    ImGui::ColorEdit3("Pick a color", (float*)&bgColor);
    ImGui::End();
}

void IMGUI::fileSystemUI(std::string &path, bool &showDialog,  bool &showControl,float &x,float &y,float &z,float &rotX,float &rotY,float &rotZ, float &r,  glm::vec4 &bgColor, bool &showFPS)
{
    ImGui::Begin("Menu");
        if (ImGui::Button("Select file")) {
            showDialog = true;
        }
        if (ImGui::Button("UI Control")) {
            showControl = !showControl;
        }
        ImGui::Checkbox("Toggle FPS", &showFPS);
        if (showDialog) {
            if (showFileDialog("File Dialog", path)) {
                showDialog = false;
            }
        }
    ImGui::End();

    if(showControl)
        renderUI(x,y,z,rotX,rotY,rotZ, r, showControl,bgColor);
}

void IMGUI::warningUI(std::string &warning, bool *pOpen)
{
    ImGui::Begin("Warning");
    ImGui::Text(warning.c_str());
    ImGui::End();
}
