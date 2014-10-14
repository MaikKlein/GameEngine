#include <string.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>

#include "Renderer.h"

//Should only be the Front-End for the user
int main(){

	//TODO: Maybe we could have more classes of objects (triangle, rectangle etc.)
	//TODO: A better object oriented way would be nice
	Object* object = new Object();

	//We initialize the renderer
	//The only question we ask us are: What do we want to be rendered (Object) and which way we want it to be rendered (Shader)
	Renderer* renderer = new Renderer("00_Renderer\\minimal.vert", "00_Renderer\\minimal.frag", object);

	//we start the renderer
	renderer->start();
	
	return 0;
}