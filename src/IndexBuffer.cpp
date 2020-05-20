#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int size, GLenum drawType)
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, drawType);
}
IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}
void IndexBuffer::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}
void IndexBuffer::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}