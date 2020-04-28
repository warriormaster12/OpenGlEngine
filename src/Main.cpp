#include "../Include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Engine/Camera.h"
#include "Engine/Movement.h"
#include "Engine/CreateObject.h"
#include "Models/model.h"

#include "Engine/ECS.h"



// settings

Manager manager;
auto& Player(manager.addEntity());


GLFWwindow* window;
const unsigned int SCR_WIDTH{1920};
const unsigned int SCR_HEIGHT{1080};
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    
    

    // glfw window creation
    // --------------------
     window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGLEngine", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    else
    {
        std::cout << "GLFW window init success" << std::endl;
    }
    
    glfwMakeContextCurrent(window);

    // load opengl functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    //enable or disable vsync
    glfwSwapInterval(0);


    // configure global opengl state
    // -----------------------------
    
    // build and compile our shader zprogram
    // ------------------------------------
    
    Object object_ref;
    Model ourModel(object_ref.model_directory);

    Player.addComponent<Camera>();
    Player.addComponent<Movement>();

    Player.getComponent<Camera>().SCR_WIDTH = SCR_WIDTH;
    Player.getComponent<Camera>().SCR_HEIGHT = SCR_HEIGHT;
    Player.getComponent<Movement>().window = window;
    
    glEnable(GL_DEPTH_TEST);


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // render
        // ------
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
        
        //Render model
       Player.getComponent<Camera>().Camera_render(object_ref.model_shader);
       object_ref.Render_Object();
       ourModel.Draw(object_ref.model_shader);
       
       manager.update(deltaTime);

       Player.getComponent<Camera>().cameraPos = Player.getComponent<Movement>().Pos;
       Player.getComponent<Camera>().cameraFront = Player.getComponent<Movement>().Front;
       Player.getComponent<Camera>().cameraUp = Player.getComponent<Movement>().Up;
    
       
       

       

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    Player.getComponent<Camera>().Process_Mouse_Scroll(yoffset);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    Player.getComponent<Movement>().Process_Mouse_Movement(xpos, ypos);
}
