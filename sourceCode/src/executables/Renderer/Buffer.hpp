#pragma once

#include <vector>
#include "GL/glew.h"
#include "glm/vec3.hpp"

enum BufferDraw{
  STATIC_DRAW = GL_STATIC_DRAW,
  DYNAMIC_DRAW = GL_DYNAMIC_DRAW
};
template<typename T>
struct Buffer{
  typename T type;
  GLuint handle;
  size_t size;
  Buffer(const std::vector<T> &v, BufferDraw bufferDraw){
    size = v.size();
    glGenBuffers(1, &handle);
    glBindBuffer(GL_ARRAY_BUFFER, handle);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(T), &v.at(0), bufferDraw);
    unbind();
  }

  ~Buffer(){
    glDeleteBuffers(1, &handle);
  }
  void bind() const{
    glBindBuffer(GL_ARRAY_BUFFER,handle);
  }
  void unbind() const{
    glBindBuffer(GL_ARRAY_BUFFER,0);
  }
};