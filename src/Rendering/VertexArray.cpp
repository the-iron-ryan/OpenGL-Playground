#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::Bind() const
{
    glBindVertexArray(m_RendererID);
} 

void VertexArray::Unbind() const 
{
    glBindVertexArray(0);
}

void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout)
{
    // Make sure we're bound first
    Bind();

    // Bind VB object and setup a vertex array based on the given layout
    vb.Bind();
    const auto& elements = layout.GetElements();
    unsigned int offset = 0;

    for(int i = 0; i < elements.size(); i++)
    {
        const auto& elem = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, elem.count, elem.type, 
            elem.isNormalized, layout.GetStride(), (const void*) offset);
        
        offset += elem.count * sizeof(elem.type);
    } 
 
}