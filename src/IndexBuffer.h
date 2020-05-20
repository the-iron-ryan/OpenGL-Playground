
#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H
#include <GL/glew.h>

#include "BaseBuffer.h"

class IndexBuffer : public IBaseBuffer
{
protected:
    IndexBuffer(const unsigned int* data, unsigned int size, GLenum drawType = GL_STATIC_DRAW);
    ~IndexBuffer();

public:
    virtual void bind() override;
    virtual void unbind() override;
};

#endif