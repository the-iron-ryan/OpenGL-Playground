#ifndef VERTEXBUFFERLAYOUT_H
#define VERTEXBUFFERLAYOUT_H

#include <vector>
#include <GL/glew.h>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    GLboolean isNormalized;
};


class VertexBufferLayout
{
protected:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride = 0;

    template<typename T>
    void PushStride(unsigned int count)
    {
        m_Stride += sizeof(T) * count;
    }

public:
    template <typename T>
    inline void Push(unsigned int count)
    {
    }

    inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
    inline unsigned int GetStride() const {return m_Stride;}
};


/* === BEGIN PUSH DEFINES === */
template<>
inline void VertexBufferLayout::Push<char>(unsigned int count)
{
    m_Elements.push_back({GL_BYTE, count, GL_TRUE});
    PushStride<GLbyte>(count);
}

template<>
inline void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    PushStride<GLubyte>(count);
}

template<>
inline void VertexBufferLayout::Push<short>(unsigned int count)
{
    m_Elements.push_back({GL_SHORT, count, GL_FALSE});
    PushStride<GLshort>(count);
}

template<>
inline void VertexBufferLayout::Push<unsigned short>(unsigned int count)
{
    m_Elements.push_back({GL_UNSIGNED_SHORT, count, GL_FALSE});
    PushStride<GLushort>(count);
}

template<>
inline void VertexBufferLayout::Push<int>(unsigned int count)
{
    m_Elements.push_back({GL_INT, count, GL_FALSE});
    PushStride<GLint>(count);
}

template<>
inline void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    PushStride<GLuint>(count);
}

template <>
inline void VertexBufferLayout::Push<float>(unsigned int count)
{
    m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
    PushStride<GLfloat>(count);
}

template <>
inline void VertexBufferLayout::Push<double>(unsigned int count)
{
    m_Elements.push_back({GL_DOUBLE, count, GL_FALSE});
    PushStride<GLdouble>(count);
}

/* === END PUSH DEFINES === */

#endif
