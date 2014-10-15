#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "utility.h"
#include "type.h"
#include "node.h"

int main(){
  // Some test vertices
  std::vector<glm::vec4> v0{glm::vec4(1.0f,2.0f,3.0f,1.0f)};
  std::vector<glm::vec4> v1{glm::vec4(4.0f,5.0f,6.0f,1.0f)};
  std::vector<glm::vec4> v2{glm::vec4(7.0f,8.0f,9.0f,1.0f)};

  auto root = make_node(glm::scale(glm::mat4(1.0f),glm::vec3(2.0f)),v0);
  root.add(make_node(glm::mat4(1.0f),v0))
      .add(make_node(glm::mat4(1.0f),v1))
      .add(make_node(glm::mat4(1.0f),v2));

  auto stream = root.to_vertex_stream();
  print_vertex_stream(stream);

 /*
 // How the renderer integration could look like
 for(auto obj : stream){
   renderer.loadObject(&obj[0],obj.size());
 }
 */
}
