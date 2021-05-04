#ifndef SHADER_H
#define SHADER_H

#include <string>

#include "Bindable.h"

class Shader : public IBindable
{
public:
    Shader(std::string filename);
    ~Shader();

private:

public:

    template<typename TUniform>
    void SetUniform(std::string name, TUniform value)
    {

    }
};


#endif