#ifndef SHADER_H
#define SHADER_H
#ifdef DEBUG
#include <iostream>
#endif
#include<string>
#include"file.h"
#include "glad/glad.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	
	Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
	void useProgram();
    unsigned int getID() const;
	
	void uniform1f(const char* variable, glm::vec1 val);
	void uniform2f(const char* variable, glm::vec2 val);
	void uniform3f(const char* variable, glm::vec3 val);
	void uniform4f(const char* variable, glm::vec4 val);
	void uniform1i(const char* variable, glm::ivec1 val);
	void uniform2i(const char* variable, glm::ivec2 val);
	void uniform3i(const char* variable, glm::ivec3 val);
	void uniform4i(const char* variable, glm::ivec4 val);
	~Shader();
private:
    unsigned int m_ID = 0;
};

#endif