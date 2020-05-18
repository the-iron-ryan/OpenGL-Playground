#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <GL/glew.h>

#include "BaseBuffer.h"

class VertexBuffer : public IBaseBuffer
{
public:
    VertexBuffer(const void* data, unsigned int size, GLenum drawType = GL_STATIC_DRAW);
    ~VertexBuffer();

    virtual void bind() override;
    virtual void unbind() override;
};

#endif