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
    vec3 diffuse = diff * lightColor*diffuseStrength;

    // Specular
    float specularStrength = 0.3;
    vec3 viewDir = normalize(modViewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(-viewDir, reflectDir), 0.0), 128);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
}
