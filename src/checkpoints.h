#include "main.h"
#include "plane.h"

#ifndef CHECKPOINTS_H
#define CHECKPOINTS_H

class Arrow {
public:
    Arrow() {}
    Arrow(float x, float y,float z);
    glm::vec3 position;
    bool flag;
    float value;
    float value2;
    float rotation;
    float alt;
    void draw(glm::mat4 VP,glm::vec3 dir);
    void tick(Plane* plane);
private:
    VAO *object;
};


class Target {
public:
    Target() {}
    Target(float x, float y,float z);
    glm::vec3 position;
    bool flag;
    float value;
    float rotation;
    float alt;
    void draw(glm::mat4 VP);
    void tick(glm::vec3 dir,float angle);
private:
    VAO *object;
    VAO *circle;
};

class Checks {
public:
    Checks() {}
    Checks(float x, float y,float z);
    glm::vec3 position;
    bool flag;
    float rotation;
    void draw(glm::mat4 VP);
    bool tick(bounding_box_t a);
private:
    VAO *object;
    VAO *circle;
};
#endif 
