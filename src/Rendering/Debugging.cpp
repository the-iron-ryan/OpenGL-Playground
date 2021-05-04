#include "Debugging.h"

#include <signal.h>
#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>

#include <GLFW/glfw3.h>

using namespace std;

void GLAPIENTRY
DebugMessageCallback(GLenum source,
                     GLenum type,
                     GLuint id,
                     GLenum severity,
                     GLsizei length,
                     const GLchar* message,
                     const void* userParam )
{
    cout << "DEBUG LOG ";

    switch (severity)
    {
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        cout << "[NOTE]";
        break;
    case GL_DEBUG_SEVERITY_LOW:
        cout << "[LOW]";
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        cout << "[MEDIUM]";
        break;
    case GL_DEBUG_SEVERITY_HIGH:
        cout << "[HIGH]";
        break;
    }

    std::cout << " ";

    switch (type)
    {
    case GL_DEBUG_TYPE_ERROR:
        cout << "<ERROR>";
        break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        cout << "<DEPRECATED_BEHAVIOR>";
        break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        cout << "<UNDEFINED_BEHAVIOR>";
        break;
    case GL_DEBUG_TYPE_PORTABILITY:
        cout << "<PORTABILITY>";
        break;
    case GL_DEBUG_TYPE_PERFORMANCE:
        cout << "<PERFORMANCE>";
        break;
    case GL_DEBUG_TYPE_OTHER:
        cout << "<OTHER>";
        break;
    }

    std::cout << ": " << message << endl;

    


    // Lastly raise break execution on severe errors
    switch (severity)
    {
        case GL_DEBUG_SEVERITY_MEDIUM:
        case GL_DEBUG_SEVERITY_HIGH:
            raise(SIGTRAP);
            break;

        default:
            break;
    }
}