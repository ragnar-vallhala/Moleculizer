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
