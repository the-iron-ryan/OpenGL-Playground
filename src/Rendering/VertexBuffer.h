#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <GL/glew.h>

#include "Bindable.h"

class VertexBuffer : public IBindable 
{
public:
    VertexBuffer(const void* data, unsigned int size, GLenum drawType = GL_STATIC_DRAW);
    ~VertexBuffer();

public:
    virtual void Bind() const override;
    virtual void Unbind() const override;
};

#endif