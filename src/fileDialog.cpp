#include "fileDialog.h"
#include <imgui.h>

#if defined(_WIN32)
#include <windows.h>
#include <sys/types.h>
#include <sys/stat.h>

// Utility function to convert std::string to std::wstring
std::wstring stringToWString(const std::string& s) {
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    std::wstring r(len, L'\0');
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, &r[0], len);
    return r;
}

#else
#include <dirent.h>
#include <sys/stat.h>
#endif

static std::vector<std::string> getDirectoryContents(const std::string& path) {
    std::vector<std::string> items;

#if defined(_WIN32)
    std::wstring wpath = stringToWString(path);
    WIN32_FIND_DATAW findFileData;
    HANDLE hFind = FindFirstFileW((wpath + L"\\*").c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            const std::wstring fileOrDir = findFileData.cFileName;
            if (fileOrDir != L"." && fileOrDir != L"..") {
                items.push_back(path + "\\" + std::string(fileOrDir.begin(), fileOrDir.end()));
            }
        } while (FindNextFileW(hFind, &findFileData) != 0);
        FindClose(hFind);
    }
#else
    DIR* dir = opendir(path.c_str());
    if (dir != nullptr) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            const std::string fileOrDir = entry->d_name;
            if (fileOrDir != "." && fileOrDir != "..") {
                items.push_back(path + "/" + fileOrDir);
            }
        }
        closedir(dir);
    }
#endif

    return items;
}

bool showFileDialog(const char* label, std::string& selectedPath) {
    static std::string currentPath =
#if defined(_WIN32)
    "C:\\";
#else
    "/";
#endif
    static std::vector<std::string> items;
    static bool updateItems = true;

    if (updateItems) {
        items = getDirectoryContents(currentPath);
        updateItems = false;
    }

    bool pOpen = true;
    bool selected = false;
    ImGui::Begin(label, &pOpen);
    if (ImGui::Button("..")) {
        size_t pos = currentPath.find_last_of("/\\");
        if (pos != std::string::npos) {
            currentPath = currentPath.substr(0, pos);
            updateItems = true;
        }
    }

    for (const auto& item : items) {
#if defined(_WIN32)
        struct _stat info;
        _stat(item.c_str(), &info);
        bool isDir = (info.st_mode & _S_IFDIR) != 0;
#else
        struct stat info;
        stat(item.c_str(), &info);
        bool isDir = S_ISDIR(info.st_mode);
#endif
        if (ImGui::Selectable(item.c_str(), false)) {
            if (isDir) {
                currentPath = item;
                updateItems = true;
            } else {
                selectedPath = item;
                selected = true;
            }
        }
    }

    ImGui::End();
    if (!pOpen) return true;
    return selected;
}
