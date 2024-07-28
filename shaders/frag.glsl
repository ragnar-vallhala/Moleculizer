#version 460 core

out vec4 color;
uniform vec2 screenSize;
uniform vec4 pos;
uniform float scale;
uniform float radius;
vec3 lightColor = vec3(1,1,1);
vec3 objectColor = vec3(0,0,1);
vec3 lightPos = vec3(2,2,-1);
void main()
{
	// ambient
	float ambientStrength = 0.5;
    vec3 ambient = ambientStrength * lightColor;

	// Diffuse 
    vec3 norm = normalize(gl_FragCoord.xyz-pos.xyz);
    vec3 lightDir = normalize(lightPos - gl_FragCoord.xyz);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

	// Specular
    float specularStrength = 0.8;
    vec3 viewDir = normalize(vec3(0,0,0) - gl_FragCoord.xyz);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);
    vec3 specular = specularStrength * spec * lightColor;

	vec3 result = (ambient + diffuse + specular) * objectColor;

	vec2 fragPos = (gl_FragCoord.xy / screenSize.yy)*2- 1.0;
	float dist = length(pos.xy*scale - fragPos);
	if(dist<radius)
		color = vec4(result,1);
	else
		discard;
}