#ifndef RENDERER_H
#define RENDERER_H

#include "Defs.h"
#include "Buffer.hpp"
#include "Shader.h"

/*
Need Information
*/

struct RenderObject{

};
struct RenderContext{
  virtual void bindContext() const = 0;
};
struct OpenGL3Context : RenderContext {
  virtual void bindContext() const override;
};
class Renderer{
public:
  Renderer(const RenderContext &context);

  template<typename T>
  void draw(const Buffer<T> &buffer, const ShaderProgram &program) {
    buffer.bind();
    program.bind();
    //FIXME - Needs generic interface
    glEnableVertexAttribArray(0);
    // MAGIC NUMBER - needs proper information for vertex size
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, buffer.size);
    glDisableVertexAttribArray(0);
    buffer.unbind();
    program.unbind();
  }
  void printInfo();
};
#endif 