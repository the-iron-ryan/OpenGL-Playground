#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

#include <GL/glew.h>
#include <GL/glut.h>

#include <GLFW/glfw3.h>

#define MYGL_CLEAR_ERROR while(glGetError() != GL_NO_ERROR);
#define MYGL_REPORT_ERRORS GLReportErrors();


static void GLReportErrors()
{
    while(GLenum err = glGetError())
    {
        std::cout << "[Open GL Error]: " << err << std::endl;
    }
}

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
    std::cout << "Reading filepath: " << filepath << std::endl;
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

    GLenum err = glewInit();
    if(err != GLEW_OK)
    {
        std::cout << "GLEW error: " << glewGetErrorString(err) << std::endl;
        return -1;
    }

    // 
    std::cout << glGetString(GL_VERSION) << std::endl;

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


    // Gen buffer with specified id
    unsigned int trianleBuffer_id;
    glGenBuffers(1, &trianleBuffer_id);
    // Binding this buffer as being used
    glBindBuffer(GL_ARRAY_BUFFER, trianleBuffer_id);
    // Put data inside of buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(trianglePos), &trianglePos, GL_STATIC_DRAW);

    /* ENABLING ATTRIBUTES */
    glEnableVertexAttribArray(0);

    /* DEFINING ATTRIBUTES */
    // Index 0: position with 2 coordinates, with a pointer starting from an offset of 0
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void *) 0);

    /* DEFINING INDEX BUFFER */
    uint triangleIbo_id; // 
    glGenBuffers(1, &triangleIbo_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangleIbo_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangleIndices), &triangleIndices, GL_STATIC_DRAW);

    // Parse files for shader source
    ShaderProgramData ProgData;
    ParseShaderFile("/home/the-iron-ryan/Software-Projects/OpenGL-Playground/res/shaders/basicTriangle.glsl", ProgData);

    // Creating a program with our compiled shaders
    uint shaderProg = CreateShader(ProgData.VertexSource, ProgData.FragmentSource);
    glUseProgram(shaderProg);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        MYGL_CLEAR_ERROR
        // Draw call!
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        MYGL_REPORT_ERRORS
        

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shaderProg);

    glfwTerminate();
    return 0;
}