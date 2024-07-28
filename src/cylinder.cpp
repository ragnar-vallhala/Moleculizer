#include "cylinder.h"

void Cylinder::generateCylinder(const glm::vec3& start, const glm::vec3& end, float radius,float length, int segments, std::vector<glm::vec3>& vertices, std::vector<unsigned int>& indices) 
{
    
    std::vector<glm::vec3> firstCircleVertices;
    Circle::generateCircle(start-end,start,radius,segments,firstCircleVertices);
    std::vector<glm::vec3> secondCircleVertices;
    glm::vec3 factor = glm::vec3(length)*(end-start);
    Circle::generateCircle((end-start),end+factor,radius,segments,secondCircleVertices);
    
    // glm::vec3 normal = starts[1]-ends[1];
    // std::cout<<"\n\nCircle Center"<<std::endl;
    // std::cout<<starts[1].x<<" "<<starts[1].y<<" "<<starts[1].z<<std::endl;
    // std::cout<<"\n\nCircle Normal"<<std::endl;
    // std::cout<<normal.x<<" "<<normal.y<<" "<<normal.z<<std::endl;
    // std::cout<<"\n\nCircle Vertices"<<std::endl;


    if(firstCircleVertices.size()<=0) return;

    vertices.push_back(firstCircleVertices[0]);
    vertices.push_back(firstCircleVertices[0]-start);
    int i{1},j{};

    while (j<secondCircleVertices.size())
    {   
        if(j<secondCircleVertices.size())
        {
            vertices.push_back(secondCircleVertices[j]);
            vertices.push_back(secondCircleVertices[j]-end);
            j++;
        }
        if(j<secondCircleVertices.size())
        {
            vertices.push_back(secondCircleVertices[j]);
            vertices.push_back(secondCircleVertices[j]-end);
            j++;
        }
        if(i<firstCircleVertices.size())
        {   
            vertices.push_back(firstCircleVertices[i]);
            vertices.push_back(firstCircleVertices[i]-start);
            i++;
        }
        if(i<firstCircleVertices.size())
        {   
            vertices.push_back(firstCircleVertices[i]);
            vertices.push_back(firstCircleVertices[i]-start);
            i++;
        }

        
    }

    int maxIndex = 2*firstCircleVertices.size()-1;
    int index=0;
    while(index+5<=maxIndex)
    {
        indices.push_back(index);
        indices.push_back(index+1);
        indices.push_back(index+2);

        indices.push_back(index+2);
        indices.push_back(index+3);
        indices.push_back(index);

        indices.push_back(index+3);
        indices.push_back(index+2);
        indices.push_back(index+5);


        indices.push_back(index+5);
        indices.push_back(index+4);
        indices.push_back(index+3);

        index+=4;
    }
    if(index+3<=maxIndex)
    {
        indices.push_back(index);
        indices.push_back(index+1);
        indices.push_back(index+2);


        indices.push_back(index+2);
        indices.push_back(index+3);
        indices.push_back(index);

        index+=2;
    }
    
}