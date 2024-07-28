#ifndef UTILS_H
#define UTILS_H
#include <glm/glm.hpp>
#include <string>
#include <unordered_map>

class Utils
{

public:
    Utils()=delete;
    inline static std::unordered_map<std::string, glm::vec3> atomColor = {
        {"H", glm::vec3(0.8f, 0.8f, 0.8f)},   // Hydrogen - Light Grey
        {"C", glm::vec3(0.3f, 0.3f, 0.3f)},   // Carbon - Dark Grey
        {"N", glm::vec3(0.0f, 0.0f, 1.0f)},   // Nitrogen - Blue
        {"O", glm::vec3(1.0f, 0.0f, 0.0f)},   // Oxygen - Red
        {"F", glm::vec3(0.0f, 1.0f, 0.0f)},   // Fluorine - Green
        {"Cl", glm::vec3(0.0f, 1.0f, 0.0f)},  // Chlorine - Green
        {"Br", glm::vec3(0.65f, 0.16f, 0.16f)}, // Bromine - Dark Red
        {"I", glm::vec3(0.58f, 0.0f, 0.58f)}, // Iodine - Purple
        {"He", glm::vec3(0.85f, 1.0f, 1.0f)}, // Helium - Light Blue
        {"Ne", glm::vec3(0.7f, 0.89f, 0.96f)}, // Neon - Light Blue
        {"Ar", glm::vec3(0.5f, 0.82f, 0.89f)}, // Argon - Light Blue
        {"Xe", glm::vec3(0.26f, 0.62f, 0.69f)}, // Xenon - Light Blue
        {"Kr", glm::vec3(0.36f, 0.72f, 0.82f)}, // Krypton - Light Blue
        {"P", glm::vec3(1.0f, 0.65f, 0.0f)},  // Phosphorus - Orange
        {"S", glm::vec3(1.0f, 1.0f, 0.0f)},   // Sulfur - Yellow
        {"B", glm::vec3(1.0f, 0.7f, 0.7f)},   // Boron - Pink
        {"Li", glm::vec3(0.8f, 0.5f, 1.0f)},  // Lithium - Purple
        {"Na", glm::vec3(0.67f, 0.36f, 0.95f)}, // Sodium - Purple
        {"K", glm::vec3(0.56f, 0.25f, 0.83f)}, // Potassium - Purple
        {"Ca", glm::vec3(0.24f, 1.0f, 0.0f)}, // Calcium - Green
        {"Fe", glm::vec3(0.88f, 0.4f, 0.2f)}, // Iron - Orange
        {"Al", glm::vec3(0.75f, 0.65f, 0.65f)}, // Aluminum - Light Gray
        {"Au", glm::vec3(1.0f, 0.85f, 0.0f)}, // Gold - Gold
        {"Ag", glm::vec3(0.75f, 0.75f, 0.75f)}, // Silver - Silver
        {"Mg", glm::vec3(0.54f, 1.0f, 0.0f)}, // Magnesium - Green
        {"Si", glm::vec3(0.94f, 0.78f, 0.63f)} // Silicon - Tan
    };
    inline static std::unordered_map<std::string, float> atomRadius = {
        {"H", 0.31f},    // Hydrogen
        {"C", 0.76f},    // Carbon
        {"N", 0.71f},    // Nitrogen
        {"O", 0.66f},    // Oxygen
        {"F", 0.57f},    // Fluorine
        {"Cl", 1.02f},   // Chlorine
        {"Br", 1.20f},   // Bromine
        {"I", 1.39f},    // Iodine
        {"He", 0.28f},   // Helium
        {"Ne", 0.38f},   // Neon
        {"Ar", 0.88f},   // Argon
        {"Xe", 1.08f},   // Xenon
        {"Kr", 1.10f},   // Krypton
        {"P", 1.07f},    // Phosphorus
        {"S", 1.05f},    // Sulfur
        {"B", 0.85f},    // Boron
        {"Li", 1.52f},   // Lithium
        {"Na", 1.86f},   // Sodium
        {"K", 2.27f},    // Potassium
        {"Ca", 1.97f},   // Calcium
        {"Fe", 1.72f},   // Iron
        {"Al", 1.84f},   // Aluminum
        {"Au", 1.44f},   // Gold
        {"Ag", 1.72f},   // Silver
        {"Mg", 1.73f},   // Magnesium
        {"Si", 1.11f}    // Silicon
    };

    inline static std::unordered_map<std::string, float> covalentRadii = {
        {"H", 0.31f},       // Hydrogen
        {"C", 0.76f},       // Carbon
        {"N", 0.71f},       // Nitrogen
        {"O", 0.66f},       // Oxygen
        {"F", 0.57f},       // Fluorine
        {"Cl", 1.02f},      // Chlorine 
        {"Br", 1.20f},      // Bromine 
        {"I", 1.39f},       // Iodine
        {"He", 0.28f},      // Helium 
        {"Ne", 0.38f},      // Neon 
        {"Ar", 0.88f},      // Argon 
        {"Xe", 1.08f},      // Xenon
        {"Kr", 1.10f},      // Krypton 
        {"P", 1.07f},       // Phosphoru
        {"S", 1.05f},       // Sulfur
        {"B", 0.85f},       // Boron
        {"Li", 1.52f},      // Lithium 
        {"Na", 1.86f},      // Sodium 
        {"K", 2.27f},       // Potassium
        {"Ca", 1.97f},      // Calcium
        {"Fe", 1.72f},      // Iron 
        {"Al", 1.84f},      // Aluminum 
        {"Au", 1.44f},      // Gold 
        {"Ag", 1.72f},      // Silver
        {"Mg", 1.73f},      // Magnesium 
        {"Si", 1.11f}       // Silicon
    };
};

#endif
