#include<vector>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
class Rect
{
public:
	Rect();
	~Rect();

	void createBuffer();
	void render(GLFWwindow* window);

private:
	std::vector<glm::vec3> m_vertices;
	
};