#ifndef MOLECULE_H
#define MOLECULE_H
#include <vector>
#include "atom.h"
#include "shader.h"
#include "xyzParser.h"
#include "glad/glad.h"
#include "sphere.h"
#include "cylinder.h"
#include "utils.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class Molecule
{
public:
    Molecule(const char* path);
    ~Molecule() = default;
    std::string getName() const{return m_name;};
    std::vector<Atom> getAtoms() const{return m_atoms;};
    void printAtoms() const;
    void render(glm::vec2 screenSize, glm::vec3 pos,glm::vec3 rot, glm::vec1 radius );
private:
    std::vector<Atom> m_atoms;
    std::string m_name;
};


#endif