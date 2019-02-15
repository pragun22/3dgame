#include "main.h"

#ifndef ENEMIES_H
#define ENEMIES_H


class Parachute {
public:
    Parachute() {}
    Parachute(float x, float y, float z,float r);
    glm::vec3 position;
    bool flag;
    float rotation;
    float pro;
    float counter;
    float tilt;
    float speedx;
    float speedy;
    float speedz;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();

    double speed;
private:
    VAO *object;
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    std::vector<VAO*> para;
};

#endif 
