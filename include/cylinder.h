#ifndef CYLINDER_H
#define CYLINDER_H
#include "glm/glm.hpp"
#include <vector>
#include "glad/glad.h"
#include "circle.h"
#include <iostream>

namespace Cylinder
{
    const float PI = 3.14159265359f;
    void generateCylinder(const glm::vec3& start, const glm::vec3& end, float radius,float length, int segments, std::vector<glm::vec3>& vertices, std::vector<unsigned int>& indices);
}
#endif