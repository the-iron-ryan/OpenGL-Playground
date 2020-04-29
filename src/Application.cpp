#include <iostream>

#include <GL/glew.h>
#include <GL/glut.h>

#include <GLFW/glfw3.h>

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

    unsigned int trianleBuffer_id;
    float trianglePos[3][2] = 
    {
        {-0.5f, -0.5f},
        {0.0f, 0.5f},
        {0.5f, -0.5f},
    };

    // Gen buffer with specified id
    glGenBuffers(1, &trianleBuffer_id);
    // Binding this buffer as being used
    glBindBuffer(GL_ARRAY_BUFFER, trianleBuffer_id);
    // Put data inside of buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(trianglePos), &trianglePos, GL_STATIC_DRAW);

    /* DEFINING ATTRIBUTES */
    
    // Index 0: position with 2 coordinates, with a pointer starting from an offset of 0
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void *) 0);

    /* ENABLING ATTRIBUTES */
    glEnableVertexAttribArray(0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw call!
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}