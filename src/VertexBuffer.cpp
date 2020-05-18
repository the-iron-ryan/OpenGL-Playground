#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size, GLenum drawType)
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, drawType);
}
VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}
void VertexBuffer::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}
void VertexBuffer::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);}