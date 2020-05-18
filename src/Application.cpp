#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <signal.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

#include <GL/glew.h>
#include <GL/glut.h>

#include <GLFW/glfw3.h>

#include "Debugging.h"


using namespace std;

struct ShaderProgramData
{
    std::string VertexSource;
    std::string FragmentSource;
};

enum class EShaderType
{
    VERTEX = 0,
    FRAGMENT = 1,
    NONE = -1
};


static void ParseShaderFile(const std::string& filepath, ShaderProgramData& out_shaderProgData)
{
    std::ifstream shaderFileStream(filepath);
    if(!shaderFileStream)
    {
        std::cerr << "Error opening file. Error code: " << strerror(errno);
    }


    std::string line;
    EShaderType CurShaderType = EShaderType::NONE;
    std::stringstream shaderStreams[2];

    while(getline(shaderFileStream, line))
    {
        if(line.find("#shader") != std::string::npos)
        {
            if(line.find("vertex") != std::string::npos)
                CurShaderType = EShaderType::VERTEX;
            else if(line.find("fragment") != std::string::npos)
                CurShaderType = EShaderType::FRAGMENT;
        }
        else
        {
            switch (CurShaderType)
            {
            case EShaderType::VERTEX:
            case EShaderType::FRAGMENT:
                shaderStreams[(int) CurShaderType] << line << "\n";
                break;
            case EShaderType::NONE:
            default:
                break;
            }
        }
    }

    // Set final shader output streams
    out_shaderProgData.VertexSource = shaderStreams[(int) EShaderType::VERTEX].str();
    out_shaderProgData.FragmentSource = shaderStreams[(int) EShaderType::FRAGMENT].str();
}

static uint CompileShader(GLenum shaderType, const std::string& source)
{
    uint shaderId = glCreateShader(shaderType);
    const char* src = &source[0]; // get ptr to first char in the array

    glShaderSource(shaderId, 1, &src, nullptr);
    glCompileShader(shaderId);

    // Handle compile error
    int result;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
    if(!result)
    {
        int len;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &len);

        char* message = (char*)alloca(len * sizeof(char));
        glGetShaderInfoLog(shaderId, len, &len, message);

        // Get shader error name
        std::string shaderName = "vertex";
        switch (shaderType)
        {
        case GL_FRAGMENT_SHADER:
            shaderName = "fragment";
            break;

        case GL_VERTEX_SHADER:
        default:
            shaderName = "vertex";
            break;
        }

        std::cout << "Falied to compile shader " << shaderName << ": " << std::endl <<  message << std::endl;
    }

    return shaderId;
}

static uint CreateShader(std::string vertexShaderSource, std::string fragmentShaderSource)
{
    uint program = glCreateProgram();
    uint vertexShaderID = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
    uint fragmentShaderID = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    glAttachShader(program, vertexShaderID);
    glAttachShader(program, fragmentShaderID);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    return program;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    GLenum err = glewInit();
    if(err != GLEW_OK)
    {
        std::cout << "GLEW error: " << glewGetErrorString(err) << std::endl;
        return -1;
    }

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(DebugMessageCallback, 0);

    float trianglePos[4][2] = 
    {
        {-0.5f, -0.5f},
        { 0.5f, -0.5f},
        { 0.5f,  0.5f},
        {-0.5f,  0.5f},
    };

    uint triangleIndices[] = 
    {
        0, 1, 2, // Tri 0
        2, 3, 0  // Tri 1
    };


    /* SETUP VERTEX ARRAY OBJECT */
    uint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Gen buffer with specified id
    unsigned int trianleBuffer_id;
    glGenBuffers(1, &trianleBuffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, trianleBuffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(trianglePos), &trianglePos, GL_STATIC_DRAW);

    /* ATTRIBUTES */
    // NOTE: index 0 of vertex array is now currently bound to current GL_ARRAY_BUFFER
    //       ie, this binds vao to current array buffer
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void *) 0); // Index 0: position with 2 coordinates, with a pointer starting from an offset of 0


    /* DEFINING INDEX BUFFER */
    uint triangleIbo_id; // 
    glGenBuffers(1, &triangleIbo_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangleIbo_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangleIndices), &triangleIndices, GL_STATIC_DRAW);

    // Parse files for shader source
    char curDirectory[FILENAME_MAX];
    GetCurrentDir(curDirectory, sizeof(curDirectory));
    string triangleShaderFile = string(curDirectory) + "/res/shaders/basicTriangle.glsl";
    ShaderProgramData ProgData;
    ParseShaderFile(triangleShaderFile, ProgData);

    // Creating a program with our compiled shaders
    uint shaderProg = CreateShader(ProgData.VertexSource, ProgData.FragmentSource);
    float r = 0.f, g = 0.f, b = 0.f;
    float step;
    float inc = step = 0.001f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProg);
        glUniform4f(1, r, g, b, 1.0f);

        glBindVertexArray(vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangleIbo_id);

        // Draw call!
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        if(r >= 1.f)
            inc = -step;
        else if(r <= 0.f)
            inc = step;
            
        r += inc;

    }

    glDeleteProgram(shaderProg);

    glfwTerminate();
    return 0;
}