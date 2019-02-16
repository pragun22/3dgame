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
    this->object = create3DObject(GL_TRIANGLES, 19*3, vertex_buffer_data, COLOR_TAPU2, GL_FILL);
}

void Arrow::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    glm::mat4 scale = glm::scale(glm::vec3(0.9,0.6,1.2));
    Matrices.model *= (translate * rotate * scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}


void Arrow::tick() {
    // float t = this->position.z;
    th += 4.0f;
    if(th>=360.0f) th = 0.0f;
    this->position.z = this->value + 3*cos((float) (th * M_PI / 180.0f));
}

