#pragma once
#include <glm/ext.hpp>
#include "Scenegraph.h"

/*The Scene class contains a scenegraph and represents a piece of a level or a whole level. 
In this class all the objects are contained cameras and lights included. */ 
class Scene
{
public:
	Scene();
	///A scene just gets a name
	/*The m_sceneName will be set and a scenegraph object m_sceneGraph will be provided automatically*/
	Scene(std::string sceneName);
	~Scene();

	///A Getter for the name of the Scene
	/*Returns the string msceneName*/
	std::string* getSceneName();

	///A Setter for the name of the Scene
	/*The Method gets a string for m_sceneName*/
	void setSceneName(std::string sceneName);

	///A setter for a scenegraph
	/*The Constructor sets automatically a scenegraph to the scene*/
	void setScenegraph(Scenegraph scenegraph);

	///A getter for the scenegraph
	/*Returns a Scenegraph object m_sceneGraph*/
	Scenegraph* getScenegraph();

private:
	std::string m_sceneName;
	Scenegraph m_sceneGraph;


};