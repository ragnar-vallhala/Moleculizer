#include "shader.h"
#ifdef DEBUG
#include <iostream>
#endif
Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{



    std::string vert{}, frag{};
	readFile(vertexShaderPath, vert);
	readFile(fragmentShaderPath, frag);
	
	const char* vertexShaderCode = vert.c_str();
	const char* fragmentShaderCode = frag.c_str();

	int success;			//get status of processes
	char* infoLog = new char[512];		//get the info in case of error


	//Creating and compiling the vertex shader
	unsigned int vertexID, fragmentID;
	vertexID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexID, 1, &vertexShaderCode, NULL);
	glCompileShader(vertexID);
	glGetShaderiv(vertexID,GL_COMPILE_STATUS,&success);

	//LOGGING in case of compilation failure
	if (!success) {
		glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
        #ifdef DEBUG
		std::cout<<"ERROR:: COMPILATION OF SHADER FAILED "<<(std::string)vertexShaderPath<<std::endl<<infoLog<<std::endl;
        #endif
    
    }

	//Creating and compiling the fragment shader
	fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentID, 1, &fragmentShaderCode, NULL);
	glCompileShader(fragmentID);    
	glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
		#ifdef DEBUG
        std::cout<<("ERROR:: COMPILATION OF SHADER FAILED " + (std::string)fragmentShaderPath)<<std::endl<<infoLog<<std::endl;
        #endif
	}

	//Creating the shader program and attching shaders to it
	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertexID);
	glAttachShader(m_ID, fragmentID);
	glLinkProgram(m_ID);

	glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_ID, 512, NULL, infoLog);
		#ifdef DEBUG
        std::cout<<("ERROR:: LINKING OF PROGRAM FAILED " + (std::string)fragmentShaderPath + " & " + (std::string)vertexShaderPath)<<std::endl<<infoLog<<std::endl;
        #endif
	}
	

	//free the resources
	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
	delete[] infoLog;
}

void Shader::useProgram()
{
    glUseProgram(m_ID);
}

unsigned int Shader::getID() const
{
    return m_ID;
}

void Shader::uniform1f(const char* variable, glm::vec1 val)
{
    glUniform1f(glGetUniformLocation(m_ID, variable), val[0]);
}

void Shader::uniform2f(const char* variable, glm::vec2 val)
{
    glUniform2f(glGetUniformLocation(m_ID, variable), val[0], val[1]);
}
void Shader::uniform3f(const char* variable, glm::vec3 val)
{
    glUniform3f(glGetUniformLocation(m_ID, variable), val[0],val[1],val[2]);
}
void Shader::uniform4f(const char* variable, glm::vec4 val)
{
    glUniform4f(glGetUniformLocation(m_ID, variable), val[0], val[1], val[2], val[3]);
}

void Shader::uniform1i(const char* variable, glm::ivec1 val)
{
    glUniform1i(glGetUniformLocation(m_ID, variable), val[0]);
}

void Shader::uniform2i(const char *variable, glm::ivec2 val)
{
    glUniform2i(glGetUniformLocation(m_ID, variable), val[0], val[1]);
}
void Shader::uniform3i(const char *variable, glm::ivec3 val)
{
    glUniform3i(glGetUniformLocation(m_ID, variable), val[0],val[1],val[2]);
}
void Shader::uniform4i(const char *variable, glm::ivec4 val)
{
    glUniform4i(glGetUniformLocation(m_ID, variable), val[0], val[1], val[2], val[3]);
}


Shader::~Shader()
{
    glDeleteProgram(m_ID);
}


