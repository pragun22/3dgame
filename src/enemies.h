#include "main.h"

#ifndef ENEMIES_H
#define ENEMIES_H


class Parachute {
public:
    Parachute() {}
    Parachute(float x, float y, float z,float r);
    glm::vec3 position;
    float rotation;
    float pro;
    float counter;
    float tilt;
    float speedx;
    float rad;
    float mov_ang;
    float speedy;
    float speedz;
    bounding_box_t attk;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bool tick();

    double speed;
private:
    VAO *person;
    VAO *ropes;
    std::vector<VAO*> para;
};
class Ring {
public:
    Ring() {}
    Ring(float x, float y, float z,float radius);
    glm::vec3 position;
    float rotation;
    clock_t timer;
    float rad;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bool tick();

    double speed;
private:
    VAO *object;
};
#endif 
