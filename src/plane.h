#include "main.h"

#ifndef PLANE_H
#define PLANE_H


class Plane {
public:
    Plane() {}
    Plane(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    float pro;
    void draw(glm::mat4 VP);
    void Up(int a);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object;
    VAO *object1;
    VAO *wing;
    VAO *tail;
    VAO *tail_wing;
    VAO *propelar;
};

#endif 
