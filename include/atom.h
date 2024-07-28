#ifndef ATOM_H
#define ATOM_H
#include<string>
#include<vector>
#include "glm/glm.hpp"
#include "utils.h"

typedef struct Atom
{
    float x,y,z,r;
    std::string name;
    Atom(float x, float y, float z, float r, std::string name): x(x), y(y), z(z), r(r), name(name){};
}Atom;

void getBonds(std::vector<Atom> &atoms, std::vector<glm::vec3>& starts, std::vector<glm::vec3>& ends);
bool isBonded(Atom A, Atom B);
#endif