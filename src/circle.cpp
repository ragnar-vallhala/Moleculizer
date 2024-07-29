#include "circle.h"

void Circle::generateCircle(glm::vec3 normal, glm::vec3 center, float radius, unsigned int segments, std::vector<glm::vec3> &vertices)
{
    // 1. Take z=0
    // 2. D = 4a^2r^2(a^2+b^2)
    // 3. y = (sqrt(D))/(2(a^2+b^2))
    // 4. x = -by/a
    float x{},y{},z{};
    float D =(float) (4*pow(normal.x,2)*pow(radius,2)*(pow(normal.x,2)+pow(normal.y,2)));
    y = (float)(pow(D,0.5)/(2*(pow(normal.x,2)+pow(normal.y,2))));
    x = -normal.y*y/normal.x;
    
    // 5. Get the coordinates of the point by adding x1,y1and z1 to x,y and z.
    x+=center.x;
    y+=center.y;
    z+=center.z;

    float theta = 2*PI/segments;
    float angle = 0;
    while(angle<=2.2*PI)
    {
        glm::mat4 rotationMatrix = glm::mat4(1.0f);
        rotationMatrix = glm::rotate(rotationMatrix,angle,normal);
        glm::vec3 point = rotationMatrix * glm::vec4(x,y,z,1.0f);
        vertices.push_back(point);
        angle+=theta;
    }
}