#include "checkpoints.h"
#include "main.h"
float th = 0.0f;
Arrow::Arrow(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->value = z;
    float w  = 3.0f;
    float span = 1.0f;
    float h = 4.0f;
    static const GLfloat vertex_buffer_data[] = {
            0.0f,0.0f,0.0f,
            w, 0.0f, 0.0f,
            0.0f, span, 0.0f,

            w, 0.0f, 0.0f,
            0.0f, span, 0.0f,
            w, span, 0.0f,

            0.0f,0.0f,-h,
            w, 0.0f, -h,
            0.0f, span, -h,

            w, 0.0f, -h,
            0.0f, span, -h,
            w, span, -h, // front view

            0.0f, span, 0.0f,
            w, span, -h,
            0.0f, span, -h,

            0.0f, span, 0.0f,
            w, span, -h,
            w, span, 0.0f,
            
            0.0f, 0.0f, 0.0f,
            w, 0.0f, -h,
            0.0f, 0.0f, -h,

            0.0f, 0.0f, 0.0f,
            w, 0.0f, -h,
            w, 0.0f, 0.0f, // upper view

            0.0f, span, 0.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, span, -h,

            0.0f, 0.0f, 0.0f,
            0.0f, span, -h,
            0.0f, 0.0f, -h, 

            w, span, 0.0f,
            w, 0.0f, 0.0f,
            w, span, -h,

            w, 0.0f, 0.0f,
            w, span, -h,
            w, 0.0f, -h, // side views

            -w/2.0f, span, -h,
            -w/2.0f, 0, -h,
            3.0f*w/2.0f, 0, -h,

            -w/2.0f, span, -h,
            3.0f*w/2.0f, span, -h,
            3.0f*w/2.0f, 0, -h,  //arrow head side1

            w/2.0f, span, -4.0f*h/2.0f,
            3.0f*w/2.0f, span, -h,
            3.0f*w/2.0f, 0, -h,


            w/2.0f, span, -4.0f*h/2.0f,
            w/2.0f, 0, -4.0f*h/2.0f,
            3.0f*w/2.0f, 0, -h, //arrow head side 2

            w/2.0f, span, -4.0f*h/2.0f,
            -w/2.0f, span, -h,
            -w/2.0f, 0, -h,


            w/2.0f, span, -4.0f*h/2.0f,
            w/2.0f, 0, -4.0f*h/2.0f,
            -w/2.0f, 0, -h, //arrow head side 2

            -w/2.0f, span, -h,
            3*w/2.0f,span, -h,
            w/2.0f, span, -4.0f*h/2.0f, // top view
    };
    this->object = create3DObject(GL_TRIANGLES, 19*3, vertex_buffer_data, COLOR_FIRE, GL_FILL);
}

void Arrow::draw(glm::mat4 VP, glm::vec3 dir) {
    std::cout<<dir.x<<"  dir  "<<dir.z<<std::endl;
    // this->rotation = glm::atan(dir.x/dir.z);
    if(dir.x < 0.0f){
        if(dir.z <0.0f) {
            this->rotation = atan(abs(dir.x)/abs(dir.z));
        }
        else{
            this->rotation = M_PI/2.0f + atan(abs(dir.z)/abs(dir.x));
        }
    }
    else{
        if(dir.z <0.0f) {
            this->rotation = -1*(M_PI/2.0f-1*atan(abs(dir.z)/abs(dir.x)));
        }
        else{
            this->rotation = -1*(M_PI/2.0f + atan(abs(dir.z)/abs(dir.x)));
        }
    }
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 rotate    = glm::rotate(this->rotation, glm::vec3(0, 1, 0));
    glm::mat4 scale = glm::scale(glm::vec3(0.9,0.6,1.2));
    Matrices.model *= (translate * rotate * scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}


void Arrow::tick(Plane *plane) {
    // float t = this->position.z;
    this->value2 = plane->position.x - 1.5f;
    this->position.y = plane->position.y+4.0f;
    this->value = plane->position.z-3.0f;

    th += 4.0f;
    if(th>=360.0f) th = 0.0f;
    this->position.z = (this->value) + (3*cos((float) (th * M_PI / 180.0f)))*cos(this->rotation);
    this->position.x = (this->value2) + (3*cos((float) (th * M_PI / 180.0f)))*sin(this->rotation);
}

Target::Target(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->value = z;
    float w  = 3.0f;
    float span = 1.0f;
    float h = 4.0f;
    static const GLfloat vertex_buffer_data[] = {
        0.0f,0.0f,0.0f,
        -1.0f,1.0f,0.0f,
        1.0f,1.0f,0.0f
    };
    this->circle = make_cyl(0,0,3.0f,3.0f,0.0f,1.0f,COLOR_REAL_BLACK);
    this->object = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data, COLOR_REAL_BLACK, GL_FILL);
}

void Target::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // glm::mat4 scale = glm::scale(glm::vec3(0.9,0.6,1.2));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->circle);
}


void Target::tick(glm::vec3 dir,float a) {
    this->position = dir;    
    this->rotation = a;
}

Checks::Checks(float x, float y , float z){
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    GLfloat vertex_data[180*5];
    GLfloat color_data[180*5];
    float x_offset = 1.5f;
    int inc = 0;
    float h = 50.0f;
    for(int i = 0; i < 180*5; i+=18){
        vertex_data[i] = 0.0f+ x_offset*inc;
        vertex_data[i+1]=0.0f;
        vertex_data[i+2]=0.0f;
        
        vertex_data[i+3]=0.5f+ x_offset*inc;
        vertex_data[i+4]=0.0f;
        vertex_data[i+5]=0.0f;
        
        vertex_data[i+6]=0.0f+ x_offset*inc;
        vertex_data[i+7]=h;
        vertex_data[i+8]=0.0f;
        
        vertex_data[i+9]=0.0f+ x_offset*inc;
        vertex_data[i+10]=h;
        vertex_data[i+11]=0.0f;
        
        vertex_data[i+12]=0.5f+ x_offset*inc;
        vertex_data[i+13]=0.0f;
        vertex_data[i+14]=0.0f;
        
        vertex_data[i+15]=0.5f+ x_offset*inc;
        vertex_data[i+16]=h;
        vertex_data[i+17]=0.0f;
        inc++;
    }
    float color = 1.0f;
    for(int i = 0; i < 180*5; i+=18){
        if(color == 1.0f) color = 0.0f;
        else color = 1.0f;
        color_data[i] = color;
        color_data[i+1]=color;
        color_data[i+2]=color;
        
        color_data[i+3]=color;
        color_data[i+4]=color;
        color_data[i+5]=color;
        
        color_data[i+6]=color;
        color_data[i+7]=color;
        color_data[i+8]=color;
        
        color_data[i+9]=color;
        color_data[i+10]=color;
        color_data[i+11]=color;
        
        color_data[i+12]=color;
        color_data[i+13]=color;
        color_data[i+14]=color;
        
        color_data[i+15]=color;
        color_data[i+16]=color;
        color_data[i+17]=color;
    }

    this->object = create3DObject(GL_TRIANGLES, 60*5, vertex_data, color_data, GL_FILL);
    
}

void Checks::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // glm::mat4 scale = glm::scale(glm::vec3(0.9,0.6,1.2));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}
bool Checks::tick(bounding_box_t a){
    bounding_box_t check;
    check.x = this->position.x;
    check.y = this->position.y;
    check.z = this->position.z;
    check.height = 50.0f;
    check.width = 50*1.5f;
    check.depth = -1.0f;
    if(detect_collision(a,check)) return true;
    return false;
}