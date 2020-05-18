#ifndef BASEBUFFER_H
#define BASEBUFFER_H

class IBaseBuffer
{
protected:
    unsigned int m_RendererID;

public:
    virtual void bind() = 0;
    virtual void unbind() = 0;
};


#endif