#version 330

layout (location = 0) in vec4 position;	
layout (location = 1) in vec3 normal;			


uniform mat4 modelMatrix;						
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec3 passNormal;

void main() {

    gl_Position = projectionMatrix * viewMatrix * modelMatrix * position;	

    passNormal = normal;
}
 
