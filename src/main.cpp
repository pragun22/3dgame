#include "main.h"
#include "timer.h"
#include "ball.h"
#include "plane.h"
#include "terrain.h"
using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/
double xpos, ypos;
bool flag = false;
Ball ball1;
Terrain terrain;
Plane plane;
float temp = 0.0f;
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);
    // Eye - Location of camera. Don't change unless you are sure!!
    // else temp = 0;
    //follow cam
    float angle1 = cos((plane.counter * M_PI / 180.0f));
    float angle2 = sin((plane.counter * M_PI / 180.0f));
    float camx = plane.position.x + (50)*angle2;
    float camz = plane.position.z + (50)*angle1;
    cout<<angle1<<"-angle-"<<angle2<<endl;
    cout<<camx<<"-cam-"<<camz<<endl;
    glm::vec3 eye ( camx ,  plane.position.y + 20 , camz);
    // glm::vec3 eye ( (plane.position.x),  plane.position.y + 20 , (plane.position.z + 50) );
    // glm::vec3 eye ( 0,  35 ,13 );
    // Target - Where is the camera looking at.  Don't change unless you are sure!!

    glm::vec3 target (plane.position.x, plane.position.y +0, plane.position.z);
    // glm::vec3 target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);
    //ends here
    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt(eye,target,up);
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    // ball1.draw(VP);  
    plane.draw(VP);
    terrain.draw(VP);
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int space = glfwGetKey(window, GLFW_KEY_SPACE);
    int w = glfwGetKey(window, GLFW_KEY_W);
    int A = glfwGetKey(window, GLFW_KEY_A);
    int D = glfwGetKey(window, GLFW_KEY_D);
    int Q = glfwGetKey(window, GLFW_KEY_E);
    int E = glfwGetKey(window, GLFW_KEY_Q);
    if(space == GLFW_PRESS) plane.Up(1);
    else if (space == GLFW_RELEASE) plane.Up(0);
    if(w == GLFW_PRESS) plane.forward(1);
    else if (w == GLFW_RELEASE) plane.forward(0);
    if(D == GLFW_PRESS) plane.tilt_fn(1,-3.0f);
    else if (D == GLFW_RELEASE) plane.tilt_fn(0,-3.0f);
    if(A == GLFW_PRESS) plane.tilt_fn(1,3.0f);
    else if (A == GLFW_RELEASE) plane.tilt_fn(0,3.0f);
    if(Q == GLFW_PRESS){ 
        plane.rotate(1,-2.0f);
    }
    else if (Q == GLFW_RELEASE){ 
        plane.rotate(0,-2.0f);
    }
    if(E == GLFW_PRESS){ 
        plane.rotate(1,2.0f);
    }
    else if (E == GLFW_RELEASE){ 
        plane.rotate(0,2.0f);
    }
    if (left) {
        if(!flag) flag = true;
        else flag = false;
     temp += 0.1f;
    }
}

void tick_elements() {
    ball1.tick();
    plane.tick();
    terrain.tick();
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    plane = Plane(0.0f,0.0f,COLOR_BLACK);
    terrain = Terrain(-400.0f,-200.0f,400,800);
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
            reset_screen();

            glfwGetCursorPos(window, &xpos, &ypos);
            // cout<<xpos<<"--"<<ypos<<endl;

        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::perspective(45.0f,1.0f,0.2f,10000.0f);
    // Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
