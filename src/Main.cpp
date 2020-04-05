#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Engine/Camera.h"
#include "Engine/Initialization.h"
#include "Engine/CreateObject.h"
#include "Engine/LightObject.h"


// settings

Camera camera;




// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

int main()
{
    camera.SCR_HEIGHT = SCR_HEIGHT;
    camera.SCR_WIDTH = SCR_WIDTH;
    InitWindow init_ref;
    // build and compile our shader zprogram
    // ------------------------------------
    
    Shader ourShader("assets/4.1.texture.vs", "assets/4.1.texture.fs");
    Shader LightShader("assets/basic_lighting.vs", "assets/basic_lighting.fs");
    Shader LampShader("assets/lamp.vs", "assets/lamp.fs");
    

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    
    Object object_ref;
    
    point_light light_ref;
    light_ref.WorldPos = glm::vec3(1.0f,2.0f, 2.5f);

    // load and create a texture 
    // -------------------------
    object_ref.create_textures(ourShader);


    


    // render loop
    // -----------
    while (!glfwWindowShouldClose(init_ref.window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(init_ref.window, deltaTime);

        // render
        // ------
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

        // bind textures on corresponding texture units
        

       light_ref.render_light(LampShader);
       camera.Camera_render(LampShader); 
       object_ref.Render_Object(LightShader);
       camera.Camera_render(LightShader);
       
       

       

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(init_ref.window);
        glfwPollEvents();
    }


    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window, float deltaTime)
{
    camera.processInput(window, deltaTime);
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
    camera.Process_Mouse_Scroll(yoffset);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    camera.Process_Mouse_Movement(xpos, ypos);
}
