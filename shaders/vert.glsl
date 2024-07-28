#version 460 core

layout(location = 0) in vec2 loc;
float radius=0.5;
vec4 color = vec4(0,0,1,1);


void main(){
    gl_Position = vec4(loc.x, loc.y,0.0, 1.0);
}