#ifndef UTILS_H
#define UTILS_H

#include <glm/glm.hpp>
#include <string>
#include <unordered_map>

class Utils
{
public:
    Utils() = delete;

    static std::unordered_map<std::string, glm::vec3> atomColor;
    static std::unordered_map<std::string, float> atomRadius;
    static std::unordered_map<std::string, float> covalentRadii;
    static bool ends_with(const std::string& str, const std::string& suffix);
};

#endif // UTILS_H
