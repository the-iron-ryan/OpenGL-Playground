#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "Bindable.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray : public IBindable
{
public:
    VertexArray();
    ~VertexArray();
protected:

public:
    void Bind() const override;
    void Unbind() const override;

    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
};

#endif