#include "main.h"
#include "timer.h"
#include "ball.h"
#include "plane.h"
#include "terrain.h"
#include "display.h"
#include "score.h"
#include "enemies.h"
#include "checkpoints.h"
using namespace std;

GLMatrices Matrices;
GLMatrices Matrices1;
GLuint     programID;
GLFWwindow *window;
Display display;
Compass compass;
Target tar;
Altitude alt;
clock_t para_timer = clock();
clock_t ring_timer = clock();
/**************************
* Customizable functions *
**************************/
double xpos, ypos;
bool flag = false;
Ball ball1;
Terrain terrain;
Plane plane;
Tapu tapu;
vector<Checks> checks;
vector<Arrow> arrow;
vector<Ring> ring;
vector<Parachute> para;
vector<Lava> lava;
vector<Canon> canon;
vector<Zero> zero;
vector<One> one;
vector<Two> two;
vector<Three> three;
vector<Four> four;
vector<Five> five;
vector<Six> six;
vector<Seven> seven;
vector<Eight> eight;
vector<Nine> nine;
vector<Gola> gola;
float temp = 0.0f;
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
int cam_mode = 0;
float camera_rotation_angle = 0;
float min(int a,int b)
{
    return a>b?b:a;
}
float max(int a,int b)
{
    return a>b?a:b;
}

