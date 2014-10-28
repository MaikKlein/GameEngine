#version 330 core

uniform vec3 color;

out vec4 fragmentColor;

void main(){
	fragmentColor = vec4(color.x,color.y,color.z,0);
}