#shader vertex
#version 330 core 

layout(location = 0) in vec4 position; // setting pointer 0 to a vec 4 position

void main()
{
    gl_Position = position;
};


#shader fragment
#version 330 core 

layout(location = 0) out vec4 color; // outputting a vec4 color

void main()
{
    color = vec4(1.0, 1.0, 0.0, 1.0);
};