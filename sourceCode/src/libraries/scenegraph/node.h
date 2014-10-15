#include <vector>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "type.h"
template<typename M, typename V>
  struct node{
    M _matrix;
    std::vector<V> vertices;
    node_vec<M,V> children;
    node<M,V>& add(node<M,V> n){
      children.push_back(std::move(n));
      return *this;
    }

    vertex_stream<V> to_vec_stream(const M &m = M(1.0f)) const{
      vertex_stream<V> v;
      auto new_matrix = m * _matrix;
      auto new_vertices = vertices;
      for(auto& vertex : new_vertices){
        vertex = new_matrix * vertex ;
      }
      v.push_back(new_vertices);
      for(const auto &n : children){
        auto r = n.to_vec_stream(new_matrix);
        v.insert(v.end(),r.begin(),r.end());
      }
      return v;
    }
    vertex_stream<float> to_vertex_stream(){
      auto v = to_vec_stream();
      vertex_stream<float> stream;
      for(const auto& e1 : v){
        for(const auto& e : e1){
          std::vector<float> t(glm::value_ptr(e), glm::value_ptr(e) + (sizeof(V) /sizeof(float)));
          stream.push_back(t);
        }
      }
      return stream;
    }
  };

template<typename M,typename V>
  node<M,V> make_node(const M &m, const std::vector<V> &v){
  static_assert((is_vec2<V>::value && is_mat2<M>::value) ||
                (is_vec3<V>::value && is_mat3<M>::value) ||
                (is_vec4<V>::value && is_mat4<M>::value),"Dimensions don't match.");
  node<M,V> n{m,v,node_vec<M,V>{}};
  return n;
}
