#include "fileDialog.h"



bool showFileDialog(const char* label, std::string& selectedPath) {
    static std::string currentPath = fs::current_path().string();
    static std::vector<std::string> items;
    static bool updateItems = true;

    if (updateItems) {
        items.clear();
        for (const auto& entry : fs::directory_iterator(currentPath)) {
            items.push_back(entry.path().string());
        }
        updateItems = false;
    }
    bool pOpen = true;
    bool selected = false;
    ImGui::Begin(label,&pOpen);
    if (ImGui::Button("..")) {
        currentPath = fs::path(currentPath).parent_path().string();
        updateItems = true;
    }

    for (const auto& item : items) {
        if (ImGui::Selectable(item.c_str(), false)) {
            if (fs::is_directory(item)) {
                currentPath = item;
                updateItems = true;
            } else {
                selectedPath = item;
                selected = true;
            }
        }
    }

    ImGui::End();
    if(!pOpen) return true;
    return selected;
}    

