#include <type_traits>
#include <vector>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

template<typename T>
using is_vec2 = std::is_same<T,glm::vec2>;

template<typename T>
using is_vec3 = std::is_same<T,glm::vec3>;

template<typename T>
using is_vec4 = std::is_same<T,glm::vec4>;

template<typename M>
using is_mat2 = std::is_same<M,glm::mat2>;

template<typename M>
using is_mat3 = std::is_same<M,glm::mat3>;

template<typename M>
using is_mat4 = std::is_same<M,glm::mat4>;

template<typename M,typename V>
struct node;

template<typename M, typename V>
using node_vec = std::vector<node<M,V>>;

template<typename T>
using vertex_stream = std::vector<std::vector<T>>;
