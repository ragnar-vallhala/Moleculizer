#include "atom.h"

void getBonds(std::vector<Atom> &atoms, std::vector<glm::vec3>& starts, std::vector<glm::vec3>& ends)
{
    for (int i = 0; i < atoms.size(); i++)
    {
        for (int j = i + 1; j < atoms.size(); j++)
        {

           if(isBonded(atoms[i], atoms[j]))
           {
                starts.push_back(glm::vec3(atoms[i].x, atoms[i].y,atoms[i].z));      
                ends.push_back(glm::vec3(atoms[j].x, atoms[j].y,atoms[j].z));      
           }
        }
    }
}

bool isBonded(Atom A, Atom B)
{
    double distance = pow((pow(A.x-B.x,2) + pow(A.y-B.y,2) + pow(A.z-B.z,2)),0.5);
    if(Utils::covalentRadii[A.name]+Utils::covalentRadii[B.name]>distance) return true;
    else return false;
}
