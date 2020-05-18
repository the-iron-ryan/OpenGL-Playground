#ifndef DEBUGGING_H
#define DEBUGGING_H 

#include <GL/glew.h>


void GLAPIENTRY DebugMessageCallback(GLenum source,
                                     GLenum type,
                                     GLuint id,
                                     GLenum severity,
                                     GLsizei length,
                                     const GLchar *message,
                                    const void *userParam);
#endif