#ifndef CIRCLE_H
#define CIRCLE_H
/*
    To draw a circle in space about a given center (x1,y1,z1) in a plane with normal (ai,bj,ck) and radius r:
    1. Take z=0
    2. D = 4a^2r^2(a^2+b^2)
    3. y = (sqrt(D))/(2(a^2+b^2))
    4. x = -by/a
    5. Get the coordinates of the point by adding x1,y1and z1 to x,y and z.
    6. Now rotate this point about a line parallel to normal and passing through (x1,y1,z1)
    7. For the below function pass the normal passing through the center of the circle 

*/
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
namespace Circle
{
    const float PI = 3.14159265358979323846f;
    void generateCircle(glm::vec3 normal,glm::vec3 center,float radius, unsigned int segments, std::vector<glm::vec3>&vertices);
};
#endif