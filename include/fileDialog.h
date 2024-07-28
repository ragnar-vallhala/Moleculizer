#ifndef FILEDIALOG_H
#define FILEDIALOG_H
#include <iostream>
#include <filesystem>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
namespace fs = std::filesystem;

bool showFileDialog(const char* label, std::string& selectedPath);

#endif