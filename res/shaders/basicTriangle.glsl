#shader vertex
#version 330 core 

layout(location = 0) in vec4 position; // setting pointer 0 to a vec 4 position

void main()
{
    gl_Position = position;
};


#shader fragment
#version 430 core 

layout(location = 0) out vec4 color; // outputting a vec4 color

layout(location = 1) uniform vec4 u_Color; // u_ denotes uniform

void main()
{
    color = u_Color;
};