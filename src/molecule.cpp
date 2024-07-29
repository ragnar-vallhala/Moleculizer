#include "molecule.h"



Molecule::Molecule(const char * path)
{
    m_atoms = XYZ::getAtoms(path);
    m_name = XYZ::getName(path);
}

void Molecule::printAtoms() const
{
#ifdef DEBUG
    for (auto & atom : m_atoms)
    {
        std::cout << atom.name<<" "<< atom.x<<" "<< atom.y<<" "<< atom.z<<" " << std::endl;
    }
#endif
}

void Molecule::render(glm::vec2 screenSize, glm::vec3 pos,glm::vec3 rot, glm::vec1 radius )
{
    if(m_name!="")
    {
        ImGui::Begin("Molecule");
        ImGui::Text(m_name.c_str());
        ImGui::End();
    }
    
    if(m_atoms.size()>0)
    {
        
        Shader shader = Shader("../../shaders/sphereVert.glsl","../../shaders/sphereFrag.glsl");
        std::vector<float> sphereVertices;
        std::vector<unsigned int> sphereIndices;
        Sphere::generateSphere(sphereVertices, sphereIndices);
        
        GLuint sphereVAO, sphereVBO, sphereEBO;
        glGenVertexArrays(1, &sphereVAO);
        glGenBuffers(1, &sphereVBO);
        glGenBuffers(1, &sphereEBO);    
        glBindVertexArray(sphereVAO);

        glBindBuffer(GL_ARRAY_BUFFER, sphereVBO);
        glBufferData(GL_ARRAY_BUFFER, sphereVertices.size() * sizeof(float), sphereVertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphereEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sphereIndices.size() * sizeof(unsigned int), sphereIndices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);


        std::vector<glm::vec3> cylinderVertices;
        std::vector<unsigned int> cylinderIndices;
        std::vector<glm::vec3> starts;
        std::vector<glm::vec3> ends;
        getBonds(m_atoms,starts,ends);





        
        shader.useProgram();

        for(int i{};i<m_atoms.size();i++)
        {
            Atom atom  = m_atoms[i];

            // Set up transformation matrices
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(atom.x,atom.y,atom.z)); // Translate the object
            model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate the object
            model = glm::scale(model, glm::vec3(Utils::atomRadius[atom.name])*radius); // Scale the object

            glm::mat4 view = glm::translate(glm::mat4(1.0f), pos);
            view = glm::rotate(view,glm::radians(rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
            view = glm::rotate(view,glm::radians(rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
            view = glm::rotate(view,glm::radians(rot.z), glm::vec3(0.0f, 0.0f, 1.0f));

            glm::mat4 projection = glm::perspective(glm::radians(45.0f), screenSize.x/screenSize.y, 0.1f, 100.0f);

            // Set uniform values
            GLint modelLoc = glGetUniformLocation(shader.getID(), "model");
            GLint viewLoc = glGetUniformLocation(shader.getID(), "view");
            GLint projectionLoc = glGetUniformLocation(shader.getID(), "projection");
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
            shader.uniform3f("lightPos",glm::vec3(100,100,-100));
            shader.uniform3f("viewPos",glm::vec3(0,0,-1));
            shader.uniform3f("lightColor",glm::vec3(1,1,1));
            shader.uniform3f("objectColor",Utils::atomColor[atom.name]);

            glBindVertexArray(sphereVAO);
            glDrawElements(GL_TRIANGLE_STRIP, (GLsizei)sphereIndices.size(), GL_UNSIGNED_INT, 0);
        }

            //bond
        // std::cout<<"Number of bonds: "<<starts.size()<<std::endl;
        // for(int i{};i<starts.size();i++)
        // {
        //     cylinderVertices.clear();
        //     cylinderIndices.clear();
        //     Cylinder::generateCylinder(starts[i],ends[i],0.1,10,16,cylinderVertices, cylinderIndices);
        //     std::cout<<"Bond"<<i<<":  Vertices: "<<cylinderVertices.size()<<" Indices: "<<cylinderIndices.size()<<std::endl;

        //     GLuint cylinderVAO, cylinderVBO, cylinderEBO;
        //     glGenVertexArrays(1, &cylinderVAO);
        //     glGenBuffers(1, &cylinderVBO);
        //     glGenBuffers(1, &cylinderEBO);    
        //     glBindVertexArray(cylinderVAO);

        //     glBindBuffer(GL_ARRAY_BUFFER, cylinderVBO);
        //     glBufferData(GL_ARRAY_BUFFER, cylinderVertices.size() * sizeof(float)*3, cylinderVertices.data(), GL_STATIC_DRAW);

        //     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cylinderEBO);
        //     glBufferData(GL_ELEMENT_ARRAY_BUFFER, cylinderIndices.size() * sizeof(unsigned int), cylinderIndices.data(), GL_STATIC_DRAW);

        //     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        //     glEnableVertexAttribArray(0);
        //     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        //     glEnableVertexAttribArray(1);

        //     glBindVertexArray(0);
        //     // Set up transformation matrices
        //     glm::mat4 model = glm::mat4(1.0f);
        //     model = glm::translate(model, glm::vec3(0,0,0)); // Translate the object
        //     model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate the object
        //     model = glm::scale(model, glm::vec3(1)*radius); // Scale the object

        //     glm::mat4 view = glm::translate(glm::mat4(1.0f), pos);
        //     view = glm::rotate(view,glm::radians(rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
        //     view = glm::rotate(view,glm::radians(rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
        //     view = glm::rotate(view,glm::radians(rot.z), glm::vec3(0.0f, 0.0f, 1.0f));

        //     glm::mat4 projection = glm::perspective(glm::radians(45.0f), screenSize.x/screenSize.y, 0.1f, 100.0f);

        //     // Set uniform values
        //     GLint modelLoc = glGetUniformLocation(shader.getID(), "model");
        //     GLint viewLoc = glGetUniformLocation(shader.getID(), "view");
        //     GLint projectionLoc = glGetUniformLocation(shader.getID(), "projection");
        //     glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        //     glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        //     glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        //     shader.uniform3f("lightPos",glm::vec3(100,100,-100));
        //     shader.uniform3f("viewPos",glm::vec3(0,0,-100));
        //     shader.uniform3f("lightColor",glm::vec3(1,1,1));
        //     shader.uniform3f("objectColor",glm::vec3(1,1,1));
        //     glBindVertexArray(cylinderVAO);
        //     glDrawElements(GL_TRIANGLE_STRIP, cylinderIndices.size(), GL_UNSIGNED_INT, 0);


        //     glDeleteVertexArrays(1, &cylinderVAO);
        //     glDeleteBuffers(1, &cylinderVBO);
        //     glDeleteBuffers(1, &cylinderEBO);


        // }


        glDeleteVertexArrays(1, &sphereVAO);
        glDeleteBuffers(1, &sphereVBO);
        glDeleteBuffers(1, &sphereEBO);
    }
}

