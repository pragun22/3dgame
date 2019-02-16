#include "checkpoints.h"
#include "main.h"
Arrow::Arrow(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
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
            w, 0.0f, -h // side views

            -w/2.0f, span, -h,
            -w/2.0f, 0, -h,
            3.0f*w/2.0f, 0, -h,

            -w/2.0f, span, -h,
            3.0f*w/2.0f, span, -h,
            3.0f*w/2.0f, 0, -h,  //arrow head side1

            w/2.0f, span, -3.0f*h/2.0f,
            3.0f*w/2.0f, span, -h,
            3.0f*w/2.0f, 0, -h,


            w/2.0f, span, -3.0f*h/2.0f,
            w/2.0f, 0, -3.0f*h/2.0f,
            3.0f*w/2.0f, 0, -h, //arrow head side 2

            w/2.0f, span, -3.0f*h/2.0f,
            -w/2.0f, span, -h,
            -w/2.0f, 0, -h,


            w/2.0f, span, -3.0f*h/2.0f,
            w/2.0f, 0, -3.0f*h/2.0f,
            -w/2.0f, 0, -h, //arrow head side 2
            
            
             
    };
    this->object = create3DObject(GL_TRIANGLES, 18*3, vertex_buffer_data, COLOR_TAPU2, GL_FILL);
}

void Arrow::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}


void Arrow::tick() {
}