void score_tick(float x, int score){
    float pos = screen_center_x + 4 -0.3f;
    float top    = screen_center_y + 4  - 0.3f;
    if(score == 0 ){ if(zero.size()>0) zero.pop_back(); zero.push_back(Zero(pos, top));}
    while(score>0){
        int temp = score % 10;
        if(temp==0){ zero.push_back(Zero(pos, top));}
        if(temp==1){ one.push_back(One(pos, top));}
        if(temp==2){ two.push_back(Two(pos, top));}
        if(temp==3){ three.push_back(Three(pos, top));}
        if(temp==4){ four.push_back(Four(pos, top));}
        if(temp==5){ five.push_back(Five(pos, top));}
        if(temp==6){ six.push_back(Six(pos, top));}
        if(temp==7){ seven.push_back(Seven(pos, top));}
        if(temp==8){ eight.push_back(Eight(pos, top));}
        if(temp==9){ nine.push_back(Nine(pos, top));}
        pos -= 0.3f;
        score = score / 10;
    }
}
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
    // cout<<angle1<<"-angle-"<<angle2<<endl;
    // cout<<camx<<"-cam-"<<camz<<endl;
    glm::vec3 eye[6]; 
    glm::vec3 target[6];
    glm::vec3 up;
    float ang = plane.counter * M_PI / 180.0f;
    glm::mat4 rotate    = rotationMatrix(glm::vec3(-1*cos(ang),0,sin(ang)),(plane.rotation * M_PI / 180.0f));
    glm::mat4 til = rotationMatrix(glm::vec3(sin(ang),0,cos(ang)),(plane.tilt * M_PI / 180.0f));
    glm::mat4 count    = glm::rotate((float) (plane.counter * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 fin = til* rotate * count;
    // fin = normalize(fin);
    up = glm::vec3(fin[1][0], fin[1][1], fin[1][2]);
    up = glm::normalize(up);
    // follow cam
    eye[0] = glm::vec3( camx ,  plane.position.y + 20 , camz);
    target[0] = glm::vec3(plane.position.x, plane.position.y +0, plane.position.z);
   // Top view
    eye[1] = glm::vec3( plane.position.x , 200.0f  , plane.position.z + 50.0f);
    target[1] = glm::vec3(plane.position.x, plane.position.y +0, plane.position.z);
    //tower view
    eye[2] = glm::vec3( camx -200.0f,  plane.position.y+30.0f , plane.position.z + 50.0f);
    target[2] = glm::vec3(plane.position.x, plane.position.y +0, plane.position.z);
    // plane's view
    eye[3] = glm::vec3( plane.position.x, plane.position.y +0, plane.position.z);
    target[3] = glm::vec3(plane.position.x, plane.position.y +0, plane.position.z-30.0f);
    // helicopter view
    glfwGetCursorPos(window, &xpos, &ypos);
    xpos = max(xpos,0);
    ypos = max(ypos,0);
    xpos = min(xpos,600);
    ypos = min(ypos,600);
    // cout<<xpos<<"--"<<yposs<<endl;
    float helicamx = camx  + (float(xpos-300.0f)/5.0f)*angle1/screen_zoom  ;
    float helicamz = camz  - (float(xpos-300.0f)/5.0f)*angle2 - 10/screen_zoom ;
    float helicamy = plane.position.y + float(ypos-300.0f)/5.0f;
    eye[4] = glm::vec3( helicamx , helicamy , helicamz);
    target[4] = glm::vec3(plane.position.x, plane.position.y +0, plane.position.z);
    //ends here
    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt(eye[cam_mode],target[cam_mode],up);
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane
    glm::vec3 dis_eye ( 0, 0, 10);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 dis_target (0, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 dis_up (0, 1, 0);
    Matrices1.view = glm::lookAt( dis_eye, dis_target, dis_up ); // Rotating Camera for 3D
    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;
    glm::mat4 VP1 = Matrices1.projection * Matrices1.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    // ball1.draw(VP); 
    plane.draw(VP);
    terrain.draw(VP);
    tapu.draw(VP);
    for(int i = 0; i < canon.size(); i++){
        canon[i].draw(VP);
    }
    for(int i = 0; i < gola.size(); i++){
        gola[i].draw(VP);
    }
    for(int  i = 0; i < para.size(); i++){
        para[i].draw(VP);
    }
    for(int  i = 0; i < ring.size(); i++){
        ring[i].draw(VP);
    }
    for(int  i = 0; i < arrow.size(); i++){
        float check_x = checks[0].position.x - plane.position.x;
        float check_y = checks[0].position.y - plane.position.y;
        float check_z = checks[0].position.z - plane.position.z;
        glm::vec3 check_dir = glm::vec3(check_x, check_y, check_z);
        arrow[i].draw(VP,check_dir);
    }
    for(int  i = 0; i < checks.size(); i++){
        checks[i].draw(VP);
    }
    tar.draw(VP);
    display.draw(VP1);
    alt.draw(VP1);
    compass.draw(VP1);
    for(int i = 0; i < zero.size();i++) zero[i].draw(VP1);
    for(int i = 0; i < one.size();i++) one[i].draw(VP1);
    for(int i = 0; i < two.size();i++) two[i].draw(VP1);
    for(int i = 0; i < three.size();i++) three[i].draw(VP1);
    for(int i = 0; i < four.size();i++) four[i].draw(VP1);
    for(int i = 0; i < five.size();i++) five[i].draw(VP1);
    for(int i = 0; i < six.size();i++) six[i].draw(VP1);
    for(int i = 0; i < seven.size();i++) seven[i].draw(VP1);
    for(int i = 0; i < eight.size();i++) eight[i].draw(VP1);
    for(int i = 0; i < nine.size();i++) nine[i].draw(VP1);
    if(zero.size()>0) zero.clear(); 
    if(one.size()>0) one.clear(); 
    if(two.size()>0)two.clear();
    if(three.size()>0)three.clear();
    if(four.size()>0)four.clear();
    if(five.size()>0)five.clear();
    if(six.size()>0)six.clear();
    if(seven.size()>0)seven.clear();
    if(eight.size()>0)eight.clear();
    if(nine.size()>0)nine.clear();
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
    int mod0 = glfwGetKey(window, GLFW_KEY_0);
    int mod1 = glfwGetKey(window, GLFW_KEY_1);
    int mod2 = glfwGetKey(window, GLFW_KEY_2);
    int mod3 = glfwGetKey(window, GLFW_KEY_3);
    int mod4 = glfwGetKey(window, GLFW_KEY_4);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int b = glfwGetKey(window, GLFW_KEY_B);
    int down  = glfwGetKey(window, GLFW_KEY_V);
    if(b)  plane.drop();
    if(up){
    float angle2 = sin((plane.counter * M_PI / 180.0f));
        float b = tar.position.y - plane.position.y;
        float a = tar.position.x - plane.position.x;
        float c = tar.position.z - plane.position.z;// + 50*(xpos-300.0f)/600.0f*angle2;
        glm::vec3 dir = glm::vec3(a,b,c);
        dir = glm::normalize(dir);
        plane.shoot(dir);
    } 
    if(mod0) cam_mode = 0;
    if(mod1) cam_mode = 1;
    if(mod2) cam_mode = 2;
    if(mod3) cam_mode = 3;
    if(mod4) cam_mode = 4;
    if(down == GLFW_PRESS) plane.Down(1);
    else if (down == GLFW_RELEASE) plane.Down(0);
    if(space == GLFW_PRESS) plane.Up(1);
    else if (space == GLFW_RELEASE) plane.Up(0);
    if(w == GLFW_PRESS) plane.forward(1);
    else if (w == GLFW_RELEASE) plane.forward(0);
    if(A == GLFW_PRESS) plane.tilt_fn(1,-1.5f);
    else if (A == GLFW_RELEASE) plane.tilt_fn(0,-2.0f);
    if(D == GLFW_PRESS) plane.tilt_fn(1,1.5f);
    else if (D == GLFW_RELEASE) plane.tilt_fn(0,2.0f);
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
    float angle1 = cos((plane.counter * M_PI / 180.0f));
    float angle2 = sin((plane.counter * M_PI / 180.0f));
    bounding_box_t air;
    air.x = plane.position.x-1.7f;
    air.y = plane.position.y-1.7f;
    air.z = plane.position.z+7.5f;
    air.depth = -15.0f;
    air.width = 3.4f;
    air.height = 3.4f;
    ball1.tick();
    plane.tick(para);
    tapu.tick(air);
    display.tick(plane.acc);
    score_tick(4.0f, 170218);
    for(int i = 0; i < ring.size(); i++){
        if(ring[i].tick()) {ring.erase(ring.begin()+i);break;}
        bounding_box_t ringa;
        ringa.x = ring[i].position.x-ring[i].rad;
        ringa.y = ring[i].position.y-ring[i].rad;
        ringa.z = ring[i].position.z;
        ringa.height = 2*ring[i].rad;
        ringa.depth = 2.0f;
        ringa.width = 2*ring[i].rad;
        // std::cout<<ringa.x + ringa.width<<" "<<ringa.y<<" "<<ringa.z+ringa.depth<<" cx  cy cz"<<std::endl;
        // std::cout<<air.x + air.width<<" "<<air.y<<" "<<air.z+air.depth<<" ax  ay az"<<std::endl;
        if(detect_collision(ringa,air)) {ring.erase(ring.begin()+i);break;}
    }
    for(int i = 0; i < canon.size(); i++){
        if(canon[i].tick(&plane,air)){
            canon.erase(canon.begin()+i);
            break;
        }
        canon[i].shoot(&plane);
    }
    alt.tick(plane.position.y);
    compass.tick(plane.counter);
    for(int i = 0; i < arrow.size(); i++){
        arrow[0].tick(&plane);
    }
    for(int i = 0; i < checks.size(); i++){
        if(checks[i].tick(air)) {
            int ran = rand()%2;
            int mult = 1;
            int mul = 1;
            int mu = 1;
            // if(ran==0) mult = -1;
            // if(ran==1) mul = -1;
            if(ran==0) mu = -1;
            checks[i].position.z -= mult*575.0f;
            checks[i].position.y += 5.0f;
            // if(checks[i].position.y <15.0f) checks[i].position.y = 15.0f;
            checks[i].position.x += mu * 170.0f;
            for(int j = 0 ; j< canon.size() ; j++){
                canon[j].position.x = checks[i].position.x + j*140.0f;
                canon[j].position.z = checks[i].position.z;
            }
        }
    }
    for(int i = 0; i < para.size(); i++){
        if(para[i].tick()){
            para.erase(para.begin()+i);
            break;
        }
    }
    
    glfwGetCursorPos(window, &xpos, &ypos);
    float camx = plane.position.x + 70*(xpos-300.0f)/600.0f*angle1 -60*angle2;
    float camy = plane.position.y-70*(ypos-300.0f)/600.0f;
    float camz = plane.position.z- 70*(xpos-300.0f)/600.0f*angle2 -60*angle1;
    tar.tick(glm::vec3(camx,camy,camz),plane.counter);
    // terrain.tick();
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    
    
    //parts done start
    plane = Plane(0.0f,0.0f,COLOR_BLACK);
    terrain = Terrain(-5000.0f,5000.0f,10000,55000);
    arrow.push_back(Arrow(5.0f,5.0,-10.0f));
    tar = Target(0,0,0);
    display = Display(-3.0f,3.0f);
    alt = Altitude(3.5f,0.0f);
    compass = Compass(-3.0f,-3.0f);
    checks.push_back(Checks(75.0f,45.0f,-220.0f));
    canon.push_back(Canon(25.0f,-220.0f));
    canon.push_back(Canon(25.0f + 50*3.5f,-220.0f));
    //parts done complete
    
    tapu = Tapu(35.0f,-35.0f);
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");
    Matrices1.MatrixID = glGetUniformLocation(programID, "MVP");


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
            //genreate objects
            clock_t end = clock();
            int ene = (int)(end - para_timer)/CLOCKS_PER_SEC;
            if(ene >7)
            {
                for(int i = 0 ; i < 4 ; i++){
                    para.push_back(Parachute(plane.position.x - 8.0f + 4*i, plane.position.y + 50.0f, plane.position.z - 150.0f,3.0f));
                }
                para_timer = clock();
            }
            int rin = (int)(end - ring_timer)/CLOCKS_PER_SEC;
            if(rin > 4)
            {
                for(int i = 0 ; i < 8  && ring.size() < 13; i ++)
                {
                    int ra = rand()%2;
                    if(ra==0) ra = -1;
                    ring.push_back(Ring(plane.position.x + ra*120.0f , plane.position.y + i*50.0f, plane.position.z - 500.0f - i*100.0f,4.0f));
                }
            }
            //ends here the part
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
            reset_screen();

            // glfwGetCursorPos(window, &xpos, &ypos);
            // cout<<xpos<<"--"<<ypos<<endl;

        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    bool x = a.x + a.width >= b.x && b.x + b.width >= a.x?true:false;
    bool y = a.y + a.height >= b.y && b.y + b.height >= a.y?true:false;       
    bool z = a.z + a.depth <= b.z && b.z + b.depth <= a.z?true:false; 
    return (x && y && z);      
}

void reset_screen() {
    float top    = screen_center_y + 4;
    float bottom = screen_center_y - 4;
    float left   = screen_center_x - 4;
    float right  = screen_center_x + 4;
    Matrices.projection = glm::perspective(45.0f,1.0f,0.2f,1000.0f);
    // Matrices1.projection = glm::perspective(45.0f,1.0f,0.2f,10000.0f);
        Matrices1.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);

    // Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
VAO* make_c(float x, float y, float z, float r, float r1, float h, float h1,color_t color){
        int n= 40;
        int inc = 0;
        GLfloat vertex_buffer_data[18*n];
        for (int i = 0; i < 9*n; i+=9)
        {
            float angle = 2*M_PI*inc/n;
            // if(inc==n) angle = 0;
            vertex_buffer_data[i]=x+r*cos(angle);
            vertex_buffer_data[i+1]=y+h;
            vertex_buffer_data[i+2]=z+r*sin(angle);
            vertex_buffer_data[i+3]=x+r1*cos(angle);
            vertex_buffer_data[i+4]=y+h1;
            vertex_buffer_data[i+5]=z+r1*sin(angle);
            vertex_buffer_data[i+6]=x+r*cos(2*M_PI*+(inc+1)/n);
            vertex_buffer_data[i+7]=y+h;
            vertex_buffer_data[i+8]=z+r*sin(2*M_PI*+(inc+1)/n);
            inc++;
        }
        inc = 0;
        for (int i = 0; i < 9*n; i+=9)
        {
            float angle = 2*M_PI*inc/n;
            float angle2 = 2*M_PI*(inc+1)/n;
            vertex_buffer_data[9*n+i]=x+r1*cos(angle);
            vertex_buffer_data[9*n+i+1]=y+h1;
            vertex_buffer_data[9*n+i+2]=z+r1*sin(angle);
            vertex_buffer_data[9*n+i+3]=x+r*cos(angle2);
            vertex_buffer_data[9*n+i+4]=y+h;
            vertex_buffer_data[9*n+i+5]=z+r*sin(angle2);
            vertex_buffer_data[9*n+i+6]=x+r1*cos(2*M_PI*+(inc+1)/n);
            vertex_buffer_data[9*n+i+7]=y+h1;
            vertex_buffer_data[9*n+i+8]=z+r1*sin(2*M_PI*+(inc+1)/n);
            inc++;
        }
        return create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data, color, GL_FILL);
        // return create3DObject(GL_TRIANGLES_ADJACENCY, 6*n, vertex_buffer_data, color, GL_FILL);
        // return create3DObject(GL_TRIANGLE_STRIP, 6*n, vertex_buffer_data, color, GL_FILL);
        // return create3DObject(GL_TRIANGLE_LIST_SUN, 6*n, vertex_buffer_data, color, GL_FILL);
        // return create3DObject(GL_TRIANGLE_MESH_SUN, 6*n, vertex_buffer_data, color, GL_FILL);
}