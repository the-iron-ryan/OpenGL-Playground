
#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H
#include <GL/glew.h>

#include "Bindable.h"

class IndexBuffer : public IBindable 
{
public:
    IndexBuffer(const unsigned int* data, unsigned int count, GLenum drawType = GL_STATIC_DRAW);
    ~IndexBuffer();

protected:
    unsigned int m_Count = 0;

public:
    virtual void Bind() const override;
    virtual void Unbind() const override;

    inline unsigned int GetCount() const {return m_Count; }

};

#endif