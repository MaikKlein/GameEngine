#version 330 core

in vec4 positionAttribute;

void main(){
    gl_Position = positionAttribute;
}