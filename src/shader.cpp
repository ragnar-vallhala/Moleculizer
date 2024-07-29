#include "shader.h"
#ifdef DEBUG
#include <iostream>
#endif
Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{

	const char* fragmentShaderSource = R"(
				#version 460 core
				out vec4 FragColor;

				in vec3 FragPos;
				in vec3 Normal;

				in vec3 modLightPos;
				uniform vec3 modViewPos;
				uniform vec3 lightColor;
				uniform vec3 objectColor;

				void main()
				{
					// Ambient
					float ambientStrength = 0.6;
					vec3 ambient = ambientStrength * lightColor;

					// Diffuse 
					float diffuseStrength = 0.6;
					vec3 norm = normalize(Normal);
					vec3 lightDir = normalize(modLightPos - FragPos);
					float diff = max(dot(norm, lightDir), 0.0);
					vec3 diffuse = diff * lightColor * diffuseStrength;

					// Specular
					float specularStrength = 0.3;
					vec3 viewDir = normalize(modViewPos - FragPos);
					vec3 reflectDir = reflect(-lightDir, norm);
					float spec = pow(max(dot(-viewDir, reflectDir), 0.0), 128);
					vec3 specular = specularStrength * spec * lightColor;

					vec3 result = (ambient + diffuse + specular) * objectColor;
					FragColor = vec4(result, 1.0);
				}
				)";

	const char* vertexShaderSource = R"(
				#version 460 core
				layout(location = 0) in vec3 aPos;
				layout(location = 1) in vec3 aNormal;

				out vec3 FragPos;
				out vec3 Normal;
				out vec3 modLightPos;
				out vec3 modViewPos;

				uniform vec3 lightPos;
				uniform vec3 viewPos;
				uniform mat4 model;
				uniform mat4 view;
				uniform mat4 projection;

				void main()
				{
					FragPos = vec3(model * vec4(aPos, 1.0));
					Normal = mat3(transpose(inverse(model))) * aNormal;
					
					modLightPos = (projection * view * vec4(lightPos, 1.0)).xyz;
					modViewPos = (projection * view * vec4(viewPos, 1.0)).xyz;
					gl_Position = projection * view * vec4(FragPos, 1.0);
				}
				)";




    std::string vert{}, frag{};
#ifndef DEBUG
	vert = vertexShaderSource;
	frag = fragmentShaderSource;
#endif

#ifdef DEBUG
	readFile(vertexShaderPath, vert);
	readFile(fragmentShaderPath, frag);
#endif	
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


