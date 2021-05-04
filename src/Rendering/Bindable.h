#ifndef BINDABLE_H
#define BINDABLE_H

#include "GLIdentifiable.h"

class IBindable : public IGLIdentifiable
{
public:
    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;
};


#endif