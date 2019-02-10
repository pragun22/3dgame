#include "terrain.h"
#include "main.h"
Terrain::Terrain(float x, float y, int height, int width) {
        float w = width;
        float h = height;
        float span = 5.0f;
        this->position = glm::vec3(x, -7.0f, y);
        this->rotation = 0.0f;
        this->height = height;
        this->width = width;
        this->speedz = 2.0f;
        const GLfloat vertex[]={
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
            w, 0.0f, -h             
        };
    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex, COLOR_BLACK, GL_FILL);
}
void Terrain::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 1, 1));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Terrain::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Terrain::tick() {
    this->position.z -= this->speedz;
}

