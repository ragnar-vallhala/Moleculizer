#ifndef SPHERE_H
#define SPHERE_H
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
namespace Sphere
{
    const float PI = 3.14159265359f;
    void generateSphere(std::vector<float>& vertices, std::vector<unsigned int>& indices, unsigned int X_SEGMENTS=64,unsigned int Y_SEGMENTS = 64);
}
#endif