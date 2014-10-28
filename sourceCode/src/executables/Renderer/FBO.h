#ifndef FBO_H
#define FBO_H

#include "DefinitionAndInclude.h"

/*
* @brief Class for OpenGL frame buffer objects (FBOs).
*
* A FBO has a given width and height. All textures used by it
* or created by it have these values for width and height. It
* is possible to create a fbo with multiple color buffers, each
* with rgba values per pixel. A fbo can use a depth buffer and
* a stencil buffer, which are not necesserily needed.
*
* To create a fbo, the constructor has to be called with the
* preferred width and height. Additionally the number of color
* textures and the use of depth or stencil buffer can be assigned.
* An example creation of a fbo with 1 color buffer and a depth
* buffer is:
* CVK::FBO fbo( 400, 300, 1, true);
*
* To use a fbo, it has to be bound to OpenGL. If the standard
* OpenGL frame buffer should be used, the fbo has to be unbound.
* fbo.bind();
* ...
* fbo.unbind();
*
* To use the result of the fbo, getters for the colorTextures
* and the depth texture exist.
* GLuint colorTexture = fbo.getColorTexture(0);
* GLuint depthTexture = fbo.getDepthTexture();
*/
class FBO
{
public:
	FBO(int width, int height);
	FBO(int width, int height, int numColorTextures, bool depthTexture, bool stencilTexture);
	~FBO();

	void bind();
	void unbind();

	void generateTextures(int width, int height, unsigned int numColorTextures, bool depthTexture, bool stencilTexture);
	void FBO::generateColorTexture(std::vector<GLenum> &drawBuffers, unsigned int index);
	void FBO::generateDepthTexture();
	void FBO::generateStencilTexture();
	GLuint FBO::createTexture();

	void resize(int width, int height);

	void reset();
	void setStatusDepthTexture(bool isActive);
	void setStatusStencilTexture(bool isActive);
	void deleteColorTexture(unsigned int index);

	GLuint getColorTexture(unsigned int index);
	GLuint getDepthTexture();
	GLuint getStencilTexture();

private:
	int m_width, m_height;
	std::vector<GLuint> m_colorTextures;
	GLuint m_depthTexture, m_stencilTexture;
	GLuint m_frameBufferHandle;
};
#endif